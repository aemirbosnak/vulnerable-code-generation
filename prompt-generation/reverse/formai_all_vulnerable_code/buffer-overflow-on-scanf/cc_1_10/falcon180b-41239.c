//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time periods that can be stored
#define MAX_TIME_PERIODS 100

// Define the structure for each time period
typedef struct {
    time_t timestamp;
    int index;
} TimePeriod;

// Initialize the array of time periods
TimePeriod timePeriods[MAX_TIME_PERIODS];
int numTimePeriods = 0;

// Function to add a new time period
void addTimePeriod(time_t timestamp) {
    if (numTimePeriods >= MAX_TIME_PERIODS) {
        printf("Error: Maximum number of time periods reached.\n");
        return;
    }
    timePeriods[numTimePeriods].timestamp = timestamp;
    timePeriods[numTimePeriods].index = numTimePeriods;
    numTimePeriods++;
}

// Function to travel back in time
void travelBackInTime(int index) {
    if (index < 0 || index >= numTimePeriods) {
        printf("Error: Invalid time period index.\n");
        return;
    }
    time_t timestamp = timePeriods[index].timestamp;
    time_t currentTime;
    time(&currentTime);
    while (currentTime > timestamp) {
        sleep(1);
        time(&currentTime);
    }
    printf("Traveled back in time to %s\n", ctime(&timestamp));
}

int main(int argc, char* argv[]) {
    addTimePeriod(time(NULL)); // Add the current time as the first time period
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Add a new time period\n");
        printf("2. Travel back in time\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTimePeriod(time(NULL));
                break;
            case 2:
                printf("Enter the index of the time period to travel back to:\n");
                scanf("%d", &choice);
                travelBackInTime(choice - 1);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}