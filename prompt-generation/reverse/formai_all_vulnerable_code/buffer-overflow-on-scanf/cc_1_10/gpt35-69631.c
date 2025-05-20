//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10

void moveForward(int speed) {
    printf("Moving Forward at speed %d \n", speed);
}

void moveBackward(int speed) {
    printf("Moving Backward at speed %d \n", speed);
}

void turnLeft(int speed) {
    printf("Turning Left at speed %d \n", speed);
}

void turnRight(int speed) {
    printf("Turning Right at speed %d \n", speed);
}

int main() {
    int currentSpeed = 0;
    char direction = 'f';
    
    // Let's simulate some user input to control the robot
    while(1) {
        printf("Enter a direction and speed (e.g. f 5): ");
        scanf(" %c %d", &direction, &currentSpeed);
        
        // Scale the speed to the MAX_SPEED
        if(currentSpeed > MAX_SPEED) {
            currentSpeed = MAX_SPEED;
        } else if(currentSpeed < -MAX_SPEED) {
            currentSpeed = -MAX_SPEED;
        }
        
        // Handle the direction input
        switch(direction) {
            case 'f':
                moveForward(currentSpeed);
                break;
            case 'b':
                moveBackward(currentSpeed);
                break;
            case 'l':
                turnLeft(currentSpeed);
                break;
            case 'r':
                turnRight(currentSpeed);
                break;
            default:
                printf("Invalid direction. Please try again.\n");
        }
    }
    
    return 0;
}