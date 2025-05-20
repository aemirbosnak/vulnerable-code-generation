//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the possible movements of the robot.
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} Movement;

// Define the options for turning (left or right).
typedef enum {
    LEFT_TURN,
    RIGHT_TURN
} TurnDirection;

// Define the function that will move the robot in a specified direction.
void move(Movement direction) {
    // Determine which direction the robot should move in and print a message to the console.
    switch(direction) {
        case FORWARD:
            printf("Moving forward...\n");
            break;
        case BACKWARD:
            printf("Moving backward...\n");
            break;
        case LEFT:
            printf("Moving left...\n");
            break;
        case RIGHT:
            printf("Moving right...\n");
            break;
        default:
            printf("Invalid direction. Please try again.\n");
            break;
    }
}

// Define the function that will turn the robot in a specified direction.
void turn(TurnDirection direction) {
    // Determine which direction the robot should turn in and print a message to the console.
    switch(direction) {
        case LEFT_TURN:
            printf("Turning left...\n");
            break;
        case RIGHT_TURN:
            printf("Turning right...\n");
            break;
        default:
            printf("Invalid direction. Please try again.\n");
            break;
    }
}

int main() {
    // Welcome message.
    printf("Welcome to the Robot Movement Control Program!\n");

    // Initialize variables (current location, direction faced).
    int x = 0, y = 0;
    Movement currentDirection = FORWARD;

    // Ask user for input.
    char input;
    printf("Enter a movement command (F/B/L/R or Q to quit): ");

    // Continue to ask for input until the user quits the program.
    while (true) {
        // Get user input.
        scanf(" %c", &input);

        // Handle user input.
        switch(input) {
            case 'F':
                move(currentDirection);
                y++;
                break;
            case 'B':
                move(currentDirection);
                y--;
                break;
            case 'L':
                turn(LEFT_TURN);
                switch(currentDirection) {
                    case FORWARD:
                        currentDirection = LEFT;
                        break;
                    case BACKWARD:
                        currentDirection = RIGHT;
                        break;
                    case LEFT:
                        currentDirection = BACKWARD;
                        break;
                    case RIGHT:
                        currentDirection = FORWARD;
                        break;
                }
                break;
            case 'R':
                turn(RIGHT_TURN);
                switch(currentDirection) {
                    case FORWARD:
                        currentDirection = RIGHT;
                        break;
                    case BACKWARD:
                        currentDirection = LEFT;
                        break;
                    case LEFT:
                        currentDirection = FORWARD;
                        break;
                    case RIGHT:
                        currentDirection = BACKWARD;
                        break;
                }
                break;
            case 'Q':
                printf("Thanks for using the Robot Movement Control Program!\n");
                return 0;
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        // Print the current location and the next command prompt.
        printf("Current position: (%d, %d) facing ", x, y);
        switch(currentDirection) {
            case FORWARD:
                printf("north\n");
                break;
            case BACKWARD:
                printf("south\n");
                break;
            case LEFT:
                printf("west\n");
                break;
            case RIGHT:
                printf("east\n");
                break;
            default:
                printf("invalid direction\n");
                break;
        }
        printf("Enter a movement command (F/B/L/R or Q to quit): ");
    }

    return 0;
}