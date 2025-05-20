//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>

// Function to get Julian Day Number
int getJulianDayNum(int day, int month, int year) {
    int a, y, m;
    a = (14 - month) / 12;
    y = year + 4800 - a;
    m = month + 12 * a - 3;
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

// Function to get Gregorian Calendar Date
void getGregorianDate(int julianDayNum, int *day, int *month, int *year) {
    int a, b, c, d, e, m;
    int f = julianDayNum + 1401 + (((4 * julianDayNum + 274277) / 146097) * 3) / 4 - 38;
    int g = f / 1461;
    e = f - (1461 * g) + 31;
    int h = e / 32;
    a = (h > 12) ? (h - 12) : h;
    b = e - (h * 32);
    c = (g - 4716) + ((a > 2) ? 1 : 0);
    *day = b;
    *month = a;   
    *year = c;
}

// Main function to convert natural language date to Julian Day Number
int main() {
    char month[10];
    int day, year;
    
    // Reading input string
    printf("Enter the natural language date (Example: August 20, 2022): ");
    scanf("%s %d, %d", month, &day, &year);

    // Converting input string to Julian Day Number
    int monthNumeric = 1;
    if (strcmp(month, "February") == 0) {
        monthNumeric = 2;
    } else if (strcmp(month, "March") == 0) {
        monthNumeric = 3;
    } else if (strcmp(month, "April") == 0) {
        monthNumeric = 4;
    } else if (strcmp(month, "May") == 0) {
        monthNumeric = 5;
    } else if (strcmp(month, "June") == 0) {
        monthNumeric = 6;
    } else if (strcmp(month, "July") == 0) {
        monthNumeric = 7;
    } else if (strcmp(month, "August") == 0) {
        monthNumeric = 8;
    } else if (strcmp(month, "September") == 0) {
        monthNumeric = 9;
    } else if (strcmp(month, "October") == 0) {
        monthNumeric = 10;
    } else if (strcmp(month, "November") == 0) {
        monthNumeric = 11;
    } else if (strcmp(month, "December") == 0) {
        monthNumeric = 12;
    }
    int julianDayNum = getJulianDayNum(day, monthNumeric, year);

    // Converting Julian Day Number to Gregorian Calendar Date
    int gDay, gMonth, gYear;
    getGregorianDate(julianDayNum, &gDay, &gMonth, &gYear);

    // Printing the result in standard format
    printf("Result: %d/%d/%d\n", gMonth, gDay, gYear);
    return 0;
}