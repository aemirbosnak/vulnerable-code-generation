//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 500000 // Delay in microseconds

// Robot states
enum RobotState {
    STAND,
    SQUAT,
    LIE_DOWN,
    CRAWL,
    JUMP
};

// Function to simulate robot movement
void moveRobot(enum RobotState state) {
    switch (state) {
        case STAND:
            printf("The robot is standing tall, ready to move!\n");
            break;
        case SQUAT:
            printf("The robot is squatting, preparing to spring into action!\n");
            break;
        case LIE_DOWN:
            printf("The robot is lying down flat, conserving energy.\n");
            break;
        case CRAWL:
            printf("The robot is crawling low to the ground, evading obstacles.\n");
            break;
        case JUMP:
            printf("The robot jumps into the air gracefully!\n");
            break;
        default:
            printf("Unknown state!\n");
    }
}

// Simulate shape-shifting with different movements
void shapeShiftMovement() {
    enum RobotState states[] = {STAND, SQUAT, LIE_DOWN, CRAWL, JUMP};
    int n = sizeof(states) / sizeof(states[0]);

    for (int i = 0; i < n; i++) {
        moveRobot(states[i]);
        usleep(DELAY); // Wait for a moment to simulate movement time
    }

    // Transition through movements
    for (int i = n - 1; i >= 0; i--) {
        moveRobot(states[i]);
        usleep(DELAY);
    }
}

// Main function to control the robot movement
int main() {
    printf("Welcome to the Shape-Shifting Robot Control Program!\n\n");

    while (1) {
        printf("Performing shape-shift movement...\n");

        // Execute shape-shifting movement
        shapeShiftMovement();

        // Ask the user if they want to repeat
        char choice;
        printf("Do you want to repeat the movement? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            printf("Exiting the program.\n");
            break;
        }
        printf("\n");
    }

    return 0;
}