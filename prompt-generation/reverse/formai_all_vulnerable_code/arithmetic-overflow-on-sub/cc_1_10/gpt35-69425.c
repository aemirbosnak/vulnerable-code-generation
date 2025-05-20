//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get year
int getYear(int year) {
    printf("Enter a year between 1600 and 2200: ");
    scanf("%d", &year);

    while (year < 1600 || year > 2200) {
        printf("\nInvalid input! Please enter a year between 1600 and 2200: ");
        scanf("%d", &year);
    }

    return year;
}

// Function to get month
int getMonth(int month) {
    printf("Enter a month between 1 and 12: ");
    scanf("%d", &month);

    while (month < 1 || month > 12) {
        printf("\nInvalid input! Please enter a month between 1 and 12: ");
        scanf("%d", &month);
    }

    return month;
}

// Function to get day
int getDay(int day, int month, int year) {
    printf("Enter a day between 1 and 31: ");
    scanf("%d", &day);

    while (day < 1 || (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) ||
           (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) ||
           (day > 28 && month == 2 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) ||
           (day > 29 && month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))) {
        printf("\nInvalid input! Please enter a valid day for this month and year: ");
        scanf("%d", &day);
    }

    return day;
}

// Function to get time
int getTime(int time) {
    printf("Enter a time between 0 and 23: ");
    scanf("%d", &time);

    while (time < 0 || time > 23) {
        printf("\nInvalid input! Please enter a time between 0 and 23: ");
        scanf("%d", &time);
    }

    return time;
}

int main() {
    int year = 0, month = 0, day = 0, time = 0;

    year = getYear(year);
    month = getMonth(month);
    day = getDay(day, month, year);
    time = getTime(time);

    // Set the date and time
    struct tm timeInfo = {0};
    timeInfo.tm_year = year - 1900;
    timeInfo.tm_mon = month - 1;
    timeInfo.tm_mday = day;
    timeInfo.tm_hour = time;

    // Convert to UNIX timestamp
    time_t timestamp = mktime(&timeInfo);
    printf("\nUnix timestamp for the entered date and time: %ld\n", timestamp);

    // Perform time travel simulation
    printf("\nPerforming time travel simulation...\n");
    timestamp -= 3600; // Travel back 1 hour
    printf("\nDate and time after time travel simulation: %s", ctime(&timestamp));

    return 0;
}