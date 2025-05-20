//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ALTITUDE_STEP 10
#define DIRECTION_STEP 5

// Function to move the drone up or down
void move(int direction) {
    int currentAltitude = rand() % 100;
    if (direction == 'u') {
        currentAltitude += ALTITUDE_STEP;
    } else if (direction == 'd') {
        currentAltitude -= ALTITUDE_STEP;
    }
    printf("Current altitude: %d\n", currentAltitude);
}

// Function to turn the drone left or right
void turn(int direction) {
    int currentDirection = rand() % 360;
    if (direction == 'l') {
        currentDirection += DIRECTION_STEP;
    } else if (direction == 'r') {
        currentDirection -= DIRECTION_STEP;
    }
    printf("Current direction: %d\n", currentDirection);
}

// Main function to control the drone
int main() {
    int direction;
    int altitude;
    srand(time(NULL));
    while (1) {
        printf("Enter a direction (u/d/l/r): ");
        scanf("%s", &direction);
        switch (direction) {
            case 'u':
            case 'd':
            case 'l':
            case 'r':
                break;
            default:
                printf("Invalid direction. Please enter again.\n");
                break;
        }
        move(direction);
        turn(direction);
    }
    return 0;
}