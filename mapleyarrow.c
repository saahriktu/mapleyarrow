/*
 * Maple-yarrow 0.1 - program that output human readable form of day by year and day index
 * 2013 (c) Kurashov A.K. (mail@saahriktu.org)
 */
#include <stdio.h>

char *month_names [] = {
"January",
"February",
"March",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December" };

int main(int argc, char **argv){
 int year, day_index, month, day_sum = 0, month_shift = 0, days_in_month, long_year = 0;
 if(argc < 3){
  printf("Too few arguments.\nUsage: mapleyarrow year day_index\n");
  return 1;
 }
 year = atoi(argv[1]);
 day_index = atoi(argv[2]);
 if(year%4 == 0)long_year = 1;
 for(month = 0; month < 12; month++){
  if(month == 7)month_shift = 1;
  if(month != 1)days_in_month = 31 - (month+month_shift)%2;
  else days_in_month = 28 + long_year;
  day_sum += days_in_month;
  if(day_index <= day_sum){
   printf("Day is %d of %s.\n", day_index - day_sum + days_in_month, month_names[month]);
   return 0;
  }
 }
 printf("Day out of %d days of year.\n", day_sum);
 return 1;
}
