//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel simulator.
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeTravelSimulator;

// Initialize the time travel simulator.
TimeTravelSimulator timeTravelSimulator;

// Get the current time.
void getCurrentTime() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    timeTravelSimulator.year = tm->tm_year + 1900;
    timeTravelSimulator.month = tm->tm_mon + 1;
    timeTravelSimulator.day = tm->tm_mday;
    timeTravelSimulator.hour = tm->tm_hour;
    timeTravelSimulator.minute = tm->tm_min;
    timeTravelSimulator.second = tm->tm_sec;
}

// Set the time.
void setTime(int year, int month, int day, int hour, int minute, int second) {
    timeTravelSimulator.year = year;
    timeTravelSimulator.month = month;
    timeTravelSimulator.day = day;
    timeTravelSimulator.hour = hour;
    timeTravelSimulator.minute = minute;
    timeTravelSimulator.second = second;
}

// Travel to the past.
void travelToPast(int years, int months, int days, int hours, int minutes, int seconds) {
    timeTravelSimulator.year -= years;
    timeTravelSimulator.month -= months;
    timeTravelSimulator.day -= days;
    timeTravelSimulator.hour -= hours;
    timeTravelSimulator.minute -= minutes;
    timeTravelSimulator.second -= seconds;
}

// Travel to the future.
void travelToFuture(int years, int months, int days, int hours, int minutes, int seconds) {
    timeTravelSimulator.year += years;
    timeTravelSimulator.month += months;
    timeTravelSimulator.day += days;
    timeTravelSimulator.hour += hours;
    timeTravelSimulator.minute += minutes;
    timeTravelSimulator.second += seconds;
}

// Get the current time.
void printCurrentTime() {
    printf("Current time: %d-%02d-%02d %02d:%02d:%02d\n", timeTravelSimulator.year, timeTravelSimulator.month, timeTravelSimulator.day, timeTravelSimulator.hour, timeTravelSimulator.minute, timeTravelSimulator.second);
}

// Main function.
int main() {
    // Initialize the time travel simulator.
    getCurrentTime();

    // Travel to the past.
    travelToPast(1, 0, 0, 0, 0, 0);
    printCurrentTime();

    // Travel to the future.
    travelToFuture(1, 0, 0, 0, 0, 0);
    printCurrentTime();

    return 0;
}