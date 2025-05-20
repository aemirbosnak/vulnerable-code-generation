//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEVATORS 3
#define MAX_FLOORS 5

typedef struct {
    int floor;
    int elevator;
} Elevator;

Elevator elevators[MAX_ELEVATORS] = {
    {0, 0},
    {1, 0},
    {2, 0}
};

int floors[MAX_FLOORS] = {
    0,
    1,
    2,
    3,
    4
};

int main() {
    srand(time(NULL));

    int currentFloor = 0;
    int currentElevator = 0;
    int nextFloor = 0;

    while (1) {
        int i;
        for (i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i].floor == currentFloor) {
                currentElevator = i;
                break;
            }
        }

        printf("Current Floor: %d\n", currentFloor);
        printf("Current Elevator: %d\n", currentElevator);

        nextFloor = (currentFloor + 1) % MAX_FLOORS;
        elevators[currentElevator].floor = nextFloor;

        printf("Next Floor: %d\n", nextFloor);

        int userInput;
        printf("Enter the number of the floor you want to go to: ");
        scanf("%d", &userInput);

        while (userInput < 0 || userInput > MAX_FLOORS) {
            printf("Invalid floor number. Please try again: ");
            scanf("%d", &userInput);
        }

        elevators[currentElevator].floor = userInput;
        printf("You have reached the %dth floor.\n", userInput);
    }

    return 0;
}