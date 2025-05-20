//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int floor;
    int capacity;
    int current_floor;
    int max_floor;
} elevator;

elevator* create_elevator(int floor, int capacity) {
    elevator* e = malloc(sizeof(elevator));
    if (e == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for elevator\n");
        exit(1);
    }

    e->floor = floor;
    e->capacity = capacity;
    e->current_floor = 0;
    e->max_floor = floor;

    return e;
}

void print_elevator_info(elevator* e) {
    printf("Elevator Information:\n");
    printf("Current floor: %d\n", e->current_floor);
    printf("Max floor: %d\n", e->max_floor);
}

int main() {
    elevator* e = create_elevator(10, 5);
    printf("Elevator %p created with floor %d and capacity %d\n", e, e->floor, e->capacity);
    print_elevator_info(e);

    int move_to_floor = 5;
    if (e->current_floor!= move_to_floor) {
        int passengers = 0;
        while (passengers < e->capacity) {
            printf("Enter passenger number: ");
            int passenger_num = scanf("%d", &passengers);
            if (passenger_num!= 0) {
                printf("Passenger %d entered the elevator\n", passengers);
                e->current_floor++;
                passengers++;
            } else {
                printf("Invalid input\n");
            }
        }
    } else {
        printf("Elevator is already on floor %d\n", move_to_floor);
    }

    printf("Elevator %p is now on floor %d\n", e, e->current_floor);
    print_elevator_info(e);

    free(e);
    return 0;
}