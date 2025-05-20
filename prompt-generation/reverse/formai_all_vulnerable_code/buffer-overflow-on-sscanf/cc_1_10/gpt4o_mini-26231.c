//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} datetime;

void printCurrentTime(datetime dt) {
    printf("Current Time: %04d-%02d-%02d %02d:%02d:%02d\n",
           dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
}

void timeTravel(datetime *dt, int years, int months, int days, int hours, int minutes, int seconds) {
    // Adjust date and time according to the inputs
    dt->second += seconds;
    dt->minute += dt->second / 60;
    dt->second %= 60;

    dt->minute += minutes;
    dt->hour += dt->minute / 60;
    dt->minute %= 60;

    dt->hour += hours;
    dt->day += dt->hour / 24;
    dt->hour %= 24;

    dt->day += days;
    dt->month += dt->day / 30;  // Simplistic month handling
    dt->day %= 30;

    dt->month += months;
    dt->year += dt->month / 12;
    dt->month %= 12;

    dt->year += years;
}

void getCurrentDateTime(datetime *dt) {
    time_t t = time(NULL);
    struct tm *tmInfo = localtime(&t);

    dt->year = tmInfo->tm_year + 1900;
    dt->month = tmInfo->tm_mon + 1;
    dt->day = tmInfo->tm_mday;
    dt->hour = tmInfo->tm_hour;
    dt->minute = tmInfo->tm_min;
    dt->second = tmInfo->tm_sec;
}

char *getMenuOption() {
    static char option[10];
    printf("Enter time travel parameters (years, months, days, hours, minutes, seconds) or 'exit' to quit: ");
    fgets(option, sizeof(option), stdin);
    option[strcspn(option, "\n")] = '\0';  // Remove newline character
    return option;
}

void parseInput(const char *input, int *years, int *months, int *days, int *hours, int *minutes, int *seconds) {
    sscanf(input, "%d %d %d %d %d %d", years, months, days, hours, minutes, seconds);
}

int main() {
    datetime currentTime;
    getCurrentDateTime(&currentTime);

    printf("Welcome to the Time Travel Simulator!\n");
    printCurrentTime(currentTime);

    while (1) {
        char *input = getMenuOption();
        
        if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
            break;
        }
        
        int years = 0, months = 0, days = 0, hours = 0, minutes = 0, seconds = 0;
        parseInput(input, &years, &months, &days, &hours, &minutes, &seconds);
        
        timeTravel(&currentTime, years, months, days, hours, minutes, seconds);
        
        printf("You have time-traveled to:\n");
        printCurrentTime(currentTime);
        
        // Reset current time to system time for the next iteration
        getCurrentDateTime(&currentTime);
    }
    return 0;
}