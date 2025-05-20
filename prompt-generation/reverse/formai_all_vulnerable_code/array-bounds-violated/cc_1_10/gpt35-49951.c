//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>

// constants
#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10

// function prototypes
void printStatus(int currentFloor, int numPassengers);
void printFloor(int floorNum);

int main() {
    // initialize variables
    int currentFloor = 1;
    int numPassengers = 0;
    int elevator[NUM_FLOORS] = {0};

    // main loop
    while (1) {
        // print current status
        printStatus(currentFloor, numPassengers);

        // wait for user input
        char input[10];
        fgets(input, 10, stdin);

        // check if user wants to exit
        if (input[0] == 'q') {
            break;
        }

        // check if user wants to go to a different floor
        if (input[0] == 'f') {
            int destFloor = input[1] - '0';
            if (destFloor > currentFloor && numPassengers < ELEVATOR_CAPACITY) {
                elevator[destFloor - 1]++;
                numPassengers++;
                printf("Elevator heading up to floor %d\n", destFloor);
                currentFloor = destFloor;
            } else {
                printf("Sorry, the elevator cannot go to that floor\n");
            }
        }

        // check if elevator has arrived at a floor
        if (elevator[currentFloor - 1] > 0) {
            printf("Elevator has arrived at floor %d\n", currentFloor);
            printf("%d passengers get off the elevator\n", elevator[currentFloor - 1]);
            numPassengers -= elevator[currentFloor - 1];
            elevator[currentFloor - 1] = 0;
        }

        // wait for a few seconds to simulate travel time
        for (int i = 0; i < 3; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");

        // move elevator up or down one floor
        if (numPassengers == 0) {
            // if nobody is in the elevator, pick a random floor to go to
            currentFloor += (rand() % 3) - 1;
        } else if (currentFloor == NUM_FLOORS) {
            // if at the top floor, go down
            currentFloor--;
        } else if (currentFloor == 1) {
            // if at the bottom floor, go up
            currentFloor++;
        } else {
            // otherwise, pick a random direction to go
            int direction = rand() % 2; // 0 = down, 1 = up
            if (direction == 0) {
                currentFloor--;
            } else {
                currentFloor++;
            }
        }
    }

    return 0;
}

void printStatus(int currentFloor, int numPassengers) {
    printf("===========================\n");
    printFloor(currentFloor);
    printf("Passengers: %d / %d\n", numPassengers, ELEVATOR_CAPACITY);
    printf("===========================\n");
}

void printFloor(int floorNum) {
    printf("|    |    |    |    |    |    |    |    |    |    |\n");
    if (floorNum == 1) {
        printf("| E  |    |    |    |    |    |    |    |    |    |\n");
    } else if (floorNum == 2) {
        printf("|    | E  |    |    |    |    |    |    |    |    |\n");
    } else if (floorNum == 3) {
        printf("|    |    | E  |    |    |    |    |    |    |    |\n");
    } else if (floorNum == 4) {
        printf("|    |    |    | E  |    |    |    |    |    |    |\n");
    } else if (floorNum == 5) {
        printf("|    |    |    |    | E  |    |    |    |    |    |\n");
    } else if (floorNum == 6) {
        printf("|    |    |    |    |    | E  |    |    |    |    |\n");
    } else if (floorNum == 7) {
        printf("|    |    |    |    |    |    | E  |    |    |    |\n");
    } else if (floorNum == 8) {
        printf("|    |    |    |    |    |    |    | E  |    |    |\n");
    } else if (floorNum == 9) {
        printf("|    |    |    |    |    |    |    |    | E  |    |\n");
    } else if (floorNum == 10) {
        printf("|    |    |    |    |    |    |    |    |    | E  |\n");
    }
    printf("|____|____|____|____|____|____|____|____|____|____|\n");
}