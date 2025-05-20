//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>

/* Function to move the robot forward */
void move_forward(int steps) {
    printf("Moving robot forward %d steps\n", steps);
    /* Code to move the robot forward */
}

/* Function to move the robot backward */
void move_backward(int steps) {
    printf("Moving robot backward %d steps\n", steps);
    /* Code to move the robot backward */
}

/* Function to turn the robot left */
void turn_left(int degrees) {
    printf("Turning robot left %d degrees\n", degrees);
    /* Code to turn the robot left */
}

/* Function to turn the robot right */
void turn_right(int degrees) {
    printf("Turning robot right %d degrees\n", degrees);
    /* Code to turn the robot right */
}

/* Function to stop the robot */
void stop_robot() {
    printf("Stopping robot\n");
    /* Code to stop the robot */
}

/* Main function */
int main() {
    int input;
    while(1) {
        printf("\nPlease enter a command for the robot:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        printf("6. Exit\n\n");
        scanf("%d", &input);

        switch(input) {
            case 1:
                move_forward(5);
                break;
            case 2:
                move_backward(5);
                break;
            case 3:
                turn_left(90);
                break;
            case 4:
                turn_right(90);
                break;
            case 5:
                stop_robot();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input, please try again.\n");
        }
    }
    return 0;
}