//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Define robot movements
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4
#define STOP 5

// Function Prototypes
void moveRobot(int direction);
void signalHandler(int sig);
void displayMovement(int direction);

// Global state
volatile sig_atomic_t running = 1;

// Signal handling for graceful shutdown
void signalHandler(int sig) {
    running = 0;
    printf("\nShutting down the robot... Thank you for using our robot!\n");
}

// Implementation of robot movement control
void moveRobot(int direction) {
    switch(direction) {
        case MOVE_FORWARD:
            displayMovement(MOVE_FORWARD);
            printf("The robot is moving forward! Whee!\n");
            break;
        case MOVE_BACKWARD:
            displayMovement(MOVE_BACKWARD);
            printf("The robot is backing up! Watch out!\n");
            break;
        case TURN_LEFT:
            displayMovement(TURN_LEFT);
            printf("Whaaaat a turn! The robot is turning left!\n");
            break;
        case TURN_RIGHT:
            displayMovement(TURN_RIGHT);
            printf("Whoa! What a spin! The robot is turning right!\n");
            break;
        case STOP:
            displayMovement(STOP);
            printf("The robot has come to a majestic stop! Rrrr...\n");
            break;
        default:
            printf("Oh no! Unknown movement command!\n");
            break;
    }
}

// Display movement visually
void displayMovement(int direction) {
    switch(direction) {
        case MOVE_FORWARD:
            printf(" >>> ");
            break;
        case MOVE_BACKWARD:
            printf(" <<< ");
            break;
        case TURN_LEFT:
            printf(" < ");
            break;
        case TURN_RIGHT:
            printf(" > ");
            break;
        case STOP:
            printf(" = ");
            break;
        default:
            printf(" ? ");
            break;
    }
    fflush(stdout);
}

// Main function
int main() {
    signal(SIGINT, signalHandler); // Catch Ctrl+C for a graceful shutdown

    printf("🏎️  Welcome to the Exciting Robot Movement Program! Let's get moving! 🏎️\n");

    while (running) {
        int command;
        printf("\nChoose a movement:\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Stop\n");
        printf("Enter your choice (1-5): ");
        
        // Get input from the user
        if (scanf("%d", &command) != 1) {
            printf("Please enter a valid number!\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        // Execute the movement command
        switch(command) {
            case 1:
                moveRobot(MOVE_FORWARD);
                break;
            case 2:
                moveRobot(MOVE_BACKWARD);
                break;
            case 3:
                moveRobot(TURN_LEFT);
                break;
            case 4:
                moveRobot(TURN_RIGHT);
                break;
            case 5:
                moveRobot(STOP);
                break;
            default:
                printf("Yikes! That's not a valid option! ⚠️\n");
                break;
        }

        // Simulate a delay to visualize movement
        sleep(1);
    }

    printf("Robot has safely exited the program. Until next time! 🚀\n");
    return 0;
}