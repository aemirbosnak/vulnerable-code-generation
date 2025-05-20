//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
    char name[20];
    int floor;
    int destination;
} Passenger;

void simulate_elevator(Passenger passengers[]) {
    int currentFloor = 1;
    int passengers_on = 0;
    time_t start_time = time(NULL);

    for (int i = 0; i < MAX_PASSENGERS && passengers_on < MAX_PASSENGERS; i++) {
        passengers[i].floor = rand() % NUM_FLOORS + 1;
        passengers[i].destination = rand() % NUM_FLOORS + 1;
        passengers_on++;
    }

    printf("Elevator Simulation:\n");

    while (currentFloor != passengers[0].destination) {
        int nextFloor = -1;
        for (int i = 0; i < passengers_on; i++) {
            if (currentFloor == passengers[i].floor) {
                nextFloor = passengers[i].destination;
            }
        }

        if (nextFloor != -1) {
            currentFloor = nextFloor;
            printf("Current floor: %d\n", currentFloor);
        } else {
            printf("No passengers at current floor.\n");
        }

        time_t end_time = time(NULL);
        int time_taken = end_time - start_time;
        printf("Time taken: %d seconds\n", time_taken);

        start_time = time(NULL);
    }

    printf("Destination reached: %d\n", passengers[0].destination);
    printf("Goodbye!\n");
}

int main() {
    Passenger passengers[MAX_PASSENGERS];
    simulate_elevator(passengers);

    return 0;
}