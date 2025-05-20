//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: interoperable
#include <stdio.h>

// function to move the drone up
void moveUp(int speed) {
    printf("Moving drone up at speed %d \n", speed);
}

// function to move the drone down
void moveDown(int speed) {
    printf("Moving drone down at speed %d \n", speed);
}

// function to move the drone left
void moveLeft(int speed) {
    printf("Moving drone left at speed %d \n", speed);
}

// function to move the drone right
void moveRight(int speed) {
    printf("Moving drone right at speed %d \n", speed);
}

// function to stop the drone 
void stop() {
    printf("Drone has stopped moving \n");
}

int main() {
    int speed = 10;

    // display instructions to the user
    printf("Welcome to Drone Remote Control! \n");
    printf("Use the following commands to control the drone: \n");
    printf("1. 'u <speed>' to move the drone up \n");
    printf("2. 'd <speed>' to move the drone down \n");
    printf("3. 'l <speed>' to move the drone left \n");
    printf("4. 'r <speed>' to move the drone right \n");
    printf("5. 's' to stop the drone \n");

    // loop to accept commands from the user
    while(1) {
        char command;
        scanf("%c", &command);

        // check for command
        if(command == 'u') {
            int speed;
            scanf("%d", &speed);
            moveUp(speed);
        }
        else if(command == 'd') {
            int speed;
            scanf("%d", &speed);
            moveDown(speed);
        }
        else if(command == 'l') {
            int speed;
            scanf("%d", &speed);
            moveLeft(speed);
        }
        else if(command == 'r') {
            int speed;
            scanf("%d", &speed);
            moveRight(speed);
        }
        else if(command == 's') {
            stop();
        }
        else {
            printf("Invalid command. Please try again. \n");
        }

        // clear input buffer
        fflush(stdin);
    }

    return 0;
}