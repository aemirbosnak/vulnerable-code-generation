//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the function to convert a date from string to struct tm
struct tm *stringToDate(char *dateString);

// Declare the function to convert a struct tm to a string
char *dateToString(struct tm *date);

int main() {
  // Get the current date and time
  time_t now = time(NULL);
  struct tm *nowTm = localtime(&now);

  // Convert the current date and time to a string
  char *nowString = dateToString(nowTm);

  // Print the current date and time
  printf("Current date and time: %s\n", nowString);

  // Get a date string from the user
  char dateString[256];
  printf("Enter a date in the format YYYY-MM-DD: ");
  scanf("%s", dateString);

  // Convert the date string to a struct tm
  struct tm *dateTm = stringToDate(dateString);

  // Convert the struct tm to a string
  char *dateString2 = dateToString(dateTm);

  // Print the converted date
  printf("Converted date: %s\n", dateString2);

  return 0;
}

// Function to convert a date from string to struct tm
struct tm *stringToDate(char *dateString) {
  struct tm dateTm;

  // Parse the date string
  sscanf(dateString, "%d-%d-%d", &dateTm.tm_year, &dateTm.tm_mon, &dateTm.tm_mday);

  // Adjust the tm_year and tm_mon values
  dateTm.tm_year -= 1900;
  dateTm.tm_mon--;

  return &dateTm;
}

// Function to convert a struct tm to a string
char *dateToString(struct tm *dateTm) {
  static char dateString[256];

  // Format the date string
  strftime(dateString, sizeof(dateString), "%Y-%m-%d", dateTm);

  return dateString;
}