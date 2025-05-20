//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int floors = 10;
    int currentFloor = 0;
    int destinationFloor = 0;
    int maxRiders = 5;
    int ridersCount = 0;
    int riderArrival = 0;
    int floorChange = 0;

    while (1) {
        printf("Enter your floor: ");
        scanf("%d", &currentFloor);

        if (currentFloor > floors) {
            printf("Invalid floor number. Please try again.\n");
            continue;
        }

        printf("Enter your destination floor: ");
        scanf("%d", &destinationFloor);

        if (destinationFloor > floors) {
            printf("Invalid destination floor number. Please try again.\n");
            continue;
        }

        if (currentFloor == destinationFloor) {
            printf("You have reached your destination. Thank you for riding with us.\n");
            break;
        }

        if (ridersCount >= maxRiders) {
            printf("Sorry, the elevator is full. Please wait for the next one.\n");
            continue;
        }

        if (floorChange == 1) {
            printf("Elevator moving...\n");
        } else {
            printf("Elevator stopped at floor %d\n", currentFloor);
        }

        riderArrival = rand() % 10;
        if (riderArrival == 0) {
            printf("Rider %d entered the elevator.\n", ridersCount + 1);
        }

        floorChange = rand() % 2;
        if (floorChange == 0) {
            destinationFloor++;
        } else {
            destinationFloor--;
        }

        if (destinationFloor == currentFloor) {
            printf("Rider %d arrived at their destination floor.\n", ridersCount + 1);
            ridersCount++;
            floorChange = 1;
        }

        if (currentFloor == destinationFloor) {
            printf("Rider %d arrived at their destination floor.\n", ridersCount);
            ridersCount = 0;
            floorChange = 0;
        }

        printf("Rider %d left the elevator.\n", ridersCount);
    }

    return 0;
}