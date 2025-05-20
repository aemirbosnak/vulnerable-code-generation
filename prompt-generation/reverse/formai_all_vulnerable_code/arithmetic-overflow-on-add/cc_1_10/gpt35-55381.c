//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}

// Function to get the total number of days in a given month of a given year
int getMonthDays(int month, int year) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month-1];
}

// Function to calculate the Julian day number
int getJulianDay(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int jdn = day + (153 * m + 2) / 5 + (365 * y) + y / 4 - y / 100 + y / 400 - 32045;
    return jdn;
}

// Function to convert the Julian day number to Gregorian date
void getGregorianDate(int jdn, int *day, int *month, int *year) {
    int a = jdn + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (146097 * b) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;
    *day = e - (153 * m + 2) / 5 + 1;
    *month = m + 3 - 12 * (m / 10);
    *year = 100 * b + d - 4800 + m / 10;
}

// Function to convert a date string in format `dd-mm-yyyy` to Julian day number
int dateToJulianDay(char *dt) {
    int day, month, year;
    sscanf(dt,"%d-%d-%d",&day,&month,&year);
    return getJulianDay(day,month,year);
}

// Function to convert a Julian day number to a date string in format `dd-mm-yyyy`
void julianDayToDate(int jdn, char *dt) {
    int day, month, year;
    getGregorianDate(jdn,&day,&month,&year);
    sprintf(dt,"%02d-%02d-%04d",day,month,year);
}

int main() {
    char dateStr[11];
    int julianDay;
    printf("Enter a date in format dd-mm-yyyy: ");
    scanf("%s", dateStr);
    printf("The entered date is: %s\n", dateStr);
    julianDay = dateToJulianDay(dateStr);
    printf("The Julian Day number for the entered date is: %d\n", julianDay);
    julianDay += 1; // Increment the Julian Day number by 1 to get the next day's Julian Day number
    julianDayToDate(julianDay,dateStr);
    printf("The date for the next day is: %s\n", dateStr);
    return 0;
}