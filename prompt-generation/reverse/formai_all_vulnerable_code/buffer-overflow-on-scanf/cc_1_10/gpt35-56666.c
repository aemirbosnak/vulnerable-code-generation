//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define robot movements
typedef enum {
    MOVE_FORWARD,
    MOVE_BACKWARD,
    TURN_LEFT,
    TURN_RIGHT
} movement;

// Define a function to get the robot movement
movement get_movement() {
    int choice;
    printf("Enter the robot movement:\n");
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    scanf("%d", &choice);

    // Check for invalid input
    while (choice < 1 || choice > 4) {
        printf("Invalid input! Please enter a valid choice:\n");
        scanf("%d", &choice);
    }

    // Convert choice to movement
    switch(choice) {
        case 1:
            return MOVE_FORWARD;
        case 2:
            return MOVE_BACKWARD;
        case 3:
            return TURN_LEFT;
        case 4:
            return TURN_RIGHT;
    }
}

// Define main function
int main() {
    int x = 0, y = 0; // Robot position
    movement m; // Current movement

    printf("Welcome to Robot Control System!\n");
    printf("--------------------------------\n");

    // Loop until user exits
    while(1) {
        m = get_movement();

        // Update position based on movement
        switch(m) {
            case MOVE_FORWARD:
                y++;
                break;
            case MOVE_BACKWARD:
                y--;
                break;
            case TURN_LEFT:
                x--;
                break;
            case TURN_RIGHT:
                x++;
                break;
        }

        // Print current position
        printf("Robot is currently at (%d,%d)\n", x, y);

        // Ask if user wants to continue or exit
        printf("Enter 1 to continue, 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}