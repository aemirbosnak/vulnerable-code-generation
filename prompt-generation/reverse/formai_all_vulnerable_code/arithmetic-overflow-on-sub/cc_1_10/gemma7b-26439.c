//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
    char name[20];
    int floor;
    int destination;
} Passenger;

void simulate_elevator(Passenger *passengers, int num_passengers) {
    int current_floor = 1;
    int destination_floor;
    time_t start_time;
    time_t end_time;

    for (int i = 0; i < num_passengers; i++) {
        destination_floor = passengers[i].destination;

        start_time = time(NULL);
        printf("Passenger %s is pressing the button for floor %d.\n", passengers[i].name, destination_floor);

        // Simulate elevator travel time
        sleep(rand() % 3);

        end_time = time(NULL);
        printf("Passenger %s has arrived on floor %d. Travel time: %ld seconds.\n", passengers[i].name, current_floor, end_time - start_time);

        current_floor = destination_floor;
    }

    printf("The elevator is now at floor %d.\n", current_floor);
}

int main() {
    Passenger passengers[MAX_PASSENGERS];

    // Create passengers
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i].name[0] = 'A' + i;
        passengers[i].floor = rand() % MAX_FLOORS + 1;
        passengers[i].destination = rand() % MAX_FLOORS + 1;
    }

    // Simulate elevator
    simulate_elevator(passengers, MAX_PASSENGERS);

    return 0;
}