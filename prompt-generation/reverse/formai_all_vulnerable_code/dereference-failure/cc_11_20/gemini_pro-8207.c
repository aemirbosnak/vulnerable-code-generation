//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Date converter from Gregorian to Julian and vice versa
// Julian calendar was used until 1582, when it was replaced by the Gregorian calendar.
// The Gregorian calendar is the one that is currently used.

// The Julian calendar is a solar calendar with a year of 365.25 days.
// The Gregorian calendar is a solar calendar with a year of 365.2425 days.

// The difference between the two calendars is that the Gregorian calendar has a leap year every 4 years, except for years that are divisible by 100 but not by 400.

// This program can convert a date from the Gregorian calendar to the Julian calendar, or vice versa.

// The program takes two command line arguments:
// - The first argument is the date in the format "YYYY-MM-DD".
// - The second argument is the type of conversion. It can be "gtoj" or "jtog".

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <date> <type>\n", argv[0]);
    printf("Type can be \"gtoj\" or \"jtog\".\n");
    return 1;
  }

  char *date = argv[1];
  char *type = argv[2];

  int year, month, day;
  sscanf(date, "%d-%d-%d", &year, &month, &day);

  if (strcmp(type, "gtoj") == 0) {
    // Convert Gregorian to Julian.

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      // The year is a leap year.
      day++;
    }

    if (month == 2 && day == 29) {
      // The date is February 29th.
      day = 1;
      month = 3;
    }
  } else if (strcmp(type, "jtog") == 0) {
    // Convert Julian to Gregorian.

    if (year % 4 == 0 && year % 100 != 0) {
      // The year is a leap year.
      day--;
    }

    if (month == 2 && day == 1) {
      // The date is February 1st.
      day = 29;
      month = 1;
    }
  } else {
    printf("Invalid type.\n");
    return 1;
  }

  printf("%d-%d-%d\n", year, month, day);

  return 0;
}