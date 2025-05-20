//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>

#define MAX_FLOORS 10  // Total number of floors
#define NUM_ELEVATORS 2  // Total number of elevators

// The `Elevator` struct represents each elevator
typedef struct {
    int id;
    int current_floor;
    int destination_floor;
    int is_busy;
} Elevator;

// Function prototypes
int get_floor_choice();
void print_elevator_status(Elevator *elevator);
int nearest_elevator(Elevator *elevators, int num_elevators, int floor);

int main() {
    Elevator elevators[NUM_ELEVATORS];

    // Initialize the elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = 1;
        elevators[i].destination_floor = -1;
        elevators[i].is_busy = 0;
    }

    int floor_choice;
    while (1) {
        // Get the user's floor choice
        floor_choice = get_floor_choice();

        // Find the nearest available elevator
        int elevator_index = nearest_elevator(elevators, NUM_ELEVATORS, floor_choice);

        // Print the status of the elevator
        print_elevator_status(&elevators[elevator_index]);

        // Update the elevator's status
        elevators[elevator_index].is_busy = 1;
        elevators[elevator_index].destination_floor = floor_choice;

        // Wait for the elevator to arrive at the selected floor
        while (elevators[elevator_index].current_floor != floor_choice) {
            // Do nothing
        }

        // Update the elevator's status
        elevators[elevator_index].is_busy = 0;
        elevators[elevator_index].destination_floor = -1;
    }

    return 0;
}

// Prompt the user to enter a floor number
int get_floor_choice() {
    int floor_choice;
    printf("Enter the floor number (1-%d): ", MAX_FLOORS);
    scanf("%d", &floor_choice);

    if (floor_choice < 1 || floor_choice > MAX_FLOORS) {
        printf("Invalid floor number. Please try again.\n");
        return get_floor_choice();
    }

    return floor_choice;
}

// Print the status of an elevator
void print_elevator_status(Elevator *elevator) {
    printf("Elevator %d is on floor %d", elevator->id, elevator->current_floor);

    if (elevator->is_busy) {
        printf(" and is currently occupied.\n");
    } else {
        printf(" and is currently available.\n");
    }
}

// Find the nearest available elevator to a given floor
int nearest_elevator(Elevator *elevators, int num_elevators, int floor) {
    // Find the nearest elevator that is not busy
    int min_distance = MAX_FLOORS + 1;
    int min_index = -1;

    for (int i = 0; i < num_elevators; i++) {
        // Ignore busy elevators
        if (elevators[i].is_busy) {
            continue;
        }

        // Calculate the distance between the elevator and the selected floor
        int distance = abs(elevators[i].current_floor - floor);

        if (distance < min_distance) {
            min_distance = distance;
            min_index = i;
        }
    }

    if (min_index == -1) {
        printf("All elevators are busy. Please try again later.\n");
        return nearest_elevator(elevators, num_elevators, floor);
    }

    return min_index;
}