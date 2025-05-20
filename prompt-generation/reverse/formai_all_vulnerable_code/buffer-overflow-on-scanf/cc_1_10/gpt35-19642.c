//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>

// Function to move the vehicle forward
void move_forward() {
    printf("Moving forward\n");
}

// Function to move the vehicle backwards
void move_backward() {
    printf("Moving backward\n");
}

// Function to turn the vehicle left
void turn_left() {
    printf("Turning left\n");
}

// Function to turn the vehicle right
void turn_right() {
    printf("Turning right\n");
}

// Function to stop the vehicle
void stop() {
    printf("Stopping\n");
}

int main() {
    char input;
    
    printf("Welcome to the Remote Control Vehicle Simulation\n");
    printf("---------------------------------------------\n");
    printf("Press 'F' to move the vehicle forward\n");
    printf("Press 'B' to move the vehicle backwards\n");
    printf("Press 'L' to turn the vehicle left\n");
    printf("Press 'R' to turn the vehicle right\n");
    printf("Press 'S' to stop the vehicle\n");
    printf("Press 'Q' to quit\n");
    
    while (1) {
        printf("Enter command: ");
        scanf(" %c", &input);
        
        switch (input) {
            case 'F':
                move_forward();
                break;
            case 'B':
                move_backward();
                break;
            case 'L':
                turn_left();
                break;
            case 'R':
                turn_right();
                break;
            case 'S':
                stop();
                break;
            case 'Q':
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }
    
    return 0;
}