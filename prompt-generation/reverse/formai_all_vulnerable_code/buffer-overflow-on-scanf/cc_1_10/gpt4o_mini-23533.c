//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Define robot movement commands
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP,
    QUIT
} Command;

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Choose a movement command for your robot:\n");
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    printf("5. Stop\n");
    printf("6. Quit\n");
    printf("Enter your choice (1-6): ");
}

// Function to execute the command
void executeCommand(Command cmd) {
    switch (cmd) {
        case FORWARD:
            printf("Moving Forward... 🚀\n");
            break;
        case BACKWARD:
            printf("Moving Backward... 🚧\n");
            break;
        case LEFT:
            printf("Turning Left... ↖️\n");
            break;
        case RIGHT:
            printf("Turning Right... ↗️\n");
            break;
        case STOP:
            printf("Stopping... ⏸️\n");
            break;
        default:
            printf("Unknown Command!\n");
            break;
    }
}

int main() {
    int choice;
    Command cmd;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        // Assign the command based on user choice
        switch (choice) {
            case 1:
                cmd = FORWARD;
                break;
            case 2:
                cmd = BACKWARD;
                break;
            case 3:
                cmd = LEFT;
                break;
            case 4:
                cmd = RIGHT;
                break;
            case 5:
                cmd = STOP;
                break;
            case 6:
                printf("Quitting the program... 😢\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again. ❌\n");
                continue;
        }

        // Execute the chosen command
        executeCommand(cmd);

        // Simulate the robot's movement with a delay
        for (int i = 0; i < 3; ++i) {
            printf("...moving...\n");
            sleep(1); // Delay for 1 second
        }
        printf("Movement complete! ✅\n\n");
    }

    return 0;
}