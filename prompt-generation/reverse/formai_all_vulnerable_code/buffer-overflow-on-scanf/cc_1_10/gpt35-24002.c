//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include <stdio.h>

int main() {
    int elevator_pos = 1; // Initialize elevator at first floor
    int num_floors = 5; // Set the number of floors available in the building
    int current_floor = 1;
    int destination_floor = 0;
    int direction = 1;  // Initialize direction of elevator as upwards

    printf("Welcome to the Elevator Simulation program!\n");
    printf("The elevator is currently at floor %d\n", elevator_pos);

    while (1) {
        printf("Please enter your destination floor (1-%d): ", num_floors);
        scanf("%d", &destination_floor);

        if (destination_floor > num_floors || destination_floor < 1){
            printf("Invalid Floor! Please Enter a Valid Floor Number Between 1-%d.\n\n", num_floors);
            continue;
        }

        // Set elevator direction based on current and destination floors
        if (destination_floor > current_floor)
            direction = 1; // Going up
        else
            direction = -1; // Going down

        printf("\nThe Lift Doors Are Closing.\n");
        printf("Going %s...\n", direction == 1 ? "Up" : "Down");

        // Move the elevator up/down until it reaches the destination floor
        while (elevator_pos != destination_floor) {
            elevator_pos += direction;
            printf("Passing floor %d...\n", elevator_pos);
        }

        // Stop elevator and open the doors
        printf("The elevator has reached floor %d.\n", elevator_pos);
        printf("Opening the elevator doors.\n");

        // Wait for some time to allow the passengers to exit
        printf("Please exit the elevator now.\n");
        sleep(3);

        // Close the doors, update variables and start the process again
        printf("The Lift Doors Are Closing.\n");
        printf("Going back to the first floor...\n");

        current_floor = elevator_pos; // Update current floor to destination floor
        destination_floor = 1; // Set destination floor as the first floor
        elevator_pos = 1; // Move the elevator to the first floor
    }

    return 0;
}