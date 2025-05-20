//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>

// Function to check if a year is a leap year or not
int isLeapYear(int year) {
  return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

// Function to get the number of days in a given month
int getDaysInMonth(int month, int year) {
  if (month == 2) {
    return isLeapYear(year) ? 29 : 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else {
    return 31;
  }
}

// Function to convert a date from natural language to standard format (YYYY-MM-DD)
void convertDate(char date[]) {
  int day, month, year;
  char monthStr[10];

  // Parse the natural language date
  sscanf(date, "%d %s %d", &day, monthStr, &year);

  // Convert the month string to a number
  if (strcmp(monthStr, "January") == 0) {
    month = 1;
  } else if (strcmp(monthStr, "February") == 0) {
    month = 2;
  } else if (strcmp(monthStr, "March") == 0) {
    month = 3;
  } else if (strcmp(monthStr, "April") == 0) {
    month = 4;
  } else if (strcmp(monthStr, "May") == 0) {
    month = 5;
  } else if (strcmp(monthStr, "June") == 0) {
    month = 6;
  } else if (strcmp(monthStr, "July") == 0) {
    month = 7;
  } else if (strcmp(monthStr, "August") == 0) {
    month = 8;
  } else if (strcmp(monthStr, "September") == 0) {
    month = 9;
  } else if (strcmp(monthStr, "October") == 0) {
    month = 10;
  } else if (strcmp(monthStr, "November") == 0) {
    month = 11;
  } else if (strcmp(monthStr, "December") == 0) {
    month = 12;
  } else {
    printf("Error: Invalid month\n");
    return;
  }

  // Check that the day is valid
  if (day < 1 || day > getDaysInMonth(month, year)) {
    printf("Error: Invalid day\n");
    return;
  }

  // Print the converted date
  printf("%04d-%02d-%02d\n", year, month, day);
}

int main() {
  char date[20];
  printf("Enter a date in natural language (e.g. 1 January 2022): ");
  fgets(date, 20, stdin);

  // Remove any newline characters from the input string
  if (date[strlen(date) - 1] == '\n') {
    date[strlen(date) - 1] = '\0';
  }

  convertDate(date);

  return 0;
}