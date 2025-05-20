//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

// Constants declaration
#define MAX_FLOORS 20
#define MAX_ELEVATORS 5

// Struct declaration
typedef struct Elevator {
    int id;
    int current_floor;
    int destination_floor;
    bool is_move_up;
    bool is_idle;
} elevator;

// Function declaration
void init_elevators(elevator elevators[], int num_of_elevators);
void update_elevator_destination(elevator *e);
bool is_destination_reached(elevator e);

// Main function
int main() {
    // Variables declaration
    int total_floors, num_of_elevators, current_floor, destination_floor, selected_elevator_id;
    elevator elevators[MAX_ELEVATORS];

    // Get input from user
    printf("Enter total number of floors: ");
    scanf("%d", &total_floors);

    printf("Enter number of elevators: ");
    scanf("%d", &num_of_elevators);

    // Initialize elevators
    init_elevators(elevators, num_of_elevators);

    // Main loop
    while (true) {
        // Print elevator status
        printf("\n");
        printf("Elevator status:\n");
        for (int i = 0; i < num_of_elevators; i++) {
            printf("Elevator %d: ", elevators[i].id);
            if (elevators[i].is_idle) {
                printf("Idle\n");
            } else {
                printf("Moving from floor %d to floor %d\n", elevators[i].current_floor, elevators[i].destination_floor);
            }
        }

        // Get input from user
        printf("\n");
        printf("Enter current floor: ");
        scanf("%d", &current_floor);

        printf("Enter destination floor: ");
        scanf("%d", &destination_floor);

        // Find the closest idle elevator
        int min_distance = total_floors + 1;
        for (int i = 0; i < num_of_elevators; i++) {
            if (elevators[i].is_idle) {
                int distance = abs(elevators[i].current_floor - current_floor);
                if (distance < min_distance) {
                    min_distance = distance;
                    selected_elevator_id = elevators[i].id;
                }
            }
        }

        // Set selected elevator destination
        elevator *selected_elevator;
        for (int i = 0; i < num_of_elevators; i++) {
            if (elevators[i].id == selected_elevator_id) {
                selected_elevator = &elevators[i];
                selected_elevator->destination_floor = destination_floor;
                update_elevator_destination(selected_elevator);
                break;
            }
        }

        // Move elevator
        while (!is_destination_reached(*selected_elevator)) {
            if (selected_elevator->is_move_up) {
                selected_elevator->current_floor++;
            } else {
                selected_elevator->current_floor--;
            }

            if (selected_elevator->current_floor == selected_elevator->destination_floor) {
                selected_elevator->is_idle = true;
                break;
            }
        }
    }

    return 0;
}

// Function implementation
void init_elevators(elevator elevators[], int num_of_elevators) {
    for (int i = 0; i < num_of_elevators; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = 1;
        elevators[i].destination_floor = 0;
        elevators[i].is_move_up = true;
        elevators[i].is_idle = true;
    }
}

void update_elevator_destination(elevator *e) {
    if (e->destination_floor > e->current_floor) {
        e->is_move_up = true;
    } else {
        e->is_move_up = false;
    }
    e->is_idle = false;
}

bool is_destination_reached(elevator e) {
    return e.current_floor == e.destination_floor;
}