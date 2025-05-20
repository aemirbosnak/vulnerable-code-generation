//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include<stdio.h>

// Function to move the car forward
void moveForward(){
    printf("Car moving forward\n");
}

// Function to move the car backward
void moveBackward(){
    printf("Car moving backward\n");
}

// Function to turn the car left
void turnLeft(){
    printf("Car turning left\n");
}

// Function to turn the car right
void turnRight(){
    printf("Car turning right\n");
}

// Function to stop the car
void stop(){
    printf("Car stopped\n");
}

int main(){
    char command;
    printf("Welcome to the Remote Control Vehicle Simulator\n");
    printf("Enter 'f' to move forward, 'b' to move backward, 'l' to turn left, 'r' to turn right and 's' to stop the car: ");

    while(1){
        scanf("%c", &command);

        switch(command){
            case 'f':
                moveForward();
                break;
            
            case 'b':
                moveBackward();
                break;

            case 'l':
                turnLeft();
                break;

            case 'r':
                turnRight();
                break;

            case 's':
                stop();
                break;

            default:
                printf("Invalid command\n");
                break;
        }

        printf("Enter another command: ");
    }

    return 0;
}