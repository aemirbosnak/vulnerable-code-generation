//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct {
    char name[20];
    int floor;
} Passenger;

int main() {
    Passenger passengers[MAX_PASSENGERS];
    int floors[MAX_FLOORS];
    int num_floors = 0;
    int num_passengers = 0;
    int current_floor = 0;
    int max_passengers = 0;

    printf("Welcome to the Elevator Simulation!\n");

    // Read floors
    printf("Enter the number of floors in the building (1-5): ");
    scanf("%d", &num_floors);
    for (int i = 0; i < num_floors; i++) {
        printf("Enter floor %d: ", i + 1);
        scanf("%d", &floors[i]);
    }

    // Read passengers
    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);
    for (int i = 0; i < num_passengers; i++) {
        printf("Enter passenger %d's name and floor: ", i + 1);
        scanf("%s %d", passengers[i].name, &passengers[i].floor);
    }

    // Sort passengers by floor
    for (int i = 0; i < num_passengers; i++) {
        for (int j = i + 1; j < num_passengers; j++) {
            if (passengers[i].floor > passengers[j].floor) {
                Passenger temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }

    // Sort floors by current floor
    for (int i = 0; i < num_floors; i++) {
        for (int j = i + 1; j < num_floors; j++) {
            if (floors[i] > floors[j]) {
                int temp = floors[i];
                floors[i] = floors[j];
                floors[j] = temp;
            }
        }
    }

    // Simulate elevator operation
    while (num_passengers > 0) {
        // Find closest floor
        int closest_floor = -1;
        int closest_distance = MAX_FLOORS;
        for (int i = 0; i < num_passengers; i++) {
            int distance = abs(floors[current_floor] - passengers[i].floor);
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_floor = passengers[i].floor;
            }
        }

        // Move elevator to closest floor
        current_floor = closest_floor;

        // Check if any passengers can board
        for (int i = 0; i < num_passengers; i++) {
            if (passengers[i].floor == current_floor) {
                printf("Passenger %s boarded the elevator on floor %d.\n", passengers[i].name, current_floor);
                passengers[i].floor = MAX_FLOORS; // Set to invalid floor to remove from passenger list
                num_passengers--;
            }
        }

        // Check if any passengers can exit
        for (int i = 0; i < num_passengers; i++) {
            if (passengers[i].floor!= MAX_FLOORS) {
                printf("Passenger %s exited the elevator on floor %d.\n", passengers[i].name, passengers[i].floor);
                num_passengers--;
            }
        }

        // Check if any passengers are left
        if (num_passengers > 0) {
            printf("Passengers remaining:\n");
            for (int i = 0; i < num_passengers; i++) {
                printf("Passenger %s on floor %d.\n", passengers[i].name, passengers[i].floor);
            }
        }
    }

    // Output final floor
    printf("The elevator has reached floor %d.\n", current_floor);

    return 0;
}