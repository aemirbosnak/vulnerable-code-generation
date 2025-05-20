//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

void simulate_elevator(int elevator, int curr_floor, bool direction_up, int dest_floor) {
    printf("Elevator %d is currently at floor %d.\n", elevator, curr_floor);
    printf("Elevator %d is going %s.\n", elevator, direction_up ? "up" : "down");
    printf("Elevator %d is going to floor %d.\n", elevator, dest_floor);
    printf("Elevator %d has arrived at floor %d.\n", elevator, dest_floor);
    printf("Elevator %d doors have opened.\n", elevator);
    printf("Elevator %d doors have closed.\n", elevator);
}

int main() {
    int num_elevators = MAX_ELEVATORS;
    int num_floors = MAX_FLOORS;

    // Elevator start positions
    int elevator_pos[num_elevators];
    for (int i = 0; i < num_elevators; i++) {
        elevator_pos[i] = 1;
    }

    // Elevator direction
    bool elevator_direction[num_elevators];
    for (int i = 0; i < num_elevators; i++) {
        elevator_direction[i] = true;
    }

    // Elevator destination floors
    int elevator_dest_floor[num_elevators];
    for (int i = 0; i < num_elevators; i++) {
        elevator_dest_floor[i] = 0;
    }

    // Simulation loop
    while (true) {
        // User input simulation
        printf("Enter an elevator (1-%d) and a floor (1-%d) separated by a space, or -1 to quit: ", num_elevators, num_floors);
        int elevator = 0;
        int floor = 0;
        scanf("%d", &elevator);
        if (elevator == -1) {
            break;
        }
        scanf("%d", &floor);

        // Check for valid input
        if (elevator < 1 || elevator > num_elevators || floor < 1 || floor > num_floors) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

       // Set elevator destination
        elevator_dest_floor[elevator - 1] = floor;

        // Run elevator simulation
        simulate_elevator(elevator, elevator_pos[elevator - 1], elevator_direction[elevator - 1], elevator_dest_floor[elevator - 1]);

        // Update elevator position and direction
        if (elevator_pos[elevator - 1] == elevator_dest_floor[elevator - 1]) {
            elevator_direction[elevator - 1] = !elevator_direction[elevator - 1];
        }
        if (elevator_direction[elevator - 1]) {
            elevator_pos[elevator - 1]++;
        } else {
            elevator_pos[elevator - 1]--;
        }
    }

    return 0;
}