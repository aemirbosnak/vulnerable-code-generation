//FormAI DATASET v1.0 Category: Robot movement control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 200
#define MIN_SPEED 0

/* function to move the robot forward */
void move_forward(int speed) {
    printf("Moving forward at speed: %d\n", speed);
    // code to move the robot forward at specified speed
}

/* function to move the robot backward */
void move_backward(int speed) {
    printf("Moving backward at speed: %d\n", speed);
    // code to move the robot backward at specified speed
}

/* function to turn the robot left */
void turn_left(int speed) {
    printf("Turning left at speed: %d\n", speed);
    // code to turn the robot left at specified speed
}

/* function to turn the robot right */
void turn_right(int speed) {
    printf("Turning right at speed: %d\n", speed);
    // code to turn the robot right at specified speed
}

int main() {
    int speed = 100; // starting speed of the robot
    
    printf("Welcome to the Robot Movement Control Program!\n");
    
    // loop to receive user input and control the robot
    while(1) {
        char input;
        int new_speed;
        
        printf("\nEnter command (f: forward, b: backward, l: left, r: right, s: stop, c: change speed, q: quit): ");
        scanf(" %c", &input);
        
        switch(input) {
            case 'f':
                move_forward(speed);
                break;
            case 'b':
                move_backward(speed);
                break;
            case 'l':
                turn_left(speed);
                break;
            case 'r':
                turn_right(speed);
                break;
            case 's':
                printf("Stopping the robot.\n");
                // code to stop the robot's movement
                break;
            case 'c':
                printf("\nEnter new speed (between 0 and 200): ");
                scanf("%d", &new_speed);
                if(new_speed < MIN_SPEED) {
                    printf("Speed cannot be lower than %d. Setting speed to %d.\n", MIN_SPEED, MIN_SPEED);
                    speed = MIN_SPEED;
                }
                else if(new_speed > MAX_SPEED) {
                    printf("Speed cannot be higher than %d. Setting speed to %d.\n", MAX_SPEED, MAX_SPEED);
                    speed = MAX_SPEED;
                }
                else {
                    speed = new_speed;
                    printf("Speed set to: %d\n", speed);
                }
                break;
            case 'q':
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}