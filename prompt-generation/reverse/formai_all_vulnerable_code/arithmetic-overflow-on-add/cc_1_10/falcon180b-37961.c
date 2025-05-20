//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to travel back in time
void time_travel_back(int seconds) {
    time_t target_time = time(NULL) - seconds;
    time_t current_time;
    do {
        current_time = time(NULL);
    } while (current_time >= target_time);
}

// Function to travel forward in time
void time_travel_forward(int seconds) {
    time_t target_time = time(NULL) + seconds;
    time_t current_time;
    do {
        current_time = time(NULL);
    } while (current_time <= target_time);
}

int main() {
    int choice, seconds;

    // Time machine initialization
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Initializing time machine...\n");
    srand(time(NULL));
    seconds = rand() % 86400; // Randomly travel between 0 and 24 hours
    time_travel_back(seconds);
    printf("Time machine initialized. You have traveled back in time by %d seconds.\n", seconds);

    // Main loop
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of seconds you want to travel back in time: ");
                scanf("%d", &seconds);
                time_travel_back(seconds);
                printf("You have traveled back in time by %d seconds.\n", seconds);
                break;
            case 2:
                printf("Enter the number of seconds you want to travel forward in time: ");
                scanf("%d", &seconds);
                time_travel_forward(seconds);
                printf("You have traveled forward in time by %d seconds.\n", seconds);
                break;
            case 3:
                printf("Exiting the Time Travel Simulator...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}