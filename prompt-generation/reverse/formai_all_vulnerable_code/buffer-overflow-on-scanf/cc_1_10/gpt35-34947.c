//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to get random number between min and max
int getRandomNumber(int min, int max) 
{
    return (rand() % (max - min + 1)) + min;
}

int main() 
{
    // set the seed for rand() function to generate random numbers
    srand(time(NULL)); 

    int x = 0, y = 0;
    char ch;
    bool isMoving = false;

    while (true) {
        printf("\nCurrent Position: (%d, %d)", x, y);

        // ask the user for input
        printf("\nPress W, A, S or D to move the vehicle. Press Q to quit: ");
        scanf(" %c", &ch);

        // check for valid input
        if (ch == 'W' || ch == 'A' || ch == 'S' || ch == 'D') {
            isMoving = true;
        } else if (ch == 'Q') {
            printf("Exiting the program...\n");
            break;
        } else {
            printf("Invalid input. Try again.\n");
            continue;
        }

        switch(ch) {
            case 'W':
                y += getRandomNumber(1, 3); // move up
                break;
            case 'A':
                x -= getRandomNumber(1, 3); // move left
                break;
            case 'S':
                y -= getRandomNumber(1, 3); // move down
                break;
            case 'D':
                x += getRandomNumber(1, 3); // move right
                break;
        }

        if (isMoving) {
            isMoving = false;
            printf("Vehicle is moving...\n\n");
        }
    }

    return 0;
}