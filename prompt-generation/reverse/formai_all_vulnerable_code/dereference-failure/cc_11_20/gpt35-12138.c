//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char input_date[20];
  int month, day, year;

  // Get date input from user
  printf("Enter a date in natural language (e.g. January 1st, 2022): ");
  fgets(input_date, 20, stdin);

  // Remove new line character from user input
  input_date[strcspn(input_date, "\n")] = 0;

  // Convert month from string to integer
  if (strstr(input_date, "January")) {
    month = 1;
  } else if (strstr(input_date, "February")) {
    month = 2;
  } else if (strstr(input_date, "March")) {
    month = 3;
  } else if (strstr(input_date, "April")) {
    month = 4;
  } else if (strstr(input_date, "May")) {
    month = 5;
  } else if (strstr(input_date, "June")) {
    month = 6;
  } else if (strstr(input_date, "July")) {
    month = 7;
  } else if (strstr(input_date, "August")) {
    month = 8;
  } else if (strstr(input_date, "September")) {
    month = 9;
  } else if (strstr(input_date, "October")) {
    month = 10;
  } else if (strstr(input_date, "November")) {
    month = 11;
  } else if (strstr(input_date, "December")) {
    month = 12;
  } else {
    printf("Error: Invalid month\n");
    return 1;
  }

  // Convert day from string to integer
  char *day_string = strtok(input_date, " ");
  day_string = strtok(NULL, " ");
  day = atoi(day_string);

  // Convert year from string to integer
  char *year_string = strtok(NULL, " ");
  year = atoi(year_string);

  // Output converted date
  printf("The date is: %02d/%02d/%04d\n", month, day, year);

  return 0;
}