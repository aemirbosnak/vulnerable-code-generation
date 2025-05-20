//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TIME_SPEED 1000 // Time speed in milliseconds
#define TIME_MAX_SPEED 10 // Maximum speed up limit
#define TIME_MIN_SPEED 1 // Minimum speed down limit
#define TIME_ACCELERATION 50 // Acceleration factor

// Function to print the current date and time
void print_date_and_time(void) {
    time_t now = time(0);
    struct tm *t = localtime(&now);

    printf("Current date and time: %s", asctime(t));
}

// Function to travel through time
void time_travel(int direction, int speed) {
    time_t target_time = time(0);
    struct tm *t = localtime(&target_time);

    if (direction == 1) { // Traveling to the future
        target_time += speed * TIME_SPEED;
    } else { // Traveling to the past
        target_time -= speed * TIME_SPEED;
    }

    t = localtime(&target_time);
    printf("Traveling to %s", asctime(t));

    sleep(1); // Wait for 1 second before returning to the present
}

int main(void) {
    int choice, speed = TIME_MIN_SPEED;

    while (1) {
        system("clear"); // Clear the console

        printf("=== Time Travel Simulator ===\n");
        printf("1. Travel to the future\n");
        printf("2. Travel to the past\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                speed += TIME_ACCELERATION;
                if (speed > TIME_MAX_SPEED) {
                    speed = TIME_MAX_SPEED;
                }
                time_travel(1, speed);
                break;

            case 2:
                speed -= TIME_ACCELERATION;
                if (speed < TIME_MIN_SPEED) {
                    speed = TIME_MIN_SPEED;
                }
                time_travel(2, speed);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option, try again.\n");
        }
    }

    return 0;
}