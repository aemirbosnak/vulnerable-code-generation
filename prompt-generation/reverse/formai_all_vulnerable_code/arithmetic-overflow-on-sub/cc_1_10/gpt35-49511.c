//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FLOORS 10
#define ELEVATORS 3

typedef struct Elevator {
    int id;
    int current_floor;
    int direction;
    int start_floor;
    int end_floor;
    int occupied;
} elevator_t;

elevator_t elevators[ELEVATORS];

void init_elevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].id = i+1;
        elevators[i].current_floor = (rand() % FLOORS) + 1;
        elevators[i].start_floor = 0;
        elevators[i].end_floor = 0;
        elevators[i].occupied = 0;
        elevators[i].direction = 0; // 0 - stationary, 1 - up, -1 - down
    }
}

void display_elevator_status() {
    for (int i = 0; i < ELEVATORS; i++) {
        char *direction = "Stationary";
        if (elevators[i].direction == 1) {
            direction = "Up";
        } else if (elevators[i].direction == -1) {
            direction = "Down";
        }
        printf("Elevator %d: Floor %d, %s\n", elevators[i].id, elevators[i].current_floor, direction);
    }
}

void move_elevator(elevator_t *elevator) {
    if (elevator->direction == 1) {
        elevator->current_floor++;
    } else if (elevator->direction == -1) {
        elevator->current_floor--;
    }
}

void update_elevator_direction(elevator_t *elevator) {
    if (elevator->current_floor == elevator->start_floor) {
        elevator->direction = 1;
    } else if (elevator->current_floor == elevator->end_floor) {
        elevator->direction = -1;
    }
}

void move_elevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevators[i].occupied) {
            if (elevators[i].current_floor == elevators[i].end_floor) {
                elevators[i].occupied = 0;
                elevators[i].start_floor = 0;
                elevators[i].end_floor = 0;
                elevators[i].direction = 0;
            } else {
                move_elevator(&elevators[i]);
                update_elevator_direction(&elevators[i]);
            }
        }
    }
}

int request_elevator(int floor) {
    int closest_elevator = -1;
    int distance = FLOORS + 1;
    for (int i = 0; i < ELEVATORS; i++) {
        if (!elevators[i].occupied) {
            int temp_distance = abs(elevators[i].current_floor - floor);
            if (temp_distance < distance) {
                distance = temp_distance;
                closest_elevator = i;
            }
        }
    }
    return closest_elevator;
}

void request_floor(int elevator, int floor) {
    elevators[elevator].end_floor = floor;
    elevators[elevator].occupied = 1;
    if (elevators[elevator].current_floor < floor) {
        elevators[elevator].direction = 1;
        elevators[elevator].start_floor = elevators[elevator].current_floor;
    } else {
        elevators[elevator].direction = -1;
        elevators[elevator].start_floor = elevators[elevator].current_floor;
    }
}

int main() {
    srand(time(NULL));
    init_elevators();
    int option, floor, elevator;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Request elevator\n");
        printf("2. Request floor\n");
        printf("3. Display elevator status\n");
        printf("4. Quit\n");
        printf("Option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter the floor where you are now: ");
                scanf("%d", &floor);

                elevator = request_elevator(floor);

                if (elevator == -1) {
                    printf("All elevators are currently in use. Please wait.\n");
                } else {
                    printf("Elevator %d is on its way to floor %d.\n", elevators[elevator].id, floor);
                }
                break;
            case 2:
                printf("Enter the elevator ID: ");
                scanf("%d", &elevator);
                printf("Enter the floor number where you want to go: ");
                scanf("%d", &floor);

                if (elevator <= 0 || elevator > ELEVATORS) {
                    printf("Invalid elevator ID. Please try again.\n");
                } else {
                    request_floor(elevator - 1, floor);
                    printf("Elevator %d is on its way to floor %d.\n", elevator, floor);
                }
                break;
            case 3:
                display_elevator_status();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        move_elevators();
        sleep(1);
        system("clear");
    }
    return 0;
}