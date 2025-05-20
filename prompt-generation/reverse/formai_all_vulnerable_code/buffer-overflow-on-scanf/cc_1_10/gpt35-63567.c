//FormAI DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Robot movement control program */

/* Define functions for robot movement */
void moveForward(int distance);
void moveBackward(int distance);
void turnLeft();
void turnRight();

/* Define function to get user's next move */
void getNextMove(char* move);

int main()
{
    int distance;
    char move[10];

    /* Welcome message */
    printf("Welcome to the Robot Movement Control Program!\n");

    /* Main program loop */
    while(1) {

        /* Get user's next move */
        getNextMove(move);

        /* Check user's move */
        if(strcmp(move, "forward") == 0) {
            /* Get distance */
            printf("Enter distance (in cm): ");
            scanf("%d", &distance);

            /* Move forward */
            moveForward(distance);
        }
        else if(strcmp(move, "backward") == 0) {
            /* Get distance */
            printf("Enter distance (in cm): ");
            scanf("%d", &distance);

            /* Move backward */
            moveBackward(distance);
        }
        else if(strcmp(move, "left") == 0) {
            /* Turn left */
            turnLeft();
        }
        else if(strcmp(move, "right") == 0) {
            /* Turn right */
            turnRight();
        }
        else if(strcmp(move, "exit") == 0) {
            /* Exit program */
            printf("Exiting Robot Movement Control Program ...\n");
            exit(0);
        }
        else {
            /* Invalid move */
            printf("Invalid move! Please try again.\n");
        }

        /* Wait for user to acknowledge move */
        printf("Press Enter to continue ...");
        getchar();
        getchar();
    }

    return 0;
}

/* Function to move robot forward */
void moveForward(int distance) {
    printf("Moving robot forward %d cm ...\n", distance);
}

/* Function to move robot backward */
void moveBackward(int distance) {
    printf("Moving robot backward %d cm ...\n", distance);
}

/* Function to turn robot left */
void turnLeft() {
    printf("Turning robot left ...\n");
}

/* Function to turn robot right */
void turnRight() {
    printf("Turning robot right ...\n");
}

/* Function to get user's next move */
void getNextMove(char* move) {
    printf("Enter next move (forward/backward/left/right/exit): ");
    fgets(move, 10, stdin);
    move[strcspn(move, "\r\n")] = 0; // remove newline character
}