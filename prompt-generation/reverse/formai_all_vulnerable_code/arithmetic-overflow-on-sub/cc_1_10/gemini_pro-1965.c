//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the time travel simulator
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeTravelSimulator;

// Initialize the time travel simulator
void initializeTimeTravelSimulator(TimeTravelSimulator *tts) {
    // Get the current time
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    // Set the time travel simulator to the current time
    tts->year = tm->tm_year + 1900;
    tts->month = tm->tm_mon + 1;
    tts->day = tm->tm_mday;
    tts->hour = tm->tm_hour;
    tts->minute = tm->tm_min;
    tts->second = tm->tm_sec;
}

// Travel forward in time
void travelForwardInTime(TimeTravelSimulator *tts, int years, int months, int days, int hours, int minutes, int seconds) {
    // Add the specified amount of time to the time travel simulator
    tts->year += years;
    tts->month += months;
    tts->day += days;
    tts->hour += hours;
    tts->minute += minutes;
    tts->second += seconds;

    // Handle any overflow
    if (tts->second >= 60) {
        tts->second -= 60;
        tts->minute++;
    }
    if (tts->minute >= 60) {
        tts->minute -= 60;
        tts->hour++;
    }
    if (tts->hour >= 24) {
        tts->hour -= 24;
        tts->day++;
    }
    if (tts->day >= 31) {
        tts->day -= 31;
        tts->month++;
    }
    if (tts->month >= 12) {
        tts->month -= 12;
        tts->year++;
    }
}

// Travel backward in time
void travelBackwardInTime(TimeTravelSimulator *tts, int years, int months, int days, int hours, int minutes, int seconds) {
    // Subtract the specified amount of time from the time travel simulator
    tts->year -= years;
    tts->month -= months;
    tts->day -= days;
    tts->hour -= hours;
    tts->minute -= minutes;
    tts->second -= seconds;

    // Handle any underflow
    if (tts->second < 0) {
        tts->second += 60;
        tts->minute--;
    }
    if (tts->minute < 0) {
        tts->minute += 60;
        tts->hour--;
    }
    if (tts->hour < 0) {
        tts->hour += 24;
        tts->day--;
    }
    if (tts->day < 0) {
        tts->day += 31;
        tts->month--;
    }
    if (tts->month < 0) {
        tts->month += 12;
        tts->year--;
    }
}

// Print the current time
void printTime(TimeTravelSimulator *tts) {
    printf("%d-%02d-%02d %02d:%02d:%02d\n", tts->year, tts->month, tts->day, tts->hour, tts->minute, tts->second);
}

// Main function
int main() {
    // Initialize the time travel simulator
    TimeTravelSimulator tts;
    initializeTimeTravelSimulator(&tts);

    // Print the current time
    printf("Current time: ");
    printTime(&tts);

    // Travel forward in time
    travelForwardInTime(&tts, 1, 0, 0, 0, 0, 0);

    // Print the new time
    printf("New time: ");
    printTime(&tts);

    // Travel backward in time
    travelBackwardInTime(&tts, 1, 0, 0, 0, 0, 0);

    // Print the new time
    printf("New time: ");
    printTime(&tts);

    return 0;
}