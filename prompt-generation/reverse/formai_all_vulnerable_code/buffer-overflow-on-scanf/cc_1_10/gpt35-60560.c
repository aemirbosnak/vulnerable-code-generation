//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
/* Woohoo! Let's move this robot, baby! */
/* Starting by initializing our motors */

#include <stdio.h>
#include <stdlib.h>

/* Let's define some variables */
int motor_left_speed = 0;
int motor_right_speed = 0;
int motor_left_direction = 1;
int motor_right_direction = 1;

int main() {
    
    /* Setting up a while loop to keep the action going */
    while(1) {
        
        /* Initializing some user input */
        char input;
        printf("Type l/r/f/b to move left/right/forward/backward: ");
        scanf("%c", &input);
        
        /* Handling the input */
        switch(input){
            case 'l':
                motor_left_speed = 50;
                motor_right_speed = 50;
                motor_left_direction = -1;
                motor_right_direction = 1;
                break;
            case 'r':
                motor_left_speed = 50;
                motor_right_speed = 50;
                motor_left_direction = 1;
                motor_right_direction = -1;
                break;
            case 'f':
                motor_left_speed = 100;
                motor_right_speed = 100;
                motor_left_direction = 1;
                motor_right_direction = 1;
                break;
            case 'b':
                motor_left_speed = 100;
                motor_right_speed = 100;
                motor_left_direction = -1;
                motor_right_direction = -1;
                break;
            default:
                printf("Please enter a valid input.\n");
        }
        
        /* Moving the robot based on user input */
        printf("Moving robot!\n");
        printf("Left motor: speed=%d, direction=%d\n", motor_left_speed, motor_left_direction);
        printf("Right motor: speed=%d, direction=%d\n", motor_right_speed, motor_right_direction);
        
        /* Pausing for a moment so we can admire the robot's movement */
        printf("3...\n");
        sleep(1);
        printf("2...\n");
        sleep(1);
        printf("1...\n");
        sleep(1);
        
        /* Resetting the motor speeds and directions */
        motor_left_speed = 0;
        motor_right_speed = 0;
        motor_left_direction = 1;
        motor_right_direction = 1;
    }
    
    return 0;
}