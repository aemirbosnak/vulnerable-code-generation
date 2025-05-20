//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_FLOORS 10

int main() {
    int passengers[MAX_PASSENGERS];
    int currentFloor = 1;
    int destinationFloor = 1;
    int elevatorCapacity = 10;

    srand(time(0));

    while (1) {
        printf("Current floor: %d\n", currentFloor);
        printf("Destination floor: %d\n", destinationFloor);
        printf("Passengers: ");
        for (int i = 0; i < MAX_PASSENGERS; i++) {
            printf("%d ", passengers[i]);
        }
        printf("\n");

        printf("1. Move up\n");
        printf("2. Move down\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                destinationFloor++;
                if (destinationFloor > MAX_FLOORS) {
                    destinationFloor = 1;
                }
                break;
            case 2:
                destinationFloor--;
                if (destinationFloor < 1) {
                    destinationFloor = MAX_FLOORS;
                }
                break;
            case 3:
                exit(0);
        }

        if (currentFloor == destinationFloor) {
            printf("Elevator arrived at destination floor.\n");
        } else {
            int passengersWaiting = 0;
            for (int i = 0; i < MAX_PASSENGERS; i++) {
                if (passengers[i] > 0) {
                    passengersWaiting++;
                }
            }

            if (passengersWaiting > 0) {
                printf("Waiting for passengers to board.\n");
            } else {
                printf("Elevator moving to destination floor.\n");
            }

            for (int i = 0; i < MAX_PASSENGERS; i++) {
                if (passengers[i] > 0) {
                    passengers[i]--;
                }
            }

            if (currentFloor == 1) {
                printf("Elevator going up.\n");
            } else if (currentFloor == MAX_FLOORS) {
                printf("Elevator going down.\n");
            } else {
                printf("Elevator moving between floors.\n");
            }
        }

        currentFloor++;
        if (currentFloor > MAX_FLOORS) {
            currentFloor = 1;
        }

        printf("Passengers: ");
        for (int i = 0; i < MAX_PASSENGERS; i++) {
            printf("%d ", passengers[i]);
        }
        printf("\n");
    }

    return 0;
}