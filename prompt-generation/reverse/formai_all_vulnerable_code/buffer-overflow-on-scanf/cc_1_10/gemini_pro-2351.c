//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the month names
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Define the day names
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the leap year rule
int isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Convert a date from the format "dd/mm/yyyy" to the format "yyyy-mm-dd"
char *convertDate(char *date) {
  // Allocate memory for the new date string
  char *newDate = malloc(11);

  // Extract the year, month, and day from the old date string
  int year = atoi(date + 6);
  int month = atoi(date + 3) - 1;
  int day = atoi(date);

  // Check if the year is valid
  if (year < 1900 || year > 2099) {
    fprintf(stderr, "Error: Invalid year %d\n", year);
    exit(EXIT_FAILURE);
  }

  // Check if the month is valid
  if (month < 0 || month > 11) {
    fprintf(stderr, "Error: Invalid month %d\n", month);
    exit(EXIT_FAILURE);
  }

  // Check if the day is valid
  if (day < 1 || day > daysInMonth[month] + (isLeapYear(year) && month == 1)) {
    fprintf(stderr, "Error: Invalid day %d\n", day);
    exit(EXIT_FAILURE);
  }

  // Format the new date string
  sprintf(newDate, "%04d-%02d-%02d", year, month + 1, day);

  // Return the new date string
  return newDate;
}

// Main function
int main(void) {
  // Get the date from the user
  char date[11];
  printf("Enter a date in the format \"dd/mm/yyyy\": ");
  scanf("%s", date);

  // Convert the date
  char *newDate = convertDate(date);

  // Print the new date
  printf("The date in the format \"yyyy-mm-dd\" is: %s\n", newDate);

  // Free the memory allocated for the new date string
  free(newDate);

  return 0;
}