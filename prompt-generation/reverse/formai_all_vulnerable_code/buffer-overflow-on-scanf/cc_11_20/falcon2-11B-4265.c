//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 5
#define MAX_ELEVATORS 2

int main()
{
    int elevators[MAX_ELEVATORS];
    int floors[FLOORS];
    int floor;
    int direction;
    int elevator;
    int i;
    int j;
    int numFloors;

    srand(time(NULL));
    for (i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i] = rand() % (FLOORS - 1) + 1;
    }
    for (i = 0; i < FLOORS; i++) {
        floors[i] = rand() % (FLOORS - 1) + 1;
    }
    floor = rand() % (FLOORS - 1) + 1;
    elevator = rand() % MAX_ELEVATORS;

    printf("Elevator simulation started!\n");

    while (true) {
        for (i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i] == floor) {
                printf("Elevator %d is at floor %d\n", i + 1, floor);
                break;
            }
        }
        if (i == MAX_ELEVATORS) {
            printf("No elevators at floor %d\n", floor);
        }

        printf("Enter direction: UP or DOWN\n");
        scanf("%s", &direction);

        if (direction == 'U') {
            elevator++;
            if (elevator >= MAX_ELEVATORS) {
                elevator = 0;
            }
            elevators[elevator] = floor;
            printf("Elevator %d is moving to floor %d\n", elevator + 1, floor);
        } else if (direction == 'D') {
            elevator--;
            if (elevator < 0) {
                elevator = MAX_ELEVATORS - 1;
            }
            elevators[elevator] = floor;
            printf("Elevator %d is moving to floor %d\n", elevator + 1, floor);
        }

        for (i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i] == floor) {
                floor = rand() % (FLOORS - 1) + 1;
                break;
            }
        }
    }

    return 0;
}