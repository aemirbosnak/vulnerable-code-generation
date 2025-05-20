//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

// Function to convert a date string into an integer date representation
int convertDateToInt(char* dateStr) {
    int day, month, year;
    sscanf(dateStr, "%d-%d-%d", &year, &month, &day);
    
    int totalDays = 0;

    for (int y = 1; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++) {
        totalDays += getDaysInMonth(m, year);
    }
    
    totalDays += day;

    return totalDays;
}

// Function to convert an integer date representation back to a date string
void convertIntToDate(int days, char* dateStr) {
    int year = 1, month = 1, day = 1;

    while (days >= (isLeapYear(year) ? 366 : 365)) {
        days -= isLeapYear(year) ? 366 : 365;
        year++;
    }

    while (days > 0) {
        int daysInMonth = getDaysInMonth(month, year);
        if (days >= daysInMonth) {
            days -= daysInMonth;
            month++;
        } else {
            day += days;
            days = 0;
        }
    }

    sprintf(dateStr, "%04d-%02d-%02d", year, month, day);
}

// Function to obtain the current date from the system
void getCurrentDate(char* currentDateStr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(currentDateStr, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

// Main function
int main() {
    char dateStr[BUFFER_SIZE];
    char currentDateStr[BUFFER_SIZE];
    int continueConversion = 1;

    getCurrentDate(currentDateStr);
    printf("Today's Date: %s\n", currentDateStr);

    while (continueConversion) {
        printf("Enter a date in 'YYYY-MM-DD' format: ");
        fgets(dateStr, BUFFER_SIZE, stdin);
        dateStr[strcspn(dateStr, "\n")] = 0; // Remove newline character
        
        int convertedDate = convertDateToInt(dateStr);
        printf("Converted Date to Integer Days: %d\n", convertedDate);

        char outputDate[BUFFER_SIZE];
        convertIntToDate(convertedDate, outputDate);
        printf("Converted back to Date: %s\n", outputDate);

        printf("Continue (1 for Yes, 0 for No): ");
        scanf("%d", &continueConversion);
        getchar(); // To consume newline left by scanf
    }

    printf("Exiting date converter program.\n");
    return 0;
}