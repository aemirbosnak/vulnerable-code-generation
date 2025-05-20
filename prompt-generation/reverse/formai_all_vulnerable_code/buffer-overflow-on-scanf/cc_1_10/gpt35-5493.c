//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//function prototypes
void displayTime(int year, int month, int day, int hour, int minute);
bool isLeapYear(int year);

int main() {
    //initialize time
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    //current time
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    int currentHour = localTime->tm_hour;
    int currentMinute = localTime->tm_min;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("The current date and time is: ");
    displayTime(currentYear, currentMonth, currentDay, currentHour, currentMinute);

    //get input from user
    printf("Please enter a year to travel to (YYYY): ");
    int inputYear;
    scanf("%d", &inputYear);
    while (inputYear < currentYear) {
        printf("Error: You can only travel forward in time! Please enter a future year (YYYY): ");
        scanf("%d", &inputYear);
    }

    printf("Please enter a month to travel to (MM): ");
    int inputMonth;
    scanf("%d", &inputMonth);
    while (inputMonth > 12 || inputMonth < 1) {
        printf("Error: Invalid month! Please enter a valid month (MM): ");
        scanf("%d", &inputMonth);
    }

    int maxDay;
    switch (inputMonth) {
        case 2:
            if (isLeapYear(inputYear)) {
                maxDay = 29;
            } else {
                maxDay = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDay = 30;
            break;
        default:
            maxDay = 31;
    }

    printf("Please enter a day to travel to (DD): ");
    int inputDay;
    scanf("%d", &inputDay);
    while (inputDay > maxDay || inputDay < 1) {
        printf("Error: Invalid day! Please enter a valid day (DD): ");
        scanf("%d", &inputDay);
    }

    printf("Please enter an hour to travel to (HH): ");
    int inputHour;
    scanf("%d", &inputHour);
    while (inputHour > 23 || inputHour < 0) {
        printf("Error: Invalid hour! Please enter a valid hour (HH): ");
        scanf("%d", &inputHour);
    }

    printf("Please enter a minute to travel to (MM): ");
    int inputMinute;
    scanf("%d", &inputMinute);
    while (inputMinute > 59 || inputMinute < 0) {
        printf("Error: Invalid minute! Please enter a valid minute (MM): ");
        scanf("%d", &inputMinute);
    }

    printf("\nYou have traveled through time!\n");
    printf("You have arrived at: ");
    displayTime(inputYear, inputMonth, inputDay, inputHour, inputMinute);

    return 0;
}

//function to display time
void displayTime(int year, int month, int day, int hour, int minute) {
    printf("%02d/%02d/%d %02d:%02d\n", month, day, year, hour, minute);
}

//function to determine if year is a leap year
bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}