//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PASSENGERS 10
#define MAX_FLOORS 10
#define MAX_LIFT_SPEED 1.0
#define LIFT_SPEED_INCREMENT 0.1

struct passenger {
    int floor;
    int elevator;
    int weight;
};

struct floor {
    int floor;
    int passengers;
};

int main() {
    int numPassengers = 0;
    int numFloors = 0;
    int elevator = 0;
    int liftSpeed = 0.0;
    int passengerWeight = 0;
    int floor = 0;
    int passengersOnFloor = 0;
    struct passenger passenger[MAX_PASSENGERS];
    struct floor floorData[MAX_FLOORS];

    // Initialize the elevator
    printf("Welcome to the unique C Elevator Simulation!\n");
    printf("Please enter the number of floors in the building:\n");
    scanf("%d", &numFloors);
    printf("Please enter the maximum number of passengers the elevator can carry:\n");
    scanf("%d", &numPassengers);
    printf("Please enter the initial floor of the elevator:\n");
    scanf("%d", &elevator);
    printf("Please enter the maximum lift speed:\n");
    scanf("%f", &liftSpeed);
    printf("Please enter the initial weight of the passengers:\n");
    scanf("%d", &passengerWeight);

    // Initialize the floors
    for (int i = 0; i < numFloors; i++) {
        printf("Please enter the floor number of floor %d:\n", i + 1);
        scanf("%d", &floor);
        printf("Please enter the number of passengers on floor %d:\n", i + 1);
        scanf("%d", &passengersOnFloor);
        floorData[i].floor = floor;
        floorData[i].passengers = passengersOnFloor;
    }

    // Start the simulation
    printf("Simulation starting...\n");
    printf("The elevator is currently at floor %d\n", elevator);
    while (1) {
        printf("What floor would you like to go to?\n");
        scanf("%d", &floor);
        printf("Please wait...\n");
        sleep(1);
        printf("Elevator moving to floor %d\n", floor);
        elevator = floor;
        printf("Please wait...\n");
        sleep(liftSpeed);
        printf("Elevator at floor %d\n", elevator);

        // Check for passengers on the current floor
        for (int i = 0; i < passengersOnFloor; i++) {
            printf("Passenger %d on floor %d would like to go to floor %d\n", i + 1, i + 1, floor);
            printf("Do you want to take this passenger? (y/n): ");
            scanf("%s", &passenger[numPassengers].elevator);
            if (strcmp(passenger[numPassengers].elevator, "y") == 0) {
                passenger[numPassengers].floor = floor;
                passenger[numPassengers].weight = passengerWeight;
                numPassengers++;
            }
        }

        // Update the floors
        for (int i = 0; i < numFloors; i++) {
            if (floorData[i].passengers > 0) {
                floorData[i].passengers--;
            } else {
                floorData[i].passengers = 0;
            }
        }

        // Update the lift speed
        liftSpeed += LIFT_SPEED_INCREMENT;
        if (liftSpeed > MAX_LIFT_SPEED) {
            liftSpeed = MAX_LIFT_SPEED;
        }
    }
    return 0;
}