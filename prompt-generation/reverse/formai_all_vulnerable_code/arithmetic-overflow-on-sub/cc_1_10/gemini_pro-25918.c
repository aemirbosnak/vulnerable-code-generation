//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the names of the months
char *months[] = {"January", "February", "March", "April", "May", "June",
                   "July", "August", "September", "October", "November", "December"};

// Define the names of the weekdays
char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Get the day of the week for a given date
int getDayOfWeek(int day, int month, int year) {
  int y0 = year - (14 - month) / 12;
  int x = y0 + y0 / 4 - y0 / 100 + y0 / 400;
  int m0 = month + 12 * ((14 - month) / 12) - 2;
  int d0 = (day + x + (31 * m0) / 12) % 7;
  return d0;
}

// Print the calendar for a given month and year
void printCalendar(int month, int year) {
  // Get the day of the week for the first day of the month
  int dayOfWeek = getDayOfWeek(1, month, year);

  // Print the header for the calendar
  printf("\n\n   %s %d\n", months[month - 1], year);
  printf("---------------------------\n");
  printf(" Sun Mon Tue Wed Thu Fri Sat\n");

  // Print the days of the month
  for (int i = 0; i < dayOfWeek; i++) {
    printf("    ");
  }
  for (int i = 1; i <= daysInMonth[month - 1]; i++) {
    printf("%4d", i);
    if ((i + dayOfWeek) % 7 == 0) {
      printf("\n");
    }
  }
  printf("\n\n");
}

// Get the date from the user
void getDate(int *day, int *month, int *year) {
  printf("Enter the day (1-31): ");
  scanf("%d", day);
  printf("Enter the month (1-12): ");
  scanf("%d", month);
  printf("Enter the year (YYYY): ");
  scanf("%d", year);
}

// Main function
int main() {
  int day, month, year;

  // Get the date from the user
  getDate(&day, &month, &year);

  // Print the calendar for the given month and year
  printCalendar(month, year);

  return 0;
}