//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a robot
typedef struct {
    int x;
    int y;
    int direction;
} Robot;

// Function to initialize the robot
void init_robot(Robot* robot) {
    robot->x = 0;
    robot->y = 0;
    robot->direction = 0;
}

// Function to move the robot forward
void move_forward(Robot* robot) {
    printf("Robot is moving forward...\n");
    robot->x += 1;
}

// Function to turn the robot left
void turn_left(Robot* robot) {
    printf("Robot is turning left...\n");
    robot->direction = (robot->direction + 3) % 4;
}

// Function to turn the robot right
void turn_right(Robot* robot) {
    printf("Robot is turning right...\n");
    robot->direction = (robot->direction + 1) % 4;
}

// Function to print the current status of the robot
void print_robot_status(Robot* robot) {
    printf("Current status of the robot:\n");
    printf("X position: %d\n", robot->x);
    printf("Y position: %d\n", robot->y);
    printf("Direction: %d\n", robot->direction);
}

// Main function to control the robot movement
int main() {
    Robot robot;
    init_robot(&robot);

    int choice;
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Print status\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move_forward(&robot);
                break;
            case 2:
                turn_left(&robot);
                break;
            case 3:
                turn_right(&robot);
                break;
            case 4:
                print_robot_status(&robot);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}