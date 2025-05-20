//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 8
#define MAX_WAIT_TIME 10

typedef struct {
    int id;
    int destination;
    int wait_time;
} Passenger;

typedef struct {
    int current_floor;
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers;
} Elevator;

void generate_passengers(Passenger passengers[], int num_passengers) {
    int i;
    for (i = 0; i < num_passengers; i++) {
        passengers[i].id = i + 1;
        passengers[i].destination = rand() % MAX_FLOORS + 1;
        passengers[i].wait_time = rand() % MAX_WAIT_TIME + 1;
    }
}

void print_passengers(Passenger passengers[], int num_passengers) {
    int i;
    for (i = 0; i < num_passengers; i++) {
        printf("Passenger %d is going to floor %d and has been waiting for %d seconds.\n", passengers[i].id, passengers[i].destination, passengers[i].wait_time);
    }
}

void move_elevator(Elevator* elevator, int direction) {
    if (direction == 1 && elevator->current_floor < MAX_FLOORS) {
        elevator->current_floor++;
    } else if (direction == -1 && elevator->current_floor > 1) {
        elevator->current_floor--;
    }
}

int main() {
    srand(time(NULL));

    Passenger passengers[MAX_PASSENGERS];
    generate_passengers(passengers, MAX_PASSENGERS);

    Elevator elevator;
    elevator.current_floor = 1;
    elevator.num_passengers = 0;

    while (1) {
        system("clear");
        printf("Current floor: %d\n", elevator.current_floor);

        if (elevator.num_passengers == 0) {
            printf("No passengers in the elevator.\n");
        } else {
            printf("Passengers in the elevator:\n");
            print_passengers(elevator.passengers, elevator.num_passengers);
        }

        int choice;
        printf("Enter your choice:\n1. Call the elevator\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (elevator.num_passengers == MAX_PASSENGERS) {
                printf("Elevator is full, please wait.\n");
            } else {
                int id = elevator.num_passengers + 1;
                elevator.passengers[elevator.num_passengers].id = id;
                elevator.passengers[elevator.num_passengers].destination = rand() % MAX_FLOORS + 1;
                elevator.passengers[elevator.num_passengers].wait_time = rand() % MAX_WAIT_TIME + 1;
                elevator.num_passengers++;
            }
        } else if (choice == 2) {
            break;
        }
    }

    return 0;
}