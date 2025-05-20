//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 10000 // Maximum time travel range in seconds

// Function prototypes
void time_travel(int time);
void shape_shift(int shape);

int main() {
    int choice;
    int time = 0;
    int shape = 1; // 1 for human, 2 for animal, 3 for object

    do {
        printf("\n");
        printf("Time Travel and Shape Shifting Simulator\n");
        printf("-----------------------------------------\n");
        printf("Current time: %d seconds\n", time);
        printf("Current shape: %d (%s)\n", shape, (shape == 1)? "human" : (shape == 2)? "animal" : "object");
        printf("Options:\n");
        printf("1. Time travel\n");
        printf("2. Shape shift\n");
        printf("3. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Time travel
                printf("Enter the number of seconds to travel (up to %d): ", MAX_TIME);
                scanf("%d", &time);
                time_travel(time);
                break;
            case 2: // Shape shift
                printf("Enter the new shape (1 for human, 2 for animal, 3 for object): ");
                scanf("%d", &shape);
                shape_shift(shape);
                break;
            case 3: // Exit
                printf("Exiting program...\n");
                exit(0);
            default: // Invalid choice
                printf("Invalid choice.\n");
        }

    } while (1); // Infinite loop to keep program running

    return 0;
}

void time_travel(int time) {
    printf("Time traveling...\n");
    sleep(time); // Pause for the specified number of seconds
    printf("Time travel complete.\n");
}

void shape_shift(int shape) {
    printf("Shape shifting...\n");
    sleep(1); // Pause for 1 second for effect
    printf("Shape shift complete. You are now a %s.\n", (shape == 1)? "human" : (shape == 2)? "animal" : "object");
}