//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    time_t currentTime;
    struct tm *timeInfo;
    char *timeString;
    char response;
    int year, month, day;
    int futureYear, futureMonth, futureDay;
    int pastYear, pastMonth, pastDay;
    int leapYear;
    int i;
    
    // get current time and date
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    timeString = asctime(timeInfo);
    
    // welcome message
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today's date and time is: %s\n", timeString);
    printf("Would you like to travel to the past or the future? (P/F)\n");
    
    // user inputs whether they want to travel to past or future
    scanf("%c", &response);
    response = toupper(response);
    
    // if user wants to travel to the future
    if (response == 'F') {
        printf("Great! Please enter a future date:\n");
        printf("Year (yyyy): ");
        scanf("%d", &futureYear);
        printf("Month (mm): ");
        scanf("%d", &futureMonth);
        printf("Day (dd): ");
        scanf("%d", &futureDay);
        
        // check if input date is valid
        if (futureYear < timeInfo->tm_year + 1900 || (futureYear == timeInfo->tm_year + 1900 && futureMonth < timeInfo->tm_mon + 1) || (futureYear == timeInfo->tm_year + 1900 && futureMonth == timeInfo->tm_mon + 1 && futureDay <= timeInfo->tm_mday)) {
            printf("Invalid input. Please enter a future date.\n");
        } else {
            printf("Preparing to travel to %d/%d/%d...\n", futureMonth, futureDay, futureYear);
            printf("3..\n");
            sleep(1);
            printf("2..\n");
            sleep(1);
            printf("1..\n");
            sleep(1);
            printf("POOF!\n");
            printf("You have arrived in %d/%d/%d!\n", futureMonth, futureDay, futureYear);
        }
    }
    
    // if user wants to travel to the past
    else if (response == 'P') {
        printf("Interesting choice. Please enter a past date:\n");
        printf("Year (yyyy): ");
        scanf("%d", &pastYear);
        printf("Month (mm): ");
        scanf("%d", &pastMonth);
        printf("Day (dd): ");
        scanf("%d", &pastDay);
        
        // check if input date is valid
        if (pastYear > timeInfo->tm_year + 1900 || (pastYear == timeInfo->tm_year + 1900 && pastMonth > timeInfo->tm_mon + 1) || (pastYear == timeInfo->tm_year + 1900 && pastMonth == timeInfo->tm_mon + 1 && pastDay >= timeInfo->tm_mday)) {
            printf("Invalid input. Please enter a past date.\n");
        } else {
            printf("Preparing to travel to %d/%d/%d...\n", pastMonth, pastDay, pastYear);
            printf("3..\n");
            sleep(1);
            printf("2..\n");
            sleep(1);
            printf("1..\n");
            sleep(1);
            printf("POOF!\n");
            printf("You have arrived in %d/%d/%d!\n", pastMonth, pastDay, pastYear);
        }
    }
    
    // if user enters invalid response
    else {
        printf("Invalid response. Please enter 'P' for past or 'F' for future.\n");
    }
    
    return 0;
}