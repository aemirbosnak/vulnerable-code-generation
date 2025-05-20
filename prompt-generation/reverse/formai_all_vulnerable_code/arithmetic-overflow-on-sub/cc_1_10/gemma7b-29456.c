//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

void simulate_elevator(int current_floor, Passenger* passengers) {
    int target_floor;
    printf("Current floor: %d, passengers: ", current_floor);
    for (Passenger* passenger = passengers; passenger; passenger = passenger->next) {
        printf("%s ", passenger->name);
    }
    printf("\n");

    printf("Enter target floor: ");
    scanf("%d", &target_floor);

    // Calculate direction and distance of travel
    int direction = target_floor - current_floor;
    int distance = abs(direction);

    // Move the elevator
    for (int i = 0; i < distance; i++) {
        current_floor += direction;
        printf("Elevator moving to floor %d... ", current_floor);
        sleep(1);
    }

    // Drop off passengers
    for (Passenger* passenger = passengers; passenger; passenger = passenger->next) {
        if (current_floor == passenger->floor) {
            printf("%s has reached their floor.\n", passenger->name);
            free(passenger);
        }
    }

    // Update current floor
    current_floor = target_floor;
}

int main() {
    int current_floor = 1;
    Passenger* passengers = NULL;

    // Simulate elevator for a while
    for (int i = 0; i < 10; i++) {
        simulate_elevator(current_floor, passengers);
    }

    return 0;
}