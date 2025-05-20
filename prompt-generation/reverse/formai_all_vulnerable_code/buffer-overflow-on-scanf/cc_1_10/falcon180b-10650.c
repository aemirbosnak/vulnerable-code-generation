//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 4

typedef struct {
    int floor;
    int direction;
    int speed;
} Elevator;

Elevator elevators[MAX_ELEVATORS];
int num_elevators;

void init_elevators() {
    srand(time(NULL));
    num_elevators = rand() % MAX_ELEVATORS + 1;
    for (int i = 0; i < num_elevators; i++) {
        elevators[i].floor = rand() % MAX_FLOORS;
        elevators[i].direction = rand() % 2;
        elevators[i].speed = rand() % 3 + 1;
    }
}

void print_elevators() {
    for (int i = 0; i < num_elevators; i++) {
        printf("Elevator %d: floor %d, direction %d, speed %d\n", i, elevators[i].floor, elevators[i].direction, elevators[i].speed);
    }
}

int main() {
    init_elevators();
    print_elevators();

    int num_passengers;
    int destination_floor;

    while (1) {
        printf("Enter number of passengers: ");
        scanf("%d", &num_passengers);

        printf("Enter destination floor: ");
        scanf("%d", &destination_floor);

        int elevator_index = -1;
        for (int i = 0; i < num_elevators; i++) {
            if (elevators[i].floor == destination_floor) {
                elevator_index = i;
                break;
            }
        }

        if (elevator_index == -1) {
            printf("No elevator at destination floor.\n");
        } else {
            elevators[elevator_index].floor = destination_floor;
            elevators[elevator_index].direction = (elevators[elevator_index].floor > elevators[elevator_index].speed)? 1 : -1;
        }
    }

    return 0;
}