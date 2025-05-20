//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_FLOORS 10
#define MAX_PASSENGERS 4

typedef struct {
    int current_floor;
    int destination_floor;
    int passenger_count;
} Elevator;

typedef struct {
    int floor;
    int direction;
} Request;

void elevator_move(Elevator* elevator, int floor) {
    if (elevator->current_floor == floor) {
        printf("Elevator is already on floor %d\n", floor);
        return;
    }

    if (elevator->current_floor > floor) {
        elevator->current_floor--;
    } else {
        elevator->current_floor++;
    }

    printf("Elevator is now on floor %d\n", elevator->current_floor);
}

void elevator_request(Elevator* elevator, Request* request) {
    if (request->floor < 0 || request->floor > MAX_FLOORS) {
        printf("Invalid floor request\n");
        return;
    }

    if (elevator->current_floor == request->floor) {
        printf("Elevator is already on floor %d\n", request->floor);
        return;
    }

    elevator_move(elevator, request->floor);

    if (request->direction == 1) {
        elevator->destination_floor = request->floor;
    } else {
        elevator->destination_floor = -1;
    }
}

void elevator_simulate(Elevator* elevator, int num_passengers, int num_floors) {
    srand(time(NULL));

    for (int i = 0; i < num_passengers; i++) {
        Request request;
        request.floor = rand() % num_floors;
        request.direction = rand() % 2;
        elevator_request(elevator, &request);
    }
}

int main() {
    Elevator elevator;
    elevator.current_floor = 0;
    elevator.destination_floor = -1;
    elevator.passenger_count = 0;

    int num_passengers, num_floors;
    printf("Enter number of passengers: ");
    scanf("%d", &num_passengers);

    printf("Enter number of floors: ");
    scanf("%d", &num_floors);

    elevator_simulate(&elevator, num_passengers, num_floors);

    return 0;
}