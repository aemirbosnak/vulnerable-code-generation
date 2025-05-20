//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>

int main() {
  int day, month, year, days_in_month, temp;
  printf("Enter a date in the format DD-MM-YYYY: ");
  scanf("%d-%d-%d", &day, &month, &year);

  // Check if year is a leap year
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    // Leap year
    int days_in_month_arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    days_in_month = days_in_month_arr[month - 1];
  } else {
    // Not a leap year
    int days_in_month_arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    days_in_month = days_in_month_arr[month - 1];
  }
  
  // Check for valid date
  if (day < 1 || day > days_in_month || month < 1 || month > 12 || year < 1) {
    printf("Invalid Date\n");
  } else {
    // Print the date in natural language format
    printf("Date: ");
    switch (month) {
      case 1:
        printf("January");
        break;
      case 2:
        printf("February");
        break;
      case 3:
        printf("March");
        break;
      case 4:
        printf("April");
        break;
      case 5:
        printf("May");
        break;
      case 6:
        printf("June");
        break;
      case 7:
        printf("July");
        break;
      case 8:
        printf("August");
        break;
      case 9:
        printf("September");
        break;
      case 10:
        printf("October");
        break;
      case 11:
        printf("November");
        break;
      case 12:
        printf("December");
        break;
    }
    printf(" %d, %d\n", day, year);

    // Print the day of the week
    printf("Day of the week: ");
    int y = year - (14 - month) / 12;
    int x = y + y/4 - y/100 + y/400;
    int m = month + 12 * ((14 - month) / 12) - 2;
    int day_of_week = (day + x + (31*m)/12) % 7;

    switch (day_of_week) {
      case 0:
        printf("Sunday");
        break;
      case 1:
        printf("Monday");
        break;
      case 2:
        printf("Tuesday");
        break;
      case 3:
        printf("Wednesday");
        break;
      case 4:
        printf("Thursday");
        break;
      case 5:
        printf("Friday");
        break;
      case 6:
        printf("Saturday");
        break;
    }
    printf("\n");
  }
  return 0;
}