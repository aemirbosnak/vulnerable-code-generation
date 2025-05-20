//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

// Function to get total number of days in a month
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

// Function to convert Gregorian date to Julian day number
int toJulianDay(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int jd = day + (153 * m + 2) / 5 + (365 * y) + y / 4 - y / 100 + y / 400 - 32045;
    return jd;
}

// Struct to represent a date
struct Date {
    int day;
    int month;
    int year;
};

// Function to convert Julian day number to Gregorian date
void toGregorianDate(int jd, struct Date *date) {
    int a = jd + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (b * 146097) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;
    date->day = e - (153 * m + 2) / 5 + 1;
    date->month = m + 3 - 12 * (m / 10);
    date->year = b * 100 + d - 4800 + m / 10;
}

// Function to calculate duration between two dates
void getDuration(struct Date *startDate, struct Date *endDate, int *years, int *months, int *days) {
    int startJulianDay = toJulianDay(startDate->day, startDate->month, startDate->year);
    int endJulianDay = toJulianDay(endDate->day, endDate->month, endDate->year);
    int diff = endJulianDay - startJulianDay;

    if (diff < 0) {
        struct Date *temp = startDate;
        startDate = endDate;
        endDate = temp;
        diff = -diff;
    }

    int yearDiff = endDate->year - startDate->year;
    int monthDiff = endDate->month - startDate->month;
    int dayDiff = endDate->day - startDate->day;

    if (dayDiff < 0) {
        int daysInMonth = getDaysInMonth(startDate->month, startDate->year);
        dayDiff += daysInMonth;
        monthDiff--;
    }

    if (monthDiff < 0) {
        monthDiff += 12;
        yearDiff--;
    }

    *years = yearDiff;
    *months = monthDiff;
    *days = dayDiff;
}

// Function to convert date from one format to another
void convertDate(char *dateStr, char *format1, char *format2) {
    struct Date date;
    sscanf(dateStr, format1, &date.day, &date.month, &date.year);
    int jd = toJulianDay(date.day, date.month, date.year);
    toGregorianDate(jd, &date);
    printf(format2, date.day, date.month, date.year);
}

int main() {
    char dateStr[20];
    int years, months, days;

    // Convert "23/08/2025" to "23 August 2025"
    convertDate("23/08/2025", "%d/%d/%d", "%d %s %d");
    printf("\n");

    // Convert "01/01/2000" to "1 year 0 months 0 days"
    struct Date startDate = {1, 1, 2000};
    struct Date endDate = {1, 1, 2001};
    getDuration(&startDate, &endDate, &years, &months, &days);
    printf("%d year %d month %d day\n", years, months, days);
    printf("\n");

    // Convert "02/03/2021" to "2021-03-02"
    convertDate("02/03/2021", "%d/%d/%d", "%d-%02d-%02d");
    printf("\n");

    return 0;
}