//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 10
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE -1

// Function prototypes
int attemptTimeTravel(int *currentTime, int targetTime);
void printTimeTravelResults(int result);

int main() {
    int currentTime = 0, targetTime, result;
    char choice;

    do {
        printf("Current time: %d\n", currentTime);
        printf("Enter target time to travel to (0 to quit): ");
        scanf("%d", &targetTime);

        if (targetTime!= 0) {
            result = attemptTimeTravel(&currentTime, targetTime);
            printTimeTravelResults(result);
        }

        printf("Do you want to time travel again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Attempts to travel through time
int attemptTimeTravel(int *currentTime, int targetTime) {
    struct tm target;
    time_t targetSeconds;

    // Convert target time into seconds since epoch
    target.tm_year = targetTime / 10000 - 1900;
    target.tm_mon = (targetTime % 10000) / 100 - 1;
    target.tm_mday = targetTime % 100;
    target.tm_hour = 0;
    target.tm_min = 0;
    target.tm_sec = 0;

    targetSeconds = mktime(&target);

    // Check if target time is within allowed range
    if (targetSeconds < (*currentTime) || targetSeconds > (*currentTime) + 86400) {
        return TIME_TRAVEL_FAILURE;
    }

    // Update current time
    (*currentTime) = targetSeconds;

    return TIME_TRAVEL_SUCCESS;
}

// Prints results of time travel attempt
void printTimeTravelResults(int result) {
    if (result == TIME_TRAVEL_SUCCESS) {
        printf("Time travel successful!\n");
    } else {
        printf("Time travel failed.\n");
    }
}