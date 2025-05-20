//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_DATE_LENGTH 11
#define MAX_MONTH_LENGTH 12
#define MAX_YEAR_LENGTH 5

// Function prototypes
int validate_date(char *date);
int convert_date(char *date, int *day, int *month, int *year);
void print_date(int day, int month, int year);

// Main function
int main() {
  // Declare variables
  char date[MAX_DATE_LENGTH];
  int day, month, year;

  // Prompt the user to enter a date
  printf("Enter a date in the format dd/mm/yyyy: ");
  scanf("%s", date);

  // Validate the date
  if (!validate_date(date)) {
    printf("Invalid date.\n");
    return EXIT_FAILURE;
  }

  // Convert the date to day, month, and year
  if (!convert_date(date, &day, &month, &year)) {
    printf("Error converting date.\n");
    return EXIT_FAILURE;
  }

  // Print the date
  print_date(day, month, year);

  return EXIT_SUCCESS;
}

// Function to validate a date
int validate_date(char *date) {
  // Check the length of the date
  if (strlen(date) != MAX_DATE_LENGTH) {
    return 0;
  }

  // Check the format of the date
  if (date[2] != '/' || date[5] != '/') {
    return 0;
  }

  // Check the day
  int day = atoi(date);
  if (day < 1 || day > 31) {
    return 0;
  }

  // Check the month
  int month = atoi(date + 3);
  if (month < 1 || month > 12) {
    return 0;
  }

  // Check the year
  int year = atoi(date + 6);
  if (year < 1900 || year > 9999) {
    return 0;
  }

  // The date is valid
  return 1;
}

// Function to convert a date to day, month, and year
int convert_date(char *date, int *day, int *month, int *year) {
  // Extract the day, month, and year from the date
  *day = atoi(date);
  *month = atoi(date + 3);
  *year = atoi(date + 6);

  return 1;
}

// Function to print a date
void print_date(int day, int month, int year) {
  // Print the day, month, and year
  printf("The date is: %d/%d/%d\n", day, month, year);
}