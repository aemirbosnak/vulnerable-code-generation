//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Wow! This program converts dates between different formats!

  // Let's define some constants:
  const int DAYS_IN_WEEK = 7;
  const int DAYS_IN_MONTH = 30;  // This is just an approximation, but it's good enough for our purposes!
  const int DAYS_IN_YEAR = 365;  // Again, this is just an approximation, but it's close enough!

  // Now, let's get some input from the user:
  int day, month, year;
  printf("Enter the day, month, and year (in that order, separated by spaces): ");
  scanf("%d %d %d", &day, &month, &year);

  // Let's check if the input is valid:
  if (day < 1 || day > DAYS_IN_MONTH || month < 1 || month > 12 || year < 1) {
    printf("Invalid input! Please try again.\n");
    return 1;  // Return an error code to indicate that the input was invalid.
  }

  // Okay, the input is valid. Now, let's convert the date to the Julian Day Number (JDN):
  int jdn = year * DAYS_IN_YEAR + month * DAYS_IN_MONTH + day;

  // Now, let's ask the user what format they want the date to be converted to:
  int choice;
  printf("What format do you want to convert the date to?\n");
  printf("1. MM/DD/YYYY\n");
  printf("2. YYYY-MM-DD\n");
  printf("3. JDN\n");
  scanf("%d", &choice);

  // Now, let's convert the date to the desired format:
  char date[11];  // This is big enough to hold any of the date formats we're using.
  switch (choice) {
    case 1:
      sprintf(date, "%02d/%02d/%04d", month, day, year);
      break;
    case 2:
      sprintf(date, "%04d-%02d-%02d", year, month, day);
      break;
    case 3:
      sprintf(date, "%d", jdn);
      break;
    default:
      printf("Invalid choice! Please try again.\n");
      return 1;  // Return an error code to indicate that the choice was invalid.
  }

  // Finally, let's print out the converted date:
  printf("The converted date is: %s\n", date);

  return 0;  // Return 0 to indicate that the program ran successfully.
}