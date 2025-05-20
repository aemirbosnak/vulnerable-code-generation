//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <string.h>

// Function to return the number of days in a given month
int daysInMonth(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Function to return the number of days between two given dates
int daysBetweenDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    int days = 0;

    // Handling years
    for (int i = y1; i < y2; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            days += 366;
        } else {
            days += 365;
        }
    }

    // Handling months
    for (int i = 1; i < m1; i++) {
        days -= daysInMonth(i, y1);
    }
    days -= d1 - 1;

    for (int i = 1; i < m2; i++) {
        days += daysInMonth(i, y2);
    }
    days += d2;

    return days;
}

int main() {
    char date[11];
    const char delim[2] = "/";
    int day, month, year;

    // Getting input date from user
    printf("Enter date (DD/MM/YYYY): ");
    fgets(date, 11, stdin);
    strtok(date, "\n");

    // Parsing input date
    char *token = strtok(date, delim);
    int i = 1;
    while (token != NULL) {
        if (i == 1) {
            day = atoi(token);
        } else if (i == 2) {
            month = atoi(token);
        } else {
            year = atoi(token);
        }
        token = strtok(NULL, delim);
        i++;
    }

    // Converting date to days since Jan 1, 1900
    int daysSince1900 = 0;
    for (int i = 1900; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            daysSince1900 += 366;
        } else {
            daysSince1900 += 365;
        }
    }

    for (int i = 1; i < month; i++) {
        daysSince1900 += daysInMonth(i, year);
    }

    daysSince1900 += day - 1;

    // Converting days since Jan 1, 1900 to date format
    int currentYear = 1900;
    int currentMonth = 1;
    int currentDay = 1;

    while (daysSince1900 > 0) {
        int daysInCurrentMonth = daysInMonth(currentMonth, currentYear);
        if (daysSince1900 >= daysInCurrentMonth) {
            currentMonth++;
            if (currentMonth > 12) {
                currentYear++;
                currentMonth = 1;
            }
            daysSince1900 -= daysInCurrentMonth;
        } else {
            currentDay += daysSince1900;
            if (currentDay > daysInCurrentMonth) {
                currentDay -= daysInCurrentMonth;
                currentMonth++;
                if (currentMonth > 12) {
                    currentYear++;
                    currentMonth = 1;
                }
            }
            daysSince1900 = 0;
        }
    }

    // Printing converted date
    printf("Converted date (YYYY-MM-DD): %d-%02d-%02d\n", currentYear, currentMonth, currentDay);

    // Handling date difference calculation
    char date2[11];
    int day2, month2, year2;

    // Getting second input date from user
    printf("Enter second date (DD/MM/YYYY): ");
    fgets(date2, 11, stdin);
    strtok(date2, "\n");

    // Parsing second input date
    token = strtok(date2, delim);
    i = 1;
    while (token != NULL) {
        if (i == 1) {
            day2 = atoi(token);
        } else if (i == 2) {
            month2 = atoi(token);
        } else {
            year2 = atoi(token);
        }
        token = strtok(NULL, delim);
        i++;
    }

    // Calculating date difference
    int dateDiff = daysBetweenDates(day, month, year, day2, month2, year2);

    // Printing date difference
    printf("Date difference: %d days\n", dateDiff);

    return 0;
}