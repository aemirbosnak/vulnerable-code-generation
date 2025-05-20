//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: peaceful
/*
 * Time Travel Simulator
 * Peaceful Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int year, month, day, hour, minute, second;
    char time_travel_mode;

    // Get current time
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    year = ltm->tm_year + 1900;
    month = ltm->tm_mon + 1;
    day = ltm->tm_mday;
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;

    // Ask user for time travel mode
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please select a time travel mode (past, present, or future): ");
    scanf("%c", &time_travel_mode);

    // Check if time travel mode is valid
    if (time_travel_mode != 'p' && time_travel_mode != 'f') {
        printf("Invalid time travel mode selected. Exiting...\n");
        return 1;
    }

    // Calculate new time
    if (time_travel_mode == 'p') {
        year--;
        if (month == 1) {
            year--;
            month = 12;
        } else {
            month--;
        }
        if (day == 1) {
            month--;
            day = 31;
        } else {
            day--;
        }
        if (hour == 0) {
            hour = 23;
        } else {
            hour--;
        }
        if (minute == 0) {
            minute = 59;
        } else {
            minute--;
        }
        if (second == 0) {
            second = 59;
        } else {
            second--;
        }
    } else if (time_travel_mode == 'f') {
        year++;
        if (month == 12) {
            year++;
            month = 1;
        } else {
            month++;
        }
        if (day == 31) {
            month++;
            day = 1;
        } else {
            day++;
        }
        if (hour == 23) {
            hour = 0;
        } else {
            hour++;
        }
        if (minute == 59) {
            minute = 0;
        } else {
            minute++;
        }
        if (second == 59) {
            second = 0;
        } else {
            second++;
        }
    }

    // Print new time
    printf("New time: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);

    return 0;
}