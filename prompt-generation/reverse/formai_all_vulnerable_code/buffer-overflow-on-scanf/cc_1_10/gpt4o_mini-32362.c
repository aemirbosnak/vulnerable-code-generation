//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define NUM_ELEVATORS 2

typedef struct {
    int current_floor;
    int target_floor;
    int id;
    int moving_up;
} Elevator;

Elevator elevators[NUM_ELEVATORS];

void initialize_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0; // Start at ground floor
        elevators[i].target_floor = -1; // No target
        elevators[i].id = i + 1; // Elevator ID
        elevators[i].moving_up = 1; // Assume moving up initially
    }
}

void request_elevator(int floor) {
    printf("Elevator requested at floor %d\n", floor);
    int selected_elevator = -1;
    int min_distance = MAX_FLOORS;

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        int distance = abs(elevators[i].current_floor - floor);
        if (distance < min_distance) {
            min_distance = distance;
            selected_elevator = i;
        }
    }

    if (selected_elevator != -1) {
        elevators[selected_elevator].target_floor = floor;
        printf("Elevator %d assigned to floor %d\n", selected_elevator + 1, floor);
    }
}

void move_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].target_floor != -1) {
            if (elevators[i].current_floor < elevators[i].target_floor) {
                elevators[i].current_floor++;
                elevators[i].moving_up = 1;
            } else if (elevators[i].current_floor > elevators[i].target_floor) {
                elevators[i].current_floor--;
                elevators[i].moving_up = 0;
            }

            printf("Elevator %d moving %s to floor %d\n", elevators[i].id,
                   elevators[i].moving_up ? "up" : "down", elevators[i].current_floor);

            if (elevators[i].current_floor == elevators[i].target_floor) {
                printf("Elevator %d arrived at floor %d\n", elevators[i].id, elevators[i].current_floor);
                elevators[i].target_floor = -1; // Reset target floor
            }
        }
    }
}

int main() {
    initialize_elevators();
    int action;

    while (1) {
        printf("\nElevator Simulation\n");
        printf("1. Request Elevator\n");
        printf("2. Move Elevators\n");
        printf("3. Exit\n");
        printf("Choose an action (1-3): ");
        scanf("%d", &action);

        switch (action) {
            case 1: {
                int floor;
                printf("Enter floor number (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                if (floor >= 0 && floor < MAX_FLOORS) {
                    request_elevator(floor);
                } else {
                    printf("Invalid floor number!\n");
                }
                break;
            }
            case 2:
                move_elevators();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid action!\n");
                break;
        }

        sleep(1); // Simulate time passing
    }

    return 0;
}