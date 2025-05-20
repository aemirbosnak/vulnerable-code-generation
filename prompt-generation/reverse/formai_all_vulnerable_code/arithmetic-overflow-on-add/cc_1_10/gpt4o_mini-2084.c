//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void displayTime(int year, int month, int day, int hour, int minute, int second) {
    printf("Current Time: %04d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return 31 - (month - 1) % 7 % 2;
}

void travelThroughTime(int *year, int *month, int *day, int *hour, int *minute, int *second, int timeWarp) {
    *second += timeWarp;

    while (*second >= 60) {
        *second -= 60;
        *minute += 1;
    }

    while (*minute >= 60) {
        *minute -= 60;
        *hour += 1;
    }

    while (*hour >= 24) {
        *hour -= 24;
        *day += 1;
    }

    while (*day > daysInMonth(*month, *year)) {
        *day -= daysInMonth(*month, *year);
        *month += 1;
    }

    while (*month > 12) {
        *month -= 12;
        *year += 1;
    }
}

void getCurrentTime(int *year, int *month, int *day, int *hour, int *minute, int *second) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    *year = tm_info->tm_year + 1900;
    *month = tm_info->tm_mon + 1;
    *day = tm_info->tm_mday;
    *hour = tm_info->tm_hour;
    *minute = tm_info->tm_min;
    *second = tm_info->tm_sec;
}

void displayMainMenu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("1. Travel Forward in Time\n");
    printf("2. Travel Backward in Time\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int year, month, day, hour, minute, second;
    getCurrentTime(&year, &month, &day, &hour, &minute, &second);
    
    printf("Welcome to the Time Travel Simulator!\n");
    displayTime(year, month, day, hour, minute, second);
    
    while (1) {
        displayMainMenu();
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int forwardSeconds;
            printf("Enter seconds to travel forward: ");
            scanf("%d", &forwardSeconds);
            travelThroughTime(&year, &month, &day, &hour, &minute, &second, forwardSeconds);
            printf("You have traveled forward in time!\n");
            displayTime(year, month, day, hour, minute, second);
        } else if (choice == 2) {
            int backwardSeconds;
            printf("Enter seconds to travel backward: ");
            scanf("%d", &backwardSeconds);
            travelThroughTime(&year, &month, &day, &hour, &minute, &second, -backwardSeconds);
            printf("You have traveled backward in time!\n");
            displayTime(year, month, day, hour, minute, second);
        } else if (choice == 3) {
            printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
        
        sleep(1); // Introduce a little pause for better experience
    }

    return 0;
}