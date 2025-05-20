//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //set up variables for current year and time
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    int currentHour = localTime->tm_hour;
    int currentMinute = localTime->tm_min;
    int currentSecond = localTime->tm_sec;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current Date and Time: %d/%d/%d %02d:%02d:%02d\n", currentMonth, currentDay, currentYear, currentHour, currentMinute, currentSecond);

    //ask user for input on year, month, day, and time they want to travel to
    int travelYear, travelMonth, travelDay, travelHour, travelMinute;
    printf("Enter the year you want to travel to: ");
    scanf("%d", &travelYear);
    printf("Enter the month you want to travel to: ");
    scanf("%d", &travelMonth);
    printf("Enter the day you want to travel to: ");
    scanf("%d", &travelDay);
    printf("Enter the hour you want to travel to: ");
    scanf("%d", &travelHour);
    printf("Enter the minute you want to travel to: ");
    scanf("%d", &travelMinute);

    //calculate the number of seconds between current and travel times
    struct tm travelTime = {0};
    travelTime.tm_year = travelYear - 1900;
    travelTime.tm_mon = travelMonth - 1;
    travelTime.tm_mday = travelDay;
    travelTime.tm_hour = travelHour;
    travelTime.tm_min = travelMinute;
    time_t travelTimeInSeconds = mktime(&travelTime);
    int secondsToTravel = (int)difftime(travelTimeInSeconds, currentTime);

    if (secondsToTravel <= 0) {
        printf("You cannot travel back in time! Please try again.\n");
        return 0;
    }

    //simulate the time travel by counting down seconds
    printf("Travelling through time...\n");
    for (int i = secondsToTravel; i >= 0; i--) {
        int yearsPassed = (currentYear - (localtime(&currentTime)->tm_year + 1900));
        int monthsPassed = yearsPassed * 12 + (currentMonth - (localtime(&currentTime)->tm_mon + 1));
        int daysPassed = monthsPassed * 30 + (currentDay - (localtime(&currentTime)->tm_mday));
        int hoursPassed = daysPassed * 24 + (currentHour - (localtime(&currentTime)->tm_hour));
        int minutesPassed = hoursPassed * 60 + (currentMinute - (localtime(&currentTime)->tm_min));
        int secondsPassed = minutesPassed * 60 + (currentSecond - (localtime(&currentTime)->tm_sec));
        printf("Time travelled: %d years, %d months, %d days, %d hours, %d minutes, %d seconds left\n", yearsPassed, monthsPassed, daysPassed, hoursPassed, minutesPassed, secondsPassed);
        sleep(1);
        currentTime++;
    }

    //print the final time after time travel is complete
    printf("Arrived at destination time: %d/%d/%d %02d:%02d:%02d\n", travelMonth, travelDay, travelYear, travelHour, travelMinute, 0);

    return 0;
}