//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include <stdio.h>

// function declarations
int isLeapYear(int);
int calculateDays(int, int, int);
void convertDate(char *);

int main() {
  char date[11];

  // accept date in mm/dd/yyyy format
  printf("Enter date in mm/dd/yyyy format: ");
  scanf("%s", date);

  // calling date converter function
  convertDate(date);

  return 0;
}

// function to check if entered year is a leap year or not
int isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return 1;
  }
  return 0;
}

// function to calculate number of days from 1st January
int calculateDays(int month, int day, int year) {
  int days = 0, i;

  for (i = 1; i < month; i++) {
    switch (i) {
      case 2:
        days += isLeapYear(year) ? 29 : 28;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        days += 30;
        break;
      default:
        days += 31;
        break;
    }
  }

  days += day;

  return days;
}

// function to convert date from mm/dd/yyyy to format: MMMM dd, yyyy
void convertDate(char *date) {
  int month, day, year, days;
  char monthName[10];

  sscanf(date, "%d/%d/%d", &month, &day, &year);

  days = calculateDays(month, day, year);

  switch (month) {
    case 1:
      sprintf(monthName, "January");
      break;
    case 2:
      sprintf(monthName, "February");
      break;
    case 3:
      sprintf(monthName, "March");
      break;
    case 4:
      sprintf(monthName, "April");
      break;
    case 5:
      sprintf(monthName, "May");
      break;
    case 6:
      sprintf(monthName, "June");
      break;
    case 7:
      sprintf(monthName, "July");
      break;
    case 8:
      sprintf(monthName, "August");
      break;
    case 9:
      sprintf(monthName, "September");
      break;
    case 10:
      sprintf(monthName, "October");
      break;
    case 11:
      sprintf(monthName, "November");
      break;
    case 12:
      sprintf(monthName, "December");
      break;
  }

  printf("Converted date: %s %d, %d", monthName, (days - calculateDays(1, 0, year)), year);
}