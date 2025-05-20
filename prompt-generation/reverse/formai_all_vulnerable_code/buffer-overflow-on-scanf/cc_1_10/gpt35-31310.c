//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random floor */
int getRandomFloor(int currentFloor, int maxFloor) {
    int floor = rand() % maxFloor + 1;
    while (floor == currentFloor) {
        floor = rand() % maxFloor + 1;
    }
    return floor;
}

/* Function to simulate elevator moving between floors */
void moveElevator(int currentFloor, int targetFloor) {
    printf("Elevator moving ");
    if (currentFloor < targetFloor) {
        printf("up ");
        for (int i = currentFloor + 1; i <= targetFloor; i++) {
            printf("%d ", i);
        }
    } else {
        printf("down ");
        for (int i = currentFloor - 1; i >= targetFloor; i--) {
            printf("%d ", i);
        }
    }
    printf("arrived at floor %d\n", targetFloor);
}

int main() {
    /* Initialize random seed */
    srand(time(NULL));

    /* Initialize elevator state */
    int currentFloor = 1;
    int maxFloor = 10;

    /* Loop to simulate elevator operation */
    while (1) {
        /* Prompt user for input */
        printf("Enter floor number or 0 to exit: ");
        int targetFloor;
        scanf("%d", &targetFloor);

        /* Check for exit condition */
        if (targetFloor == 0) {
            break;
        }

        /* Check for invalid floor input */
        if (targetFloor < 1 || targetFloor > maxFloor) {
            printf("Invalid floor number\n");
            continue;
        }

        /* Simulate elevator moving between floors */
        moveElevator(currentFloor, targetFloor);

        /* Update elevator state */
        currentFloor = targetFloor;

        /* Generate a random stop for the elevator */
        int nextFloor = getRandomFloor(currentFloor, maxFloor);
        moveElevator(currentFloor, nextFloor);
        currentFloor = nextFloor;
    }

    /* Exit program */
    printf("Exiting elevator simulation\n");
    return 0;
}