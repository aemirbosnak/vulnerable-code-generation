//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SPEED 5
#define MAX_ANGLE 90

// function prototypes
void move_forward(int speed);
void move_backward(int speed);
void turn_left(int angle);
void turn_right(int angle);

int main() {
    int throttle = 0;
    int steering = 0;
    char command[50];

    printf("Remote Control Vehicle Simulation\n");

    while(1) {
        printf("\nPlease enter a command (i.e. 'forward 3', 'turn left 45'): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            printf("Exiting program.\n");
            break;
        }
        else if (strcmp(command, "stop") == 0) {
            printf("Vehicle has stopped.\n");
            throttle = 0;
            steering = 0;
        }
        else if (strncmp(command, "forward", 7) == 0) {
            int speed = atoi(&command[8]);
            if (speed > MAX_SPEED) {
                printf("Speed is too high. Maximum speed is %d.\n", MAX_SPEED);
            } else {
                printf("Moving forward at speed %d.\n", speed);
                move_forward(speed);
                throttle = speed;
            }
        }
        else if (strncmp(command, "backward", 8) == 0) {
            int speed = atoi(&command[9]);
            if (speed > MAX_SPEED) {
                printf("Speed is too high. Maximum speed is %d.\n", MAX_SPEED);
            } else {
                printf("Moving backward at speed %d.\n", speed);
                move_backward(speed);
                throttle = -speed;
            }
        }
        else if (strncmp(command, "turn left", 9) == 0) {
            int angle = atoi(&command[10]);
            if (angle > MAX_ANGLE) {
                printf("Angle is too high. Maximum angle is %d.\n", MAX_ANGLE);
            } else {
                printf("Turning left at angle %d.\n", angle);
                turn_left(angle);
                steering = -angle;
            }
        }
        else if (strncmp(command, "turn right", 10) == 0) {
            int angle = atoi(&command[11]);
            if (angle > MAX_ANGLE) {
                printf("Angle is too high. Maximum angle is %d.\n", MAX_ANGLE);
            } else {
                printf("Turning right at angle %d.\n", angle);
                turn_right(angle);
                steering = angle;
            }
        } 
        else if (strncmp(command, "status", 6) == 0) {
            printf("Throttle: %d, Steering: %d\n", throttle, steering);
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

void move_forward(int speed) {
    printf("Vehicle moving forward at speed %d.\n", speed);
    // code to control motor forward
}

void move_backward(int speed) {
    printf("Vehicle moving backward at speed %d.\n", speed);
    // code to control motor backward
}

void turn_left(int angle) {
    printf("Vehicle turning left at angle %d.\n", angle);
    // code to control steering left
}

void turn_right(int angle) {
    printf("Vehicle turning right at angle %d.\n", angle);
    // code to control steering right
}