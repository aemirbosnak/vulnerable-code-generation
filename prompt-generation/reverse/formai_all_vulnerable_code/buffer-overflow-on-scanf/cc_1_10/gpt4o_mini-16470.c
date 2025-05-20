//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure for Time Travel Machine
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char destination[50];
} TimeMachine;

// Function prototypes
void displayCurrentTime();
void setDestination(TimeMachine *tm);
void timeTravel(TimeMachine *tm);
void printTravelDetails(TimeMachine *tm);
int isLeapYear(int year);
void calculateDate(int year, int month, int day);

int main() {
    TimeMachine tm;
    tm.year = 2023;
    tm.month = 11;
    tm.day = 1;
    tm.hour = 12;
    tm.minute = 0;
    tm.second = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    
    // Set initial time
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    tm.year = local->tm_year + 1900; // tm_year is years since 1900
    tm.month = local->tm_mon + 1;    // tm_mon is months since January
    tm.day = local->tm_mday;
    tm.hour = local->tm_hour;
    tm.minute = local->tm_min;
    tm.second = local->tm_sec;

    // Display the current time
    displayCurrentTime();

    // Set destination for time travel
    setDestination(&tm);
    
    // Travel in time
    timeTravel(&tm);
    
    return 0;
}

// Function to display the current time
void displayCurrentTime() {
    printf("Current Time: 2023-11-01 12:00:00\n");
}

// Function to set travel destination
void setDestination(TimeMachine *tm) {
    printf("Enter the year you want to travel to: ");
    scanf("%d", &tm->year);
    
    printf("Enter the month you want to travel to (1-12): ");
    scanf("%d", &tm->month);
    
    printf("Enter the day you want to travel to: ");
    scanf("%d", &tm->day);
    
    printf("Enter the hour you want to travel to (0-23): ");
    scanf("%d", &tm->hour);
    
    printf("Enter the minute you want to travel to (0-59): ");
    scanf("%d", &tm->minute);
    
    printf("Enter the second you want to travel to (0-59): ");
    scanf("%d", &tm->second);
    
    printf("Enter a destination description: ");
    scanf(" %[^\n]", tm->destination); // Read string with spaces
}

// Function to perform time travel
void timeTravel(TimeMachine *tm) {
    printf("\nPreparing to travel...\n");
    
    // Simulated time travel
    sleep(2); // Pause for effect
    printTravelDetails(tm);
    
    printf("Time Travel Successful! Welcome to %s.\n", tm->destination);
}

// Function to print travel details
void printTravelDetails(TimeMachine *tm) {
    printf("Traveling to: %d-%02d-%02d %02d:%02d:%02d\n", 
            tm->year, tm->month, tm->day, tm->hour, tm->minute, tm->second);
}

// Function to check for leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

// Function to calculate date (optional details)
void calculateDate(int year, int month, int day) {
    // Placeholder for date calculation functionality
    printf("Calculating date for %d-%02d-%02d...\n", year, month, day);
}