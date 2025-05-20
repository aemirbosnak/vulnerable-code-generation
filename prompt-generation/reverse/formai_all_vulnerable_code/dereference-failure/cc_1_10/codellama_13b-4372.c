//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int floor;
    int weight;
} passenger;

void simulateElevator(int numPassengers, passenger* passengers) {
    int currentFloor = 1;
    int direction = 1;
    int time = 0;

    while (numPassengers > 0) {
        for (int i = 0; i < numPassengers; i++) {
            if (passengers[i].floor == currentFloor) {
                printf("Passenger %d has arrived at floor %d\n", i, currentFloor);
                numPassengers--;
            }
        }

        if (time == 100) {
            printf("Moving to next floor\n");
            currentFloor += direction;
            time = 0;
        } else {
            time++;
        }

        if (currentFloor == NUM_FLOORS || currentFloor == 1) {
            direction *= -1;
        }
    }
}

int main() {
    srand(time(NULL));

    passenger* passengers = malloc(sizeof(passenger) * NUM_FLOORS);
    for (int i = 0; i < NUM_FLOORS; i++) {
        passengers[i].floor = i + 1;
        passengers[i].weight = rand() % MAX_CAPACITY + 1;
    }

    simulateElevator(NUM_FLOORS, passengers);

    free(passengers);
    return 0;
}