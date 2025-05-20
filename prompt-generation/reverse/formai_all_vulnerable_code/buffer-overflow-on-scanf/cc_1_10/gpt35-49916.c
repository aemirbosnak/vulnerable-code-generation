//FormAI DATASET v1.0 Category: Robot movement control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT_MOTOR 1
#define RIGHT_MOTOR 2

bool is_happy = true;

void move_forward(int distance);
void move_backward(int distance);
void turn_left(int angle);
void turn_right(int angle);
void dance();

int main() {
    printf("Hello! I'm your happy dancing robot.\n");

    while (is_happy) {
        printf("What should I do next?\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Dance\n");
        printf("6. Quit\n");

        int choice;
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int distance;
                printf("Enter the distance (in cms) to move forward: ");
                scanf("%d", &distance);
                move_forward(distance);
                break;
            }
            case 2: {
                int distance;
                printf("Enter the distance (in cms) to move backward: ");
                scanf("%d", &distance);
                move_backward(distance);
                break;
            }
            case 3: {
                int angle;
                printf("Enter the angle (in degrees) to turn left: ");
                scanf("%d", &angle);
                turn_left(angle);
                break;
            }
            case 4: {
                int angle;
                printf("Enter the angle (in degrees) to turn right: ");
                scanf("%d", &angle);
                turn_right(angle);
                break;
            }
            case 5:
                dance();
                break;
            case 6:
                is_happy = false;
                printf("Bye! See you later\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-6\n");
        }
    }

    return 0;
}

void move_forward(int distance) {
    printf("Moving forward %d cms\n", distance);
    // Code to move the robot forward using motors
}

void move_backward(int distance) {
    printf("Moving backward %d cms\n", distance);
    // Code to move the robot backward using motors
}

void turn_left(int angle) {
    printf("Turning left %d degrees\n", angle);
    // Code to turn the robot left using motors
}

void turn_right(int angle) {
    printf("Turning right %d degrees\n", angle);
    // Code to turn the robot right using motors
}

void dance() {
    printf("Woo hoo! Let's dance!\n");
    // Code to make the robot dance using motors
    printf("That was fun! What should we do next?\n");
}