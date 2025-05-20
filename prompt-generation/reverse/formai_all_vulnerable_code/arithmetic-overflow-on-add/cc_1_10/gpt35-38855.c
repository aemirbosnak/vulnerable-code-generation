//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>

int isLeap(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
        return 1;
    }
    return 0;
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeap(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

void printDateTime(int day, int month, int year, int hour, int minute, int second) {
    printf("%02d/%02d/%d %02d:%02d:%02d\n", month, day, year, hour, minute, second);
}

int main() {
    int day, month, year, hour, minute, second, daysInMonth, daysInYear, totalDays;

    printf("Enter date and time in natural language format (MM/DD/YYYY HH:MM:SS):\n");
    scanf("%d/%d/%d %d:%d:%d", &month, &day, &year, &hour, &minute, &second);

    // Validate input
    if (day < 1 || day > 31 || month < 1 || month > 12 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        printf("Invalid input\n");
        return 1;
    }

    // Get days in month and year
    daysInMonth = getDaysInMonth(month, year);
    daysInYear = isLeap(year) ? 366 : 365;

    // Validate day input based on days in month and year
    if (day > daysInMonth) {
        printf("Invalid input\n");
        return 1;
    }

    // Calculate the total number of days elapsed in the given year so far
    int daysElapsedInYear = 0;
    for (int i = 1; i < month; i++) {
        daysElapsedInYear += getDaysInMonth(i, year);
    }
    daysElapsedInYear += day - 1;

    // Calculate the total number of days elapsed since 1/1/0001
    totalDays = (year - 1) * daysInYear + daysElapsedInYear;

    // Add leap days
    for (int i = 1; i < year; i++) {
        if (isLeap(i)) {
            totalDays++;
        }
    }

    // Calculate seconds elapsed today
    int secondsElapsedToday = hour * 3600 + minute * 60 + second;

    // Calculate total seconds elapsed
    int totalSeconds = totalDays * 86400 + secondsElapsedToday;

    // Print the converted date and time in natural language
    printDateTime(day, month, year, hour, minute, second);
    printf("Total seconds elapsed since 1/1/0001: %d\n", totalSeconds);

    return 0;
}