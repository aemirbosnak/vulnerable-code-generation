//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* This program simulates an elevator with a maximum capacity of 10 people. */

int main() {
    int currentFloor = 1; // The elevator starts on the first floor
    int numPassengers = 0; // The number of passengers currently in the elevator
    int totalPassengers = 0; // The total number of passengers who have ridden the elevator

    printf("Welcome to the elevator! You are currently on the first floor.\n");

    while (1) { // Loop forever until the program is terminated
        printf("Please choose a floor to go to (1-10): \n");
        int selectedFloor;
        scanf("%d", &selectedFloor);

        if (selectedFloor == currentFloor) {
            printf("You are already on floor %d!\n", currentFloor);
            continue; // Continue the loop without incrementing the total passenger count
        }

        if (selectedFloor < 1 || selectedFloor > 10) {
            printf("Invalid floor selected! Please choose a floor between 1-10.\n");
            continue; // Continue the loop without incrementing the total passenger count
        }

        if (numPassengers == 10) {
            printf("Sorry, the elevator is already at maximum capacity!\n");
            continue; // Continue the loop without incrementing the total passenger count
        }

        // If all validation passes, increment the passenger count
        numPassengers++;
        totalPassengers++;

        printf("Please enter your name: \n");
        char name[50];
        scanf("%s", name);

        printf("%s enters the elevator and presses button for floor %d.\n", name, selectedFloor);

        // Move the elevator to the selected floor
        if (selectedFloor > currentFloor) {
            for (int i = currentFloor; i < selectedFloor; i++) {
                printf("Elevator is moving up to floor %d.\n", i + 1);
            }
        } else {
            for (int i = currentFloor; i > selectedFloor; i--) {
                printf("Elevator is moving down to floor %d.\n", i - 1);
            }
        }

        currentFloor = selectedFloor;
        printf("Ding! You have arrived at floor %d.\n", currentFloor);

        printf("Please exit the elevator.\n");
        numPassengers--;

        // If there are no more passengers, reset the elevator to the first floor
        if (numPassengers == 0) {
            currentFloor = 1;
            printf("The elevator is now empty and is back on the first floor.\n");
        }

        printf("Total passengers transported: %d\n", totalPassengers);
    }

    return 0;
}