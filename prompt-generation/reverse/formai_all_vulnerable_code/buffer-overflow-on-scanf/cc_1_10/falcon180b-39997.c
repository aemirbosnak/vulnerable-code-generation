//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 20
#define MAX_DESTINATIONS 20
#define MAX_WAIT_TIME 5

struct floor {
    int passengers;
    int destinations[MAX_DESTINATIONS];
};

struct elevator {
    int current_floor;
    int destination_floor;
    int wait_time;
    int number_of_passengers;
};

int main() {
    srand(time(NULL));

    struct elevator elevator;
    struct floor floors[MAX_FLOORS];

    for (int i = 0; i < MAX_FLOORS; i++) {
        floors[i].passengers = rand() % MAX_PASSENGERS;
    }

    int num_destinations;
    int dest_floors[MAX_DESTINATIONS];

    printf("Welcome to the Happy Elevator Simulation!\n");
    printf("How many destinations would you like to go to? ");
    scanf("%d", &num_destinations);

    for (int i = 0; i < num_destinations; i++) {
        printf("Enter the floor number for destination %d: ", i+1);
        scanf("%d", &dest_floors[i]);
    }

    elevator.current_floor = rand() % MAX_FLOORS;
    elevator.destination_floor = dest_floors[0];
    elevator.wait_time = rand() % MAX_WAIT_TIME;
    elevator.number_of_passengers = 0;

    while (1) {
        system("clear");
        printf("Current floor: %d\n", elevator.current_floor);
        printf("Destination floor: %d\n", elevator.destination_floor);
        printf("Wait time: %d seconds\n", elevator.wait_time);
        printf("Number of passengers: %d\n", elevator.number_of_passengers);

        if (elevator.current_floor == elevator.destination_floor) {
            printf("\nArrived at destination floor!\n");
            break;
        }

        if (elevator.wait_time > 0) {
            elevator.wait_time--;
            printf("\nWaiting...\n");
        } else {
            int next_floor = rand() % MAX_FLOORS;

            if (next_floor == elevator.destination_floor) {
                printf("\nArrived at destination floor!\n");
                break;
            }

            if (floors[next_floor].passengers + elevator.number_of_passengers <= MAX_PASSENGERS) {
                elevator.current_floor = next_floor;
                elevator.wait_time = rand() % MAX_WAIT_TIME;
            } else {
                printf("\nElevator is full. Skipping floor.\n");
            }
        }
    }

    return 0;
}