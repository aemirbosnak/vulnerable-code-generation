//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime;
    struct tm *timeinfo;
    int hours, minutes, seconds; // simulation variables
    
    time(&currentTime);
    timeinfo = localtime(&currentTime);

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Enter a future year (YYYY): ");
    int futureYear;
    scanf("%d", &futureYear);
    printf("\n");
   
    if(futureYear <= timeinfo->tm_year + 1900){
        printf("Sorry, you can only travel to the future!\n");
        return 0;
    }
    
    int yearDiff = futureYear - (timeinfo->tm_year + 1900);
    int totalSeconds = yearDiff * 365 * 24 * 60 * 60;
    
    printf("Enter a future time (HH:MM:SS): ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);
    printf("\n");

    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
        printf("Invalid time!\n");
        return 0;
    }

    totalSeconds += hours * 60 * 60 + minutes * 60 + seconds;

    printf("Your time travel destination: %d-%02d-%02d %02d:%02d:%02d\n", 
           futureYear, timeinfo->tm_mon + 1, timeinfo->tm_mday, hours, minutes, seconds);
    printf("Travel begins in:\n");

    for (int i = 10; i >= 0; i--) {
        printf("%d\n", i);
        sleep(1);
    }

    printf("You have arrived at your destination!\n");

    time_t newTime = currentTime + totalSeconds;
    struct tm *newTimeinfo = localtime(&newTime);

    printf("Current time: %d-%02d-%02d %02d:%02d:%02d\n",
            newTimeinfo->tm_year + 1900, newTimeinfo->tm_mon + 1, newTimeinfo->tm_mday,
            newTimeinfo->tm_hour, newTimeinfo->tm_min, newTimeinfo->tm_sec);
    return 0;
}