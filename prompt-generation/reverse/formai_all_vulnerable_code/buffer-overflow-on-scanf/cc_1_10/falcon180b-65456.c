//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 20

typedef struct {
    int current_floor;
    int destination_floor;
    int passenger_count;
} Elevator;

void initialize_elevator(Elevator* elevator, int current_floor, int destination_floor, int passenger_count) {
    elevator->current_floor = current_floor;
    elevator->destination_floor = destination_floor;
    elevator->passenger_count = passenger_count;
}

void move_elevator(Elevator* elevator, int direction) {
    if (direction == 1 && elevator->current_floor < elevator->destination_floor) {
        elevator->current_floor++;
    } else if (direction == -1 && elevator->current_floor > elevator->destination_floor) {
        elevator->current_floor--;
    }
}

int main() {
    int floors[MAX_FLOORS] = {0};
    int passengers[MAX_PASSENGERS] = {0};
    int current_floor = 0;
    int destination_floor = 0;
    int passenger_count = 0;
    int choice = 0;

    while (1) {
        printf("Welcome to the elevator!\n");
        printf("Current floor: %d\n", current_floor);
        printf("Enter your destination floor: ");
        scanf("%d", &destination_floor);

        if (destination_floor < 0 || destination_floor >= MAX_FLOORS) {
            printf("Invalid floor!\n");
            continue;
        }

        printf("Enter the number of passengers: ");
        scanf("%d", &passenger_count);

        if (passenger_count > MAX_PASSENGERS) {
            printf("Too many passengers!\n");
            continue;
        }

        Elevator elevator;
        initialize_elevator(&elevator, current_floor, destination_floor, passenger_count);

        while (elevator.current_floor!= elevator.destination_floor) {
            printf("The elevator is moving...\n");
            move_elevator(&elevator, 1);
        }

        printf("You have reached your destination!\n");
        break;
    }

    return 0;
}