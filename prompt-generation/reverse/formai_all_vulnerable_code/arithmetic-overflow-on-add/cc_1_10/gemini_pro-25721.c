//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the months of the year
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Define the days of the week
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the leap year rule
int isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Define the function to convert a date from the Gregorian calendar to the Julian calendar
void gregorianToJulian(int year, int month, int day) {
  if (year < 1582 || (year == 1582 && month < 10) || (year == 1582 && month == 10 && day < 15)) {
    printf("The date %d-%d-%d is not valid in the Julian calendar.\n", year, month, day);
    return;
  }

  // Convert the date to the Julian calendar
  int julianYear = year - 10;
  int julianMonth = month;
  int julianDay = day;

  // Adjust the date for the leap year rule
  if (isLeapYear(year)) {
    if (month > 2) {
      julianDay++;
    }
  }

  // Print the date in the Julian calendar
  printf("The date %d-%d-%d in the Gregorian calendar is %d-%d-%d in the Julian calendar.\n", year, month, day, julianYear, julianMonth, julianDay);
}

// Define the function to convert a date from the Julian calendar to the Gregorian calendar
void julianToGregorian(int year, int month, int day) {
  if (year < 1582 || (year == 1582 && month < 10) || (year == 1582 && month == 10 && day < 15)) {
    printf("The date %d-%d-%d is not valid in the Gregorian calendar.\n", year, month, day);
    return;
  }

  // Convert the date to the Gregorian calendar
  int gregorianYear = year + 10;
  int gregorianMonth = month;
  int gregorianDay = day;

  // Adjust the date for the leap year rule
  if (isLeapYear(gregorianYear)) {
    if (gregorianMonth > 2) {
      gregorianDay--;
    }
  }

  // Print the date in the Gregorian calendar
  printf("The date %d-%d-%d in the Julian calendar is %d-%d-%d in the Gregorian calendar.\n", year, month, day, gregorianYear, gregorianMonth, gregorianDay);
}

// Define the main function
int main() {
  // Get the date from the user
  int year, month, day;
  printf("Enter the year: ");
  scanf("%d", &year);
  printf("Enter the month: ");
  scanf("%d", &month);
  printf("Enter the day: ");
  scanf("%d", &day);

  // Convert the date from the Gregorian calendar to the Julian calendar
  gregorianToJulian(year, month, day);

  // Convert the date from the Julian calendar to the Gregorian calendar
  julianToGregorian(year, month, day);

  return 0;
}