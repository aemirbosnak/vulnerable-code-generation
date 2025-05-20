//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1900
#define MAX_ATTEMPTS 10
#define TIME_MACHINE_SPEED 88

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

int main() {
    char input[100];
    Time currentTime, destinationTime;
    int attempts = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", input);
    strptime(input, "%Y-%m-%d %H:%M:%S", &currentTime);

    while (attempts < MAX_ATTEMPTS) {
        printf("\nWhere and when would you like to travel?\n");
        printf("Enter destination date and time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        strptime(input, "%Y-%m-%d %H:%M:%S", &destinationTime);

        if (destinationTime.year < MIN_YEAR || destinationTime.year > MAX_YEAR) {
            printf("Invalid destination year.\n");
        } else if (destinationTime.month < 1 || destinationTime.month > 12) {
            printf("Invalid destination month.\n");
        } else if (destinationTime.day < 1 || destinationTime.day > 31) {
            printf("Invalid destination day.\n");
        } else if (destinationTime.hour < 0 || destinationTime.hour > 23) {
            printf("Invalid destination hour.\n");
        } else if (destinationTime.minute < 0 || destinationTime.minute > 59) {
            printf("Invalid destination minute.\n");
        } else if (destinationTime.second < 0 || destinationTime.second > 59) {
            printf("Invalid destination second.\n");
        } else {
            attempts++;
            int timeDifference = difftime(mktime(&destinationTime), mktime(&currentTime));

            if (timeDifference < 0) {
                printf("You cannot travel back in time.\n");
            } else {
                double distance = TIME_MACHINE_SPEED * timeDifference;
                printf("Traveling %.2f light years...\n", distance);
                currentTime = destinationTime;
                printf("\nArrived at %d-%02d-%02d %02d:%02d:%02d.\n", currentTime.year, currentTime.month, currentTime.day, currentTime.hour, currentTime.minute, currentTime.second);
            }
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("\nTime travel failed. Please try again later.\n");
    }

    return 0;
}