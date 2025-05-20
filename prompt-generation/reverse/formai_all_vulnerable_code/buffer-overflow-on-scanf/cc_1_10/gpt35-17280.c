//FormAI DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void moveForward(int steps);
void moveBackward(int steps);
void turnRight(int degrees);
void turnLeft(int degrees);

int main() {
    printf("Welcome to the Robot Movement Control Program!\n");
    
    char command[20];
    bool exitProgram = false;

    while(!exitProgram) {
        printf("\nEnter your command: ");
        scanf("%s", command);

        if(strcmp(command, "MF") == 0) {
            int numSteps;
            printf("Enter number of steps: ");
            scanf("%d", &numSteps);
            moveForward(numSteps);
        }
        else if(strcmp(command, "MB") == 0) {
            int numSteps;
            printf("Enter number of steps: ");
            scanf("%d", &numSteps);
            moveBackward(numSteps);
        }
        else if(strcmp(command, "TR") == 0) {
            int degrees;
            printf("Enter degree to turn right: ");
            scanf("%d", &degrees);
            turnRight(degrees);
        }
        else if(strcmp(command, "TL") == 0) {
            int degrees;
            printf("Enter degree to turn left: ");
            scanf("%d", &degrees);
            turnLeft(degrees);
        }
        else if(strcmp(command, "EXIT") == 0) {
            exitProgram = true;
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }

    printf("\nThank you for using the Robot Movement Control Program!");
    return 0;
}

// Function definitions
void moveForward(int steps) {
    printf("Moving forward %d steps...\n", steps);
}

void moveBackward(int steps) {
    printf("Moving backward %d steps...\n", steps);
}

void turnRight(int degrees) {
    printf("Turning right %d degrees...\n", degrees);
}

void turnLeft(int degrees) {
    printf("Turning left %d degrees...\n", degrees);
}