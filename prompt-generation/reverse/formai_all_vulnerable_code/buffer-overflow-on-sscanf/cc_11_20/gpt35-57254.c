//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void convertDate(const char* date) {
  // Parse input date string
  char monthStr[10], dayStr[5], yearStr[10];
  sscanf(date, "%s %s %s", monthStr, dayStr, yearStr);

  // Convert month string to integer
  int month;
  if (strcmp(monthStr, "January") == 0)      month = 1;
  else if (strcmp(monthStr, "February") == 0) month = 2;
  else if (strcmp(monthStr, "March") == 0)    month = 3;
  else if (strcmp(monthStr, "April") == 0)    month = 4;
  else if (strcmp(monthStr, "May") == 0)      month = 5;
  else if (strcmp(monthStr, "June") == 0)     month = 6;
  else if (strcmp(monthStr, "July") == 0)     month = 7;
  else if (strcmp(monthStr, "August") == 0)   month = 8;
  else if (strcmp(monthStr, "September") == 0)month = 9;
  else if (strcmp(monthStr, "October") == 0)  month = 10;
  else if (strcmp(monthStr, "November") == 0) month = 11;
  else if (strcmp(monthStr, "December") == 0) month = 12;
  else {
    printf("Invalid month '%s'\n", monthStr);
    return;
  }

  // Convert year and day strings to integers
  int year = atoi(yearStr);
  int day = atoi(dayStr);

  // Check for valid inputs
  if (month < 1 || month > 12) {
    printf("Invalid month %d\n", month);
    return;
  }
  if (day < 1 || day > 31) {
    printf("Invalid day %d\n", day);
    return;
  }
  if (year < 0) {
    printf("Invalid year %d\n", year);
    return;
  }

  // Determine if leap year
  int leapYear = 0;
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    leapYear = 1;
  }

  // Check for valid day in month
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
    printf("Invalid day %d for %s %d\n", day, monthStr, year);
  } else if (month == 2) {
    if (leapYear && day > 29) {
      printf("Invalid day %d for %s %d (leap year)\n", day, monthStr, year);
    } else if (!leapYear && day > 28) {
      printf("Invalid day %d for %s %d (not a leap year)\n", day, monthStr, year);
    }
  }

  // Print output date string
  printf("The input date '%s' in natural language format is equivalent to %d/%02d/%04d\n", date, month, day, year);
}

int main() {
  // Read input date string
  char input[MAX_INPUT_LENGTH];
  printf("Enter a date in natural language format (e.g. 'January 1 2022'): ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Trim newline character from input
  if (strlen(input) > 0 && input[strlen(input)-1] == '\n') {
    input[strlen(input)-1] = '\0';
  }

  // Convert date and print result
  convertDate(input);

  return 0;
}