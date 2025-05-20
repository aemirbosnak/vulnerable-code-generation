//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Starting position of the vehicle
int x = 0;
int y = 0;
char direction = 'N';

// Function to move the vehicle forward
void moveForward(){
    if (direction == 'N'){
        y++;
    }
    else if (direction == 'S'){
        y--;
    }
    else if (direction == 'E'){
        x++;
    }
    else if (direction == 'W'){
        x--;
    }
}

// Function to move the vehicle backward
void moveBackward(){
    if (direction == 'N'){
        y--;
    }
    else if (direction == 'S'){
        y++;
    }
    else if (direction == 'E'){
        x--;
    }
    else if (direction == 'W'){
        x++;
    }
}

// Function to turn the vehicle to the left
void turnLeft(){
    if (direction == 'N'){
        direction = 'W';
    }
    else if (direction == 'S'){
        direction = 'E';
    }
    else if (direction == 'E'){
        direction = 'N';
    }
    else if (direction == 'W'){
        direction = 'S';
    }
}

// Function to turn the vehicle to the right
void turnRight(){
    if (direction == 'N'){
        direction = 'E';
    }
    else if (direction == 'S'){
        direction = 'W';
    }
    else if (direction == 'E'){
        direction = 'S';
    }
    else if (direction == 'W'){
        direction = 'N';
    }
}

// Main function to execute the program
int main(){

    // Display starting position and direction of the vehicle
    printf("Vehicle starting at (%d,%d) facing %c.\n",x,y,direction);

    // Get user input to control vehicle movement
    char input;
    printf("Use WASD keys to move the vehicle. Press q to quit.\n");
    while(1){
        scanf(" %c", &input);

        if (input == 'w' || input == 'W'){
            moveForward();
        }
        else if(input == 's' || input == 'S'){
            moveBackward();
        }
        else if(input == 'a' || input == 'A'){
            turnLeft();
        }
        else if(input == 'd' || input == 'D'){
            turnRight();
        }
        else if(input == 'q' || input == 'Q'){
            exit(0);
        }

        // Display current position and direction of the vehicle
        printf("Vehicle at (%d,%d) facing %c.\n", x, y, direction);
    }

    // Exit program
    return 0;
}