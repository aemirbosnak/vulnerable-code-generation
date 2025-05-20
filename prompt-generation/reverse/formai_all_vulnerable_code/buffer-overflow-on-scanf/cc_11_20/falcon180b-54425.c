//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 20
#define MAX_DESTINATIONS 50
#define MAX_ELEVATORS 5
#define MAX_WAIT_TIME 10

typedef struct {
    int floor;
    int destination;
} passenger;

typedef struct {
    int current_floor;
    int direction;
} elevator;

int main() {
    srand(time(NULL));
    int num_elevators, num_passengers, num_destinations;
    printf("Enter the number of elevators: ");
    scanf("%d", &num_elevators);
    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);
    printf("Enter the number of destinations: ");
    scanf("%d", &num_destinations);

    // Initialize elevators
    elevator elevators[MAX_ELEVATORS];
    for (int i = 0; i < num_elevators; i++) {
        elevators[i].current_floor = rand() % MAX_FLOORS + 1;
        elevators[i].direction = rand() % 2 == 0? 1 : -1; // Randomly assign direction
    }

    // Initialize passengers
    passenger passengers[MAX_PASSENGERS];
    for (int i = 0; i < num_passengers; i++) {
        passengers[i].floor = rand() % MAX_FLOORS + 1;
        passengers[i].destination = rand() % MAX_DESTINATIONS + 1;
    }

    // Simulate elevator movement
    int current_time = 0;
    while (1) {
        for (int i = 0; i < num_elevators; i++) {
            elevators[i].current_floor += elevators[i].direction;
            if (elevators[i].current_floor <= 0 || elevators[i].current_floor >= MAX_FLOORS) {
                elevators[i].direction *= -1; // Reverse direction when reaching end of shaft
            }
        }

        for (int i = 0; i < num_passengers; i++) {
            if (passengers[i].floor == elevators[0].current_floor) {
                elevators[0].current_floor = passengers[i].destination;
            }
        }

        current_time++;
        if (current_time >= MAX_WAIT_TIME) {
            break;
        }
    }

    // Print results
    printf("Final destinations:\n");
    for (int i = 0; i < num_passengers; i++) {
        printf("%d: %d\n", i+1, passengers[i].destination);
    }

    return 0;
}