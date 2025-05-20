//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to travel back in time
void time_travel_backward(int seconds) {
    time_t target_time = time(NULL) - seconds;
    time_t current_time;

    // Keep looping until we reach the target time
    do {
        current_time = time(NULL);
    } while (current_time > target_time);

    printf("You have successfully traveled back in time by %d seconds!\n", seconds);
}

// Function to travel forward in time
void time_travel_forward(int seconds) {
    time_t target_time = time(NULL) + seconds;
    time_t current_time;

    // Keep looping until we reach the target time
    do {
        current_time = time(NULL);
    } while (current_time < target_time);

    printf("You have successfully traveled forward in time by %d seconds!\n", seconds);
}

int main() {
    int choice, seconds;

    // Loop until the user chooses to quit
    do {
        printf("Welcome to the Time Travel Simulator!\n\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of seconds you want to travel back in time: ");
                scanf("%d", &seconds);
                time_travel_backward(seconds);
                break;
            case 2:
                printf("Enter the number of seconds you want to travel forward in time: ");
                scanf("%d", &seconds);
                time_travel_forward(seconds);
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}