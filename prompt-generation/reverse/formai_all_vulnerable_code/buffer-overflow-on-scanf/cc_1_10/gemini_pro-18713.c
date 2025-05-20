//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the months of the year
char *months[] = {"January", "February", "March", "April", "May", "June",
                   "July", "August", "September", "October", "November", "December"};

// Define the days of the week
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to convert a date from the format "dd/mm/yyyy" to the format "yyyy-mm-dd"
char *convertDate(char *date) {
  // Allocate memory for the new date string
  char *newDate = malloc(11);

  // Get the year from the date string
  char *year = strtok(date, "/");

  // Get the month from the date string
  char *month = strtok(NULL, "/");

  // Get the day from the date string
  char *day = strtok(NULL, "/");

  // Convert the month to a number
  int monthNumber;
  for (monthNumber = 0; monthNumber < 12; monthNumber++) {
    if (strcmp(month, months[monthNumber]) == 0) {
      break;
    }
  }

  // Convert the day to a number
  int dayNumber = atoi(day);

  // Convert the year to a number
  int yearNumber = atoi(year);

  // Check if the year is valid
  if (yearNumber < 1900 || yearNumber > 2099) {
    printf("Invalid year: %s\n", year);
    return NULL;
  }

  // Check if the month is valid
  if (monthNumber < 0 || monthNumber > 11) {
    printf("Invalid month: %s\n", month);
    return NULL;
  }

  // Check if the day is valid
  if (dayNumber < 1 || dayNumber > daysInMonth[monthNumber]) {
    printf("Invalid day: %s\n", day);
    return NULL;
  }

  // Convert the date to the new format
  sprintf(newDate, "%d-%02d-%02d", yearNumber, monthNumber + 1, dayNumber);

  // Return the new date string
  return newDate;
}

int main() {
  // Get the date from the user
  char date[11];
  printf("Enter a date in the format dd/mm/yyyy: ");
  scanf("%s", date);

  // Convert the date to the new format
  char *newDate = convertDate(date);

  // Print the new date
  printf("The date in the format yyyy-mm-dd is: %s\n", newDate);

  // Free the memory allocated for the new date string
  free(newDate);

  return 0;
}