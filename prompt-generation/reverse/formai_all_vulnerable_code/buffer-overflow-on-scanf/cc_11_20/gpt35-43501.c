//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Declare variables to store input date
  char input_date[20];
  int day, month, year;

  // Get input date from user
  printf("Enter a date in the format dd/mm/yyyy: ");
  scanf("%s", input_date);

  // Convert input date to integers
  char *token = strtok(input_date, "/");
  day = atoi(token);
  token = strtok(NULL, "/");
  month = atoi(token);
  token = strtok(NULL, "/");
  year = atoi(token);

  // Check if input date is valid
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1 || year > 9999)
  {
    printf("Invalid date.\n");
    return 0;
  }

  // Declare variables for converted date
  char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  char *suffix;
  int century = (year - 1) / 100 + 1;
  int year_in_century = year % 100;
  char converted_date[50];

  // Convert month to string and add suffix to day
  if (day == 1 || day == 21 || day == 31)
    suffix = "st";
  else if (day == 2 || day == 22)
    suffix = "nd";
  else if (day == 3 || day == 23)
    suffix = "rd";
  else
    suffix = "th";

  // Build converted date string
  sprintf(converted_date, "%d%s %s %d (Century %d, Year %d)", day, suffix, months[month - 1], year, century, year_in_century);

  // Print converted date
  printf("Converted date: %s\n", converted_date);

  return 0;
}