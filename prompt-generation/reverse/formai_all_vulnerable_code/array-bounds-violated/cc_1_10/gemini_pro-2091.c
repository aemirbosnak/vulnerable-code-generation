//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
/* Time Traveler 2000 - C Natural Language Date Converter */

#include <stdio.h>
#include <stdlib.h>

/* Months */
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/* Days */
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

/* Suffixes */
char *suffixes[] = {"st", "nd", "rd", "th"};

/* Prototypes */
int get_day_of_week(int year, int month, int day);
char *get_month_name(int month);
char *get_day_name(int day);
char *get_suffix(int day);

/* Main Function */
int main()
{
   int year, month, day;
   int day_of_week;
   char *month_name;
   char *day_name;
   char *suffix;

   /* Get the date from the user. */
   printf("Enter the year: ");
   scanf("%d", &year);
   printf("Enter the month: ");
   scanf("%d", &month);
   printf("Enter the day: ");
   scanf("%d", &day);

   /* Get the day of the week. */
   day_of_week = get_day_of_week(year, month, day);

   /* Get the month name. */
   month_name = get_month_name(month);

   /* Get the day name. */
   day_name = get_day_name(day_of_week);

   /* Get the suffix. */
   suffix = get_suffix(day);

   /* Print the date. */
   printf("The date is %s, %s %d%s %d.\n", day_name, month_name, day, suffix, year);

   return 0;
}

/* Get the day of the week. */
int get_day_of_week(int year, int month, int day)
{
   int c, y;

   if (month < 3)
   {
      month += 12;
      year--;
   }

   c = year / 100;
   y = year % 100;

   return (day + (26 * month - 2) / 10 + y + y / 4 + c / 4 - 2 * c + 777) % 7;
}

/* Get the month name. */
char *get_month_name(int month)
{
   return months[month - 1];
}

/* Get the day name. */
char *get_day_name(int day)
{
   return days[day];
}

/* Get the suffix. */
char *get_suffix(int day)
{
   if (day % 10 == 1 && day != 11)
   {
      return suffixes[0];
   }
   else if (day % 10 == 2 && day != 12)
   {
      return suffixes[1];
   }
   else if (day % 10 == 3 && day != 13)
   {
      return suffixes[2];
   }
   else
   {
      return suffixes[3];
   }
}