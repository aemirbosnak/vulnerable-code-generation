//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to move forward in time by a given number of seconds
void moveForward(int seconds) {
    struct tm tm;
    time_t now = time(NULL);
    localtime_r(&now, &tm);
    tm.tm_sec += seconds;
    localtime_r(&now, &tm);
    printf("Forward by %d seconds. Current time: %s\n", seconds, asctime(localtime(&now)));
}

// Function to move backward in time by a given number of seconds
void moveBackward(int seconds) {
    struct tm tm;
    time_t now = time(NULL);
    localtime_r(&now, &tm);
    tm.tm_sec -= seconds;
    localtime_r(&now, &tm);
    printf("Backward by %d seconds. Current time: %s\n", seconds, asctime(localtime(&now)));
}

int main() {
    int choice, seconds, minutes, hours;

    // Main loop
    do {
        printf("Time Travel Simulator\n");
        printf("1. Move forward in time\n");
        printf("2. Move backward in time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user input
        switch (choice) {
            case 1:
                printf("Enter the number of seconds to move forward: ");
                scanf("%d", &seconds);
                moveForward(seconds);
                break;
            case 2:
                printf("Enter the number of seconds to move backward: ");
                scanf("%d", &seconds);
                moveBackward(seconds);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 3);

    return 0;
}