//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUILDING_HEIGHT 10
#define ELEVATOR_SPEED 1
#define NUM_ELEVATORS 3
#define ELEVATOR_CAPACITY 4

typedef struct {
    int floor;
    int direction;
} elevator;

elevator elevators[NUM_ELEVATORS];

void initialize_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = 0;
    }
}

void move_elevator(elevator *elevator) {
    if (elevator->direction == 1) {
        elevator->floor++;
    } else {
        elevator->floor--;
    }
}

int get_closest_elevator(int floor) {
    int closest_elevator = -1;
    int min_distance = BUILDING_HEIGHT;

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].floor == floor) {
            return i;
        }

        int distance = abs(elevators[i].floor - floor);
        if (distance < min_distance) {
            min_distance = distance;
            closest_elevator = i;
        }
    }

    return closest_elevator;
}

void request_elevator(int floor, int elevator_number) {
    elevators[elevator_number].floor = floor;
    elevators[elevator_number].direction = 0;
}

void main() {
    srand(time(NULL));
    initialize_elevators();

    int num_people = rand() % 10 + 1;
    int *people_floors = malloc(num_people * sizeof(int));

    for (int i = 0; i < num_people; i++) {
        people_floors[i] = rand() % BUILDING_HEIGHT + 1;
    }

    for (int i = 0; i < num_people; i++) {
        int closest_elevator = get_closest_elevator(people_floors[i]);
        request_elevator(people_floors[i], closest_elevator);
        move_elevator(&elevators[closest_elevator]);

        if (elevators[closest_elevator].floor == people_floors[i]) {
            printf("Elevator %d picked up person on floor %d\n", closest_elevator + 1, people_floors[i]);
        }
    }

    for (int i = 0; i < num_people; i++) {
        int closest_elevator = get_closest_elevator(people_floors[i]);
        request_elevator(people_floors[i], closest_elevator);
        move_elevator(&elevators[closest_elevator]);

        if (elevators[closest_elevator].floor == people_floors[i]) {
            printf("Elevator %d dropped off person on floor %d\n", closest_elevator + 1, people_floors[i]);
        }
    }

    free(people_floors);
}