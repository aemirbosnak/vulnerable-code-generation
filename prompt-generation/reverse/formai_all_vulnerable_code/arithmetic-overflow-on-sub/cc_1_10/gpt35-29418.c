//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void timeTravel(int year, int month, int day, int hour, int minute, int second) {
    struct tm timeinfo = { 0 };
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = second;

    const time_t travelTime = mktime(&timeinfo);

    time_t currentTime;
    time(&currentTime);

    double timeDifference = difftime(travelTime, currentTime);

    if (timeDifference < 0) {
        printf("You have travelled back in time!\n");
    }
    else {
        printf("You have travelled into the future!\n");
    }

    printf("The time difference is: %.0f seconds\n", timeDifference);

    //wait for the time difference
    struct timespec sleepTime;
    sleepTime.tv_sec = (time_t)timeDifference;
    sleepTime.tv_nsec = 0;
    nanosleep(&sleepTime, NULL);

    //print the new time
    struct tm newTimeInfo;
    time_t newTime = time(NULL);
    localtime_r(&newTime, &newTimeInfo);
    printf("The new time is: %s\n", asctime(&newTimeInfo));
}

int main() {
    int year, month, day, hour, minute, second;

    printf("Enter the year you want to time travel to: ");
    scanf("%d", &year);

    printf("Enter the month you want to time travel to: ");
    scanf("%d", &month);

    printf("Enter the day you want to time travel to: ");
    scanf("%d", &day);

    printf("Enter the hour you want to time travel to: ");
    scanf("%d", &hour);

    printf("Enter the minute you want to time travel to: ");
    scanf("%d", &minute);

    printf("Enter the second you want to time travel to: ");
    scanf("%d", &second);

    timeTravel(year, month, day, hour, minute, second);

    return 0;
}