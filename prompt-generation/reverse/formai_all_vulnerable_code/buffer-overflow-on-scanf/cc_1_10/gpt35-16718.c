//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// define constants for movement directions    
#define FORWARD 1
#define BACKWARD 0
#define LEFT 2
#define RIGHT 3

// define function to handle robot movement
void moveRobot(int direction, int duration){
    if(direction == FORWARD){
        printf("Moving forward for %d seconds...\n", duration);
        // code to move robot forward
        sleep(duration);
    }
    else if(direction == BACKWARD){
        printf("Moving backward for %d seconds...\n", duration);
        // code to move robot backward
        sleep(duration);
    }
    else if(direction == LEFT){
        printf("Turning left and moving for %d seconds...\n", duration);
        // code to turn robot left and move forward
        sleep(duration);
    }
    else if(direction == RIGHT){
        printf("Turning right and moving for %d seconds...\n", duration);
        // code to turn robot right and move forward
        sleep(duration);
    }
    else{
        printf("Invalid movement direction!\n");
    }
}

int main(){
    int direction;
    int duration;
    
    // Ask user for input
    printf("Enter the movement direction (1: Forward, 0: Backward, 2: Left, 3: Right):\n");
    scanf("%d", &direction);
    printf("Enter the movement duration (in seconds):\n");
    scanf("%d", &duration);

    // Call function to move robot
    moveRobot(direction, duration);

    // End program
    printf("Program ended.\n");

    return 0;
}