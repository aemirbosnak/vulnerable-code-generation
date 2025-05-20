//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 5
#define MAX_PASSENGERS 5

typedef struct {
    int floor;
    int direction; // 0 = up, 1 = down
} Passenger;

void print_elevator(int floor) {
    printf("Elevator is at floor %d\n", floor);
}

void print_passengers(Passenger* passengers, int num_passengers) {
    printf("Passengers: ");
    for (int i = 0; i < num_passengers; i++) {
        printf("%d ", passengers[i].floor);
    }
    printf("\n");
}

void update_elevator(int* floor, Passenger* passengers, int num_passengers) {
    if (num_passengers == 0) {
        return;
    }

    // Find the closest passenger to the elevator
    int closest_passenger = 0;
    for (int i = 1; i < num_passengers; i++) {
        if (abs(passengers[i].floor - *floor) < abs(passengers[closest_passenger].floor - *floor)) {
            closest_passenger = i;
        }
    }

    // Move the elevator towards the closest passenger
    if (passengers[closest_passenger].floor > *floor) {
        *floor += 1;
    } else if (passengers[closest_passenger].floor < *floor) {
        *floor -= 1;
    }

    // Remove the passenger from the list
    for (int i = closest_passenger; i < num_passengers - 1; i++) {
        passengers[i] = passengers[i + 1];
    }
    num_passengers--;
}

int main() {
    // Initialize the elevator
    int floor = 0;
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers = 0;

    // Simulate the elevator for 100 floors
    for (int i = 0; i < 100; i++) {
        // Print the current floor and passengers
        print_elevator(floor);
        print_passengers(passengers, num_passengers);

        // Update the elevator and passengers
        update_elevator(&floor, passengers, &num_passengers);

        // Add a new passenger if necessary
        if (num_passengers < MAX_PASSENGERS && rand() % 2 == 0) {
            passengers[num_passengers].floor = rand() % NUM_FLOORS;
            passengers[num_passengers].direction = rand() % 2;
            num_passengers++;
        }

        // Simulate time passing
        sleep(1);
    }

    return 0;
}