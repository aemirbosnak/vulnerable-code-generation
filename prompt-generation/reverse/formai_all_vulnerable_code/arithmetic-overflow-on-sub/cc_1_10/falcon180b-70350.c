//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1000
#define MAX_MONTH 12
#define MAX_DAY 31

// Function to check if a year is a leap year
int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a date is valid
int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > MAX_MONTH || day < 1 || day > MAX_DAY) {
        return 0;
    } else if (month == 2 && day > 29 &&!is_leap_year(year)) {
        return 0;
    } else {
        return 1;
    }
}

// Function to time travel
void time_travel(int year, int month, int day) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    t->tm_year = year - 1900;
    t->tm_mon = month - 1;
    t->tm_mday = day;
    t->tm_hour = 0;
    t->tm_min = 0;
    t->tm_sec = 0;
    time_t travel_time = mktime(t);
    sleep(difftime(travel_time, now));
}

// Main function
int main() {
    int year, month, day;

    // Get current date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    year = t->tm_year + 1900;
    month = t->tm_mon + 1;
    day = t->tm_mday;

    // Get destination date from user
    printf("Enter the destination year (between %d and %d): ", MIN_YEAR, MAX_YEAR);
    scanf("%d", &year);
    printf("Enter the destination month (between 1 and 12): ");
    scanf("%d", &month);
    printf("Enter the destination day (between 1 and 31): ");
    scanf("%d", &day);

    // Check if destination date is valid
    if (!is_valid_date(day, month, year)) {
        printf("Invalid date!\n");
        return 1;
    }

    // Time travel
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Time travel initiated!\n");
    time_travel(year, month, day);

    // Print destination date
    time_t travel_time = time(NULL);
    t = localtime(&travel_time);
    printf("You have traveled to %d-%02d-%02d %02d:%02d:%02d!\n", year, month, day, t->tm_hour, t->tm_min, t->tm_sec);

    return 0;
}