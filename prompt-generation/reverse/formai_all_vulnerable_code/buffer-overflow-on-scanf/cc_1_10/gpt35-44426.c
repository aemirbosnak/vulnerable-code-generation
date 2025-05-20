//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define macros for the range of movement
#define LEFT 1
#define RIGHT 2
#define FORWARD 3
#define BACKWARD 4

// Function to generate a random number from the range of movement
int generateRandomMovement() {
    int randomMovement = rand() % 4 + 1;
    return randomMovement;
}

// Function to control the robot movement based on the randomly generated number
void controlRobotMovement(int movement) {
    switch(movement) {
        case LEFT:
            printf("Robot is moving left\n");
            break;
        case RIGHT:
            printf("Robot is moving right\n");
            break;
        case FORWARD:
            printf("Robot is moving forward\n");
            break;
        case BACKWARD:
            printf("Robot is moving backward\n");
            break;
        default:
            printf("Error: Invalid movement generated\n");
            break;
    }
}

int main() {
    int i;
    srand(time(NULL)); // Set seed for random number generator
    
    printf("*** PARANOID MOVEMENT CONTROL PROGRAM FOR ROBOTS ***\n\n");
    printf("WARNING: The robot movement will be completely random and potentially dangerous.\n");
    printf("Only execute this program if you are prepared for the consequences.\n\n");
    
    printf("How many movements do you want the robot to make? ");
    int numMovements;
    scanf("%d", &numMovements);
    
    for(i = 0; i < numMovements; i++) {
        int movement = generateRandomMovement();
        controlRobotMovement(movement);
    }
    
    printf("\nPARANOID ROBOT MOVEMENT PROGRAM EXECUTED SUCCESSFULLY!\n");
    printf("Remember, you chose to run this program and assume all responsiblity for any damage caused.\n");
    
    return 0;
}