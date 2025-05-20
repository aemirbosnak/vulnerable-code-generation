//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int numFloors = 10;
    int currentFloor = 0;
    int maxPassengers = 20;

    printf("Welcome to the Elevator Simulation!\n");
    printf("The elevator has %d floors.\n", numFloors);
    printf("The elevator can hold a maximum of %d passengers.\n", maxPassengers);

    while (currentFloor <= numFloors) {
        printf("Current floor: %d\n", currentFloor);
        if (currentFloor == 0) {
            printf("The elevator is at the bottom floor.\n");
        } else if (currentFloor == numFloors) {
            printf("The elevator is at the top floor.\n");
        } else {
            printf("The elevator is at floor %d.\n", currentFloor);
        }

        printf("Passengers: ");
        int passengers = 0;
        for (int i = 0; i < maxPassengers; i++) {
            int userInput = scanf("%d", &passengers);
            if (userInput!= 1) {
                printf("Invalid input, please try again.\n");
                passengers = 0;
                break;
            }
        }
        printf("%d\n", passengers);

        if (passengers > 0) {
            printf("New passengers enter the elevator.\n");
        } else {
            printf("The elevator is empty.\n");
        }

        int floorInput = scanf("%d", &currentFloor);
        if (floorInput!= 1) {
            printf("Invalid input, please try again.\n");
            currentFloor = 0;
        } else {
            printf("The elevator goes up to floor %d.\n", currentFloor);
        }
    }

    printf("Thank you for using the elevator simulation!\n");

    return 0;
}