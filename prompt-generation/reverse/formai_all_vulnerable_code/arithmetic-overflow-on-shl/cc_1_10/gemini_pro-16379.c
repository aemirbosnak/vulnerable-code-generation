//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to convert a date from Gregorian to Julian
int GregorianToJulian(int month, int day, int year) {
  int a = (14 - month) / 12;
  int y = year + 4800 - a;
  int m = month + 12 * a - 3;
  return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

// Function to convert a date from Julian to Gregorian
int JulianToGregorian(int julianDate) {
  int a = julianDate + 32044;
  int b = (4 * a + 3) / 146097;
  int c = a - (b * 146097) / 4;
  int d = (4 * c + 3) / 1461;
  int e = c - (d * 1461) / 4;
  int f = (5 * e + 2) / 153;
  int g = e - (f * 153 + 2) / 5 + 1;
  int h = f + 2 - 12 * (f + 2) / 10;
  int i = g - h + 31;
  int j = h - (i / 30 + 4) * 30 + 1;
  int k = b * 100;
  int l = k + (j / 30 + 39) / 31;
  int year = l + 4;
  int month = j - (i / 30 + 4) * 30 + 1;
  int day = i;
  return (year << 9) | (month << 5) | day;
}

int main() {
  // Get the Gregorian date from the user
  int month, day, year;
  printf("Enter the Gregorian date (MM/DD/YYYY): ");
  scanf("%d/%d/%d", &month, &day, &year);

  // Convert the Gregorian date to Julian
  int julianDate = GregorianToJulian(month, day, year);

  // Print the Julian date
  printf("The Julian date is: %d\n", julianDate);

  // Convert the Julian date back to Gregorian
  int gregorianDate = JulianToGregorian(julianDate);

  // Print the Gregorian date
  printf("The Gregorian date is: %d/%d/%d\n", gregorianDate >> 9, gregorianDate >> 5 & 0x1F, gregorianDate & 0x1F);

  return 0;
}