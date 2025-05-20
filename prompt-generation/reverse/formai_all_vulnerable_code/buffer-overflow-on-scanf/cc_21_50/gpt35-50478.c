//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // set initial position of the RC car
    int xPos = 0;
    int yPos = 0;

    // set initial direction of the RC car
    int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west

    // set up boundary
    int boundary = 10;

    // start of simulation loop
    while (1) {
        // output current position and direction of car
        printf("RC Car is currently at (%d,%d) and facing %s\n", xPos, yPos, (direction == 0 ? "North" : (direction == 1 ? "East" : (direction == 2 ? "South" : "West"))));

        // ask user for command
        char command;
        printf("Enter Command (F)orward, (L)eft, (R)ight, or (Q)uit: ");
        scanf(" %c", &command);

        if (command == 'F' || command == 'f') {
            // move the car forward
            switch (direction) {
                case 0:
                    // move north
                    yPos++;
                    break;
                case 1:
                    // move east
                    xPos++;
                    break;
                case 2:
                    // move south
                    yPos--;
                    break;
                case 3:
                    // move west
                    xPos--;
                    break;
            }

            // check if out of bounds
            if (xPos < -boundary || xPos > boundary || yPos < -boundary || yPos > boundary) {
                printf("Out of bounds! Game Over.\n");
                break;
            }
        }
        else if (command == 'L' || command == 'l') {
            // turn the car left
            direction = (direction - 1 + 4) % 4;
        }
        else if (command == 'R' || command == 'r') {
            // turn the car right
            direction = (direction + 1) % 4;
        }
        else if (command == 'Q' || command == 'q') {
            // end simulation
            printf("Simulation Ended by User.\n");
            break;
        }
        else {
            // invalid command
            printf("Invalid Command.\n");
        }

        // randomly spawn obstacles
        int obstacleX = rand() % (2 * boundary + 1) - boundary;
        int obstacleY = rand() % (2 * boundary + 1) - boundary;

        // check if RC car hits obstacle
        if (xPos == obstacleX && yPos == obstacleY) {
            printf("Oops! You hit an obstacle at (%d,%d).\n", obstacleX, obstacleY);
            break;
        }
    }

    return 0;
}