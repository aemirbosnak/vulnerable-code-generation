//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int floor;
    int destination;
    int status;
} elevator;

elevator* create_elevator(int id, int floor) {
    elevator* new_elevator = (elevator*) malloc(sizeof(elevator));
    new_elevator->id = id;
    new_elevator->floor = floor;
    new_elevator->destination = 0;
    new_elevator->status = 0;
    return new_elevator;
}

void print_elevator(elevator* elevator) {
    printf("Elevator %d is on floor %d and its status is %d\n", elevator->id, elevator->floor, elevator->status);
}

void simulate_elevator(elevator* elevator, int num_floors) {
    int passengers = 0;
    elevator->status = 1;
    while (elevator->status == 1) {
        printf("Elevator %d is moving...\n", elevator->id);
        sleep(1);
        if (elevator->destination!= 0 && elevator->floor == elevator->destination) {
            elevator->status = 0;
            passengers = 0;
        } else if (elevator->destination == 0) {
            elevator->destination = rand() % num_floors + 1;
            printf("Elevator %d is going to floor %d\n", elevator->id, elevator->destination);
        } else {
            if (passengers == 0) {
                printf("Elevator %d is waiting for passengers on floor %d\n", elevator->id, elevator->floor);
            } else {
                printf("Elevator %d is carrying %d passengers on floor %d\n", elevator->id, passengers, elevator->floor);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int num_floors = 10;
    elevator* elevator1 = create_elevator(1, 1);
    elevator* elevator2 = create_elevator(2, 10);
    simulate_elevator(elevator1, num_floors);
    simulate_elevator(elevator2, num_floors);
    return 0;
}