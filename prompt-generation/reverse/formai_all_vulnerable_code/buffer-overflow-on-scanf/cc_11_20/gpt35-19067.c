//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cmd[20];
    int direction[4] = {0,0,0,0}; //Direction of drone: [up, down, left, right]
    int altitude = 0; //Altitude of drone
    int boost = 1; //Speed boost for drone
    int i;
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("To begin, please enter the commands as follows:\n");
    printf("Direction commands: 'up', 'down', 'left', 'right'\n");
    printf("Speed boost command: 'boost'\n");
    printf("Altitude commands: 'increase altitude', 'decrease altitude'\n");
    printf("To exit program, enter 'exit'\n");

    while(1) { //Loop until 'exit' command is entered
        printf("Enter command:");
        scanf("%s", cmd);

        if (strcmp(cmd, "up") == 0) { //Move drone up
            direction[0] = 1;
            direction[1] = 0;
            printf("Moving drone up...\n");
        }
        else if (strcmp(cmd, "down") == 0) { //Move drone down
            direction[0] = 0;
            direction[1] = 1;
            printf("Moving drone down...\n");
        }
        else if (strcmp(cmd, "left") == 0) { //Move drone left
            direction[2] = 1;
            direction[3] = 0;
            printf("Moving drone left...\n");
        }
        else if (strcmp(cmd, "right") == 0) {//Move drone right
            direction[2] = 0;
            direction[3] = 1;
            printf("Moving drone right...\n");
        }
        else if (strcmp(cmd, "boost") == 0) { //Speed boost
            boost += 1;
            printf("Drone speed boosted to %d!\n", boost);
        }
        else if (strcmp(cmd, "increase altitude") == 0) { //Increase altitude
            altitude += 10;
            printf("Drone altitude increased to %d meters\n", altitude);
        }
        else if (strcmp(cmd, "decrease altitude") == 0) { //Decrease altitude
            altitude -= 10;
            printf("Drone altitude decreased to %d meters\n", altitude);
        }
        else if (strcmp(cmd, "exit") == 0) { //Exit program
            printf("Exiting program...\n");
            return 0;
        }
        else { //Invalid command
            printf("Invalid command. Please try again.\n");
        }

        //Print current state of drone
        printf("Current state of drone:\n");
        printf("Direction: ");
        for (i = 0; i < 4; i++) {
            printf("%d ", direction[i]);
        }
        printf("\nAltitude: %d meters\n", altitude);
        printf("Speed boost: %d\n", boost);
    }

    return 0;
}