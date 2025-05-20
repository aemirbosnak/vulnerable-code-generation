//FormAI DATASET v1.0 Category: Date and time ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXYEAR 2100
#define MINYEAR 1900

// Function to check if year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int days;
    switch (month) {
        case 1:
            days = 31;
            break;
        case 2:
            if (isLeapYear(year))
                days = 29;
            else
                days = 28;
            break;
        case 3:
            days = 31;
            break;
        case 4:
            days = 30;
            break;
        case 5:
            days = 31;
            break;
        case 6:
            days = 30;
            break;
        case 7:
            days = 31;
            break;
        case 8:
            days = 31;
            break;
        case 9:
            days = 30;
            break;
        case 10:
            days = 31;
            break;
        case 11:
            days = 30;
            break;
        case 12:
            days = 31;
            break;
    }
    return days;
}

// Function to get the name of the month in a string
char* getMonthName(int month) {
    char* monthName;
    switch (month) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
    }
    return monthName;
}

int main() {
    // Initialize variables
    time_t now;
    struct tm *currentTime;
    int year, month, day, hour, minute, second;

    // Get current system time
    time(&now);
    currentTime = localtime(&now);

    // Set current date and time variables
    year = currentTime->tm_year + 1900;
    month = currentTime->tm_mon + 1;
    day = currentTime->tm_mday;
    hour = currentTime->tm_hour;
    minute = currentTime->tm_min;
    second = currentTime->tm_sec;

    // Print current date and time
    printf("Current Date and Time: %02d-%s-%d %02d:%02d:%02d\n", day, getMonthName(month), year, hour, minute, second);

    // Get user input for a different date and time
    printf("\nEnter a date and time (DD-MM-YYYY HH:MM:SS): ");
    scanf("%d-%d-%d %d:%d:%d", &day, &month, &year, &hour, &minute, &second);

    // Validate input values
    if (year < MINYEAR || year > MAXYEAR) {
        printf("Invalid year entered.\n");
        return 1;
    }
    if (month < 1 || month > 12) {
        printf("Invalid month entered.\n");
        return 1;
    }
    if (day < 1 || day > getDaysInMonth(month, year)) {
        printf("Invalid day entered.\n");
        return 1;
    }
    if (hour < 0 || hour > 23) {
        printf("Invalid hour entered.\n");
        return 1;
    }
    if (minute < 0 || minute > 59) {
        printf("Invalid minute entered.\n");
        return 1;
    }
    if (second < 0 || second > 59) {
        printf("Invalid second entered.\n");
        return 1;
    }

    // Set user input date and time
    currentTime->tm_year = year - 1900;
    currentTime->tm_mon = month - 1;
    currentTime->tm_mday = day;
    currentTime->tm_hour = hour;
    currentTime->tm_min = minute;
    currentTime->tm_sec = second;
    now = mktime(currentTime);

    // Print user input date and time
    printf("User Input Date and Time: %02d-%s-%d %02d:%02d:%02d\n", day, getMonthName(month), year, hour, minute, second);

    // Calculate the difference between current time and user input time
    time_t diff = difftime(now, time(NULL));

    // Print the difference in seconds, minutes, and hours
    printf("\nDifference: ");
    if (diff < 0) {
        printf("-");
        diff *= -1;
    }
    printf("%ld seconds (%ld minutes, %ld hours)\n", diff, diff / 60, diff / 3600);

    return 0;
}