//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <string.h>

char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

struct Date {
    int day, month, year;
};

void printDate(struct Date d) {
    printf("%02d-%s-%04d", d.day, months[d.month-1], d.year);
}

int isLeapYear(int year) {
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) {
        return 1;
    }
    return 0;
}

int daysInMonth(int month, int year) {
    if(month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

struct Date convertDate(char *dateString) {
    struct Date result;
    char *dayString, *monthString, *yearString;

    // extract day, month and year from string
    dayString = strtok(dateString, "-");
    monthString = strtok(NULL, "-");
    yearString = strtok(NULL, "-");

    // convert strings to integers
    result.day = atoi(dayString);
    result.month = atoi(monthString);
    result.year = atoi(yearString);

    return result;
}

long daysBetween(struct Date start, struct Date end) {
    long days = 0;

    // calculate days in current year from start date
    for(int month = start.month; month <= 12; month++) {
        days += daysInMonth(month, start.year);
    }
    days -= start.day;

    // calculate days in years between start and end dates
    for(int year = start.year+1; year < end.year; year++) {
        days += isLeapYear(year) ? 366 : 365;
    }

    // calculate days in current year from end date
    for(int month = 1; month < end.month; month++) {
        days += daysInMonth(month, end.year);
    }
    days += end.day;

    return days;
}

int main() {
    char dateString[11];
    struct Date startDate, endDate;

    printf("Enter start date in format DD-MM-YYYY:\n");
    scanf("%s", dateString);
    startDate = convertDate(dateString);

    printf("Enter end date in format DD-MM-YYYY:\n");
    scanf("%s", dateString);
    endDate = convertDate(dateString);

    long days = daysBetween(startDate, endDate);
    printf("Days between ");
    printDate(startDate);
    printf(" and ");
    printDate(endDate);
    printf(": %ld", days);

    return 0;
}