//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the number of days in each month
int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Converts a string representing a date in the MM/DD/YYYY format to a Julian day number
int dateToJulian(char *date) {
  // Extract the month, day, and year from the date string
  int month = atoi(strtok(date, "/"));
  int day = atoi(strtok(NULL, "/"));
  int year = atoi(strtok(NULL, "/"));

  // Calculate the Julian day number
  int julianDay = 0;
  for (int i = 1; i < month; i++) {
    julianDay += daysInMonth[i];
  }
  julianDay += day;
  julianDay += (year - 1) * 365;
  julianDay += (year - 1) / 4;
  julianDay -= (year - 1) / 100;
  julianDay += (year - 1) / 400;
  return julianDay;
}

// Converts a Julian day number to a string representing the date in the MM/DD/YYYY format
char *julianToDate(int julianDay) {
  // Calculate the year, month, and day
  int year = (julianDay - 1) / 365 + 1;
  int month = 1;
  int day = 1;
  while (julianDay > daysInMonth[month] + (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
    julianDay -= daysInMonth[month];
    month++;
  }
  day = julianDay;

  // Create the date string
  char *date = malloc(11);
  sprintf(date, "%02d/%02d/%04d", month, day, year);
  return date;
}

int main() {
  // Get the input date
  char date[11];
  printf("Enter a date in the MM/DD/YYYY format: ");
  scanf("%s", date);

  // Convert the date to a Julian day number
  int julianDay = dateToJulian(date);

  // Print the Julian day number
  printf("Julian day number: %d\n", julianDay);

  // Convert the Julian day number back to a date
  char *newDate = julianToDate(julianDay);

  // Print the new date
  printf("New date: %s\n", newDate);

  return 0;
}