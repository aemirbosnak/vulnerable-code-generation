//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the months of the year
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Define the days of the week
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the leap year rule
int isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Convert a date from the Gregorian calendar to the Julian calendar
void gregorianToJulian(int year, int month, int day, int *julianYear, int *julianMonth, int *julianDay) {
  int a = (14 - month) / 12;
  int y = year + 4800 - a;
  int m = month + 12 * a - 3;
  *julianYear = y + (m + 2) / 12;
  *julianMonth = (m + 2) % 12 + 1;
  *julianDay = day + (153 * m + 8) / 5 + y * 365 + y / 4 - y / 100 + y / 400 - 32045;
}

// Convert a date from the Julian calendar to the Gregorian calendar
void julianToGregorian(int year, int month, int day, int *gregorianYear, int *gregorianMonth, int *gregorianDay) {
  int a = (year + 32044) / 36525;
  int b = (year + 32045) % 36525;
  int c = (b + 3) / 8;
  int d = (8 * c + 5) / 2;
  int e = d % 4;
  int f = (38 * e + 31) % 29;
  int g = (b - d * 365 - f) / 30;
  int h = (30 * g + f) % 30;
  int i = h % 12;
  int j = h / 12;
  *gregorianYear = year + a - j;
  *gregorianMonth = i + 1;
  *gregorianDay = b - d * 365 - f - g * 30 - j * 365 - j / 4 + j / 100 - j / 400;
}

// Print a date in the Gregorian calendar
void printGregorianDate(int year, int month, int day) {
  printf("%s %d, %d\n", months[month - 1], day, year);
}

// Print a date in the Julian calendar
void printJulianDate(int year, int month, int day) {
  printf("%s %d, %d (Julian)\n", months[month - 1], day, year);
}

// Get a date from the user
void getDate(int *year, int *month, int *day) {
  printf("Enter a date in the Gregorian calendar (YYYY-MM-DD): ");
  scanf("%d-%d-%d", year, month, day);
}

// Convert a date from the Gregorian calendar to the Julian calendar and print the result
void convertGregorianToJulian() {
  int year, month, day;
  getDate(&year, &month, &day);
  int julianYear, julianMonth, julianDay;
  gregorianToJulian(year, month, day, &julianYear, &julianMonth, &julianDay);
  printJulianDate(julianYear, julianMonth, julianDay);
}

// Convert a date from the Julian calendar to the Gregorian calendar and print the result
void convertJulianToGregorian() {
  int year, month, day;
  getDate(&year, &month, &day);
  int gregorianYear, gregorianMonth, gregorianDay;
  julianToGregorian(year, month, day, &gregorianYear, &gregorianMonth, &gregorianDay);
  printGregorianDate(gregorianYear, gregorianMonth, gregorianDay);
}

// Print the menu
void printMenu() {
  printf("1. Convert a date from the Gregorian calendar to the Julian calendar\n");
  printf("2. Convert a date from the Julian calendar to the Gregorian calendar\n");
  printf("3. Exit\n");
}

// Get a choice from the user
int getChoice() {
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

// Main function
int main() {
  int choice;
  do {
    printMenu();
    choice = getChoice();
    switch (choice) {
      case 1:
        convertGregorianToJulian();
        break;
      case 2:
        convertJulianToGregorian();
        break;
      case 3:
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 3);
  return 0;
}