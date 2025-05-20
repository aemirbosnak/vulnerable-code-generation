//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Defining constants
#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Function prototypes
void move(int direction);
void stop();
void forward();
void backward();
void turnLeft();
void turnRight();

// Main function
int main()
{
    // Print welcome message
    printf("Welcome to C Robot Movement Control Program!\n");
    
    // Infinite loop for continuous control
    while(1) {
        // Display menu options
        printf("\nAvailable directions:\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Stop Robot\n");
        printf("6. Exit Program\n\n");
        
        int choice;
        
        // Ask for user input
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        // Switch statement to handle user input
        switch(choice) {
            case FORWARD:
                forward();
                break;
            case BACKWARD:
                backward();
                break;
            case LEFT:
                turnLeft();
                break;
            case RIGHT:
                turnRight();
                break;
            case STOP:
                stop();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Function definition for move()
void move(int direction)
{
    switch(direction) {
        case FORWARD:
            printf("\nMoving forward...\n");
            break;
        case BACKWARD:
            printf("\nMoving backward...\n");
            break;
        case LEFT:
            printf("\nTurning left...\n");
            break;
        case RIGHT:
            printf("\nTurning right...\n");
            break;
        default:
            printf("\nInvalid direction!\n");
    }
}

// Function definition for stop()
void stop()
{
    printf("\nStopping robot...\n");
}

// Function definition for forward()
void forward()
{
    move(FORWARD);
}

// Function definition for backward()
void backward()
{
    move(BACKWARD);
}

// Function definition for turnLeft()
void turnLeft()
{
    move(LEFT);
}

// Function definition for turnRight()
void turnRight()
{
    move(RIGHT);
}