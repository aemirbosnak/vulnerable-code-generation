//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <string.h>

// Function to check if a given year is a leap year
int isLeap(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

// Function to get the number of days in a given month
int getDaysInMonth(int month, int year) {
    switch(month) {
        case 2:
            return isLeap(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

// Function to convert a date string to a date struct
struct Date {
    int day, month, year;
};

struct Date getDateFromString(char* dateStr) {
    struct Date date;
    sscanf(dateStr, "%d-%d-%d", &date.year, &date.month, &date.day);
    return date;
}

// Function to convert a date struct to a date string
char* getStringFromDate(struct Date date) {
    static char dateString[11];
    sprintf(dateString, "%04d-%02d-%02d", date.year, date.month, date.day);
    return dateString;
}

// Function to add days to a date
struct Date addDaysToDate(struct Date date, int days) {
    while (days > 0) {
        int daysInMonth = getDaysInMonth(date.month, date.year);
        if (date.day + days > daysInMonth) {
            days -= daysInMonth - date.day + 1;
            date.day = 1;
            if (date.month == 12) {
                date.month = 1;
                date.year++;
            } else {
                date.month++;
            }
        } else {
            date.day += days;
            days = 0;
        }
    }
    return date;
}

// Main program
int main() {
    // Read input date
    char dateStr[11];
    scanf("%s", dateStr);
    struct Date date = getDateFromString(dateStr);

    // Read input number of days
    int days;
    scanf("%d", &days);

    // Add days to date
    struct Date newDate = addDaysToDate(date, days);

    // Print output date
    printf("%s\n", getStringFromDate(newDate));

    return 0;
}