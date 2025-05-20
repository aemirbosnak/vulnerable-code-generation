//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSENGERS 10
#define MAX_FLOORS 5

typedef struct {
    int destination;
    int floor;
    char name[20];
} Passenger;

typedef struct {
    Passenger passengers[MAX_PASSENGERS];
    int passenger_count;
    int floor_count;
    int current_floor;
    int direction;
    int queue_size;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = 0;
    elevator->queue_size = 0;
    elevator->floor_count = 0;
    elevator->passenger_count = 0;
}

void print_elevator_status(Elevator *elevator) {
    printf("Current floor: %d\n", elevator->current_floor);
    printf("Passengers: ");
    for (int i = 0; i < elevator->passenger_count; i++) {
        printf("%s ", elevator->passengers[i].name);
    }
    printf("\n");
    printf("Destination: ");
    for (int i = 0; i < elevator->floor_count; i++) {
        printf("%d ", elevator->passengers[i].destination);
    }
    printf("\n");
    printf("Direction: %d\n", elevator->direction);
}

void enqueue(Elevator *elevator, int destination, int floor) {
    if (elevator->queue_size < MAX_PASSENGERS) {
        elevator->passengers[elevator->queue_size].destination = destination;
        elevator->passengers[elevator->queue_size].floor = floor;
        elevator->queue_size++;
    }
}

void dequeue(Elevator *elevator) {
    if (elevator->queue_size > 0) {
        elevator->queue_size--;
    }
}

void move_elevator(Elevator *elevator, int floor) {
    if (floor < elevator->floor_count) {
        elevator->current_floor = floor;
        elevator->direction = 0;
        for (int i = 0; i < elevator->passenger_count; i++) {
            if (elevator->passengers[i].destination == floor) {
                printf("Passenger %s has arrived at floor %d\n", elevator->passengers[i].name, floor);
                dequeue(elevator);
                elevator->floor_count--;
                elevator->passenger_count--;
            }
        }
    } else if (floor > elevator->current_floor) {
        elevator->current_floor = floor;
        elevator->direction = 1;
    } else if (floor < elevator->current_floor) {
        elevator->current_floor = floor;
        elevator->direction = -1;
    }
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    printf("Enter the floors that the elevator should stop at (comma-separated): ");
    char floors[MAX_FLOORS][20];
    for (int i = 0; i < MAX_FLOORS; i++) {
        fgets(floors[i], 20, stdin);
    }

    for (int i = 0; i < MAX_FLOORS; i++) {
        sscanf(floors[i], "%d", &elevator.passengers[i].destination);
        elevator.floor_count++;
    }

    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("Enter the name of passenger %d: ", i + 1);
        fgets(elevator.passengers[i].name, 20, stdin);
    }

    print_elevator_status(&elevator);
    printf("Enter the floor where you want the elevator to stop: ");
    scanf("%d", &elevator.current_floor);

    while (elevator.current_floor < elevator.floor_count) {
        printf("Enter the floor where you want the elevator to stop: ");
        scanf("%d", &elevator.current_floor);
        move_elevator(&elevator, elevator.current_floor);
        print_elevator_status(&elevator);
    }

    return 0;
}