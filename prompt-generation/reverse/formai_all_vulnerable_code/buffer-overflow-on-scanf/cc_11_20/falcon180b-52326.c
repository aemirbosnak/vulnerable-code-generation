//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define MAX_PASSENGERS 10
#define MAX_WAIT_TIME 30

typedef struct {
    int floor;
    int direction;
    int passengers;
} Elevator;

int main() {
    int num_passengers = 0;
    int wait_time = 0;
    int current_floor = 0;
    int destination_floor = 0;
    int elevator_floor = 0;
    int elevator_direction = 0;
    int elevator_passengers = 0;
    int i, j;
    Elevator elevator[NUM_ELEVATORS];

    // Initialize elevators
    for (i = 0; i < NUM_ELEVATORS; i++) {
        elevator[i].floor = rand() % NUM_FLOORS;
        elevator[i].direction = rand() % 2;
        elevator[i].passengers = 0;
    }

    while (1) {
        printf("Current Floor: %d\n", current_floor);
        printf("Number of Passengers: %d\n", num_passengers);
        printf("Wait Time: %d seconds\n", wait_time);
        printf("Enter Destination Floor: ");
        scanf("%d", &destination_floor);

        for (i = 0; i < NUM_ELEVATORS; i++) {
            if (elevator[i].floor == destination_floor) {
                elevator_floor = elevator[i].floor;
                elevator_direction = elevator[i].direction;
                elevator_passengers = elevator[i].passengers;
                break;
            }
        }

        if (i == NUM_ELEVATORS) {
            printf("No elevator available.\n");
            continue;
        }

        if (elevator_passengers >= MAX_PASSENGERS) {
            printf("Elevator is full.\n");
            continue;
        }

        if (elevator_direction == 0) {
            if (destination_floor > elevator_floor) {
                elevator_floor++;
            } else {
                elevator_floor--;
            }
        } else {
            if (destination_floor > elevator_floor) {
                elevator_floor--;
            } else {
                elevator_floor++;
            }
        }

        if (elevator_floor == current_floor) {
            printf("Elevator has arrived.\n");
            elevator[i].passengers++;
            num_passengers++;
        } else {
            printf("Elevator is on its way.\n");
            wait_time = rand() % MAX_WAIT_TIME;
        }

        current_floor = destination_floor;
    }

    return 0;
}