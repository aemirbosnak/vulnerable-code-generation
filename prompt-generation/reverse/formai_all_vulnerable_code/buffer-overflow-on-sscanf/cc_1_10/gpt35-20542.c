//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a structure to hold the date information
typedef struct {
  int year;
  int month;
  int day;
} Date;

// Declare an array of month names
char *month_names[12] = {
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
  "December"
};

// Declare function to get the number of days in a month
int days_in_month(int month, int year) {
  int days;
  switch(month) {
    case 2:
      // Check if it's a leap year
      if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days = 29;
      } else {
        days = 28;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      days = 30;
      break;
    default:
      days = 31;
      break;
  }
  return days;
}

// Declare function to convert a date string to Date structure
Date convert_date_string(char *date_string) {
  Date date;
  char *token;
  
  // Get year
  token = strtok(date_string, "-");
  sscanf(token, "%d", &date.year);

  // Get month
  token = strtok(NULL, "-");
  sscanf(token, "%d", &date.month);

  // Get day
  token = strtok(NULL, "-");
  sscanf(token, "%d", &date.day);

  return date;
}

// Declare function to convert a Date structure to a string
char *convert_date_to_string(Date date) {
  char *date_string = (char *) malloc(11);
  sprintf(date_string, "%04d-%02d-%02d", date.year, date.month, date.day);
  return date_string;
}

// Declare the main function
int main() {
  // Ask user for date input in YYYY-MM-DD format
  printf("Enter a date in YYYY-MM-DD format: ");

  // Declare a character array to hold the date string
  char date_string[11];
  scanf("%s", date_string);

  // Convert the date string to a Date structure
  Date date = convert_date_string(date_string);

  // Get the month name
  char *month_name = month_names[date.month - 1];

  // Get the number of days in the month
  int days = days_in_month(date.month, date.year);

  // Increment the day by 1
  date.day++;

  // Check if the day is greater than the number of days in the month
  if(date.day > days) {
    date.day = 1;
    date.month++;
  }

  // Check if the month is greater than 12
  if(date.month > 12) {
    date.month = 1;
    date.year++;
  }

  // Convert the updated date to a string and print it out
  char *updated_date_string = convert_date_to_string(date);
  printf("The updated date is: %s\n", updated_date_string);

  // Free the memory allocated for the date strings
  free(updated_date_string);

  // Return with success code
  return 0;
}