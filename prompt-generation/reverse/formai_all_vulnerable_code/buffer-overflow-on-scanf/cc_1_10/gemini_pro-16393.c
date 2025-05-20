//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 10
#define DAYS_IN_MONTH 31
#define MONTHS_IN_YEAR 12

// Function to convert a string to an integer
int strToInt(char *str) {
  int num = 0;
  for (int i = 0; i < strlen(str); i++) {
    num = num * 10 + (str[i] - '0');
  }
  return num;
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
  if (year % 400 == 0) {
    return 1;
  } else if (year % 100 == 0) {
    return 0;
  } else if (year % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}

// Function to convert a date string to a Julian day number
int dateToJulian(char *date) {
  // Extract the year, month, and day from the date string
  char yearStr[5];
  char monthStr[3];
  char dayStr[3];
  strncpy(yearStr, date, 4);
  strncpy(monthStr, date + 5, 2);
  strncpy(dayStr, date + 8, 2);

  // Convert the year, month, and day to integers
  int year = strToInt(yearStr);
  int month = strToInt(monthStr);
  int day = strToInt(dayStr);

  // Calculate the Julian day number
  int julianDay = 0;
  for (int i = 1; i < month; i++) {
    if (i == 2) {
      julianDay += 28 + isLeapYear(year);
    } else if (i % 2 == 0) {
      julianDay += 30;
    } else {
      julianDay += 31;
    }
  }
  julianDay += day;
  julianDay += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

  return julianDay;
}

// Function to convert a Julian day number to a date string
char *julianToDate(int julianDay) {
  // Calculate the year, month, and day from the Julian day number
  int year = 1;
  int month = 1;
  int day = 1;
  while (julianDay > DAYS_IN_MONTH) {
    if (month % 2 == 0) {
      julianDay -= 30;
    } else if (month == 2) {
      julianDay -= 28 + isLeapYear(year);
    } else {
      julianDay -= 31;
    }
    month++;
  }
  day = julianDay;

  // Convert the year, month, and day to a string
  char *date = malloc(MAX_DATE_LEN);
  sprintf(date, "%04d-%02d-%02d", year, month, day);

  return date;
}

int main() {
  // Get the date string from the user
  char date[MAX_DATE_LEN];
  printf("Enter a date (YYYY-MM-DD): ");
  scanf("%s", date);

  // Convert the date string to a Julian day number
  int julianDay = dateToJulian(date);

  // Print the Julian day number
  printf("Julian day number: %d\n", julianDay);

  // Convert the Julian day number to a date string
  char *newDate = julianToDate(julianDay);

  // Print the new date string
  printf("New date: %s\n", newDate);

  return 0;
}