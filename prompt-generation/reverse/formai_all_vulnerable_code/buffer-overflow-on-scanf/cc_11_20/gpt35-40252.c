//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// This program simulates a multi-floor elevator system

int main() {

    int curr_floor = 1; // Current floor of elevator
    int floor_request = 0; // Floor requested by user
    int num_floors = 5; // Total number of floors in the building
    int num_people = 0; // Number of people in the elevator
    int max_capacity = 10; // Maximum capacity of the elevator
    int available_space = max_capacity - num_people; // Available space in the elevator
    int direction = 1; // 1 represents going up, -1 represents going down

    printf("*** Welcome to Multi-Floor Elevator Simulation! ***\n");

    // Keep running the program until user exits
    while (4) {
        printf("\nYou are currently on floor %d.\n", curr_floor);
        printf("There are %d people in the elevator. Available space: %d\n", num_people, available_space);
        printf("Please enter the floor you would like to go to (1-%d), or enter 0 to exit: ", num_floors);

        scanf("%d", &floor_request);

        // Check if user wants to exit
        if (floor_request == 0) {
            printf("Thank you for using Multi-Floor Elevator Simulation!\n");
            return 0;
        }

        // Check if user input is valid
        if (floor_request < 1 || floor_request > num_floors) {
            printf("Invalid input. Please enter a floor number between 1 and %d.\n", num_floors);
            continue;
        }

        // Check if elevator is at requested floor
        if (floor_request == curr_floor) {
            printf("You are already on floor %d.\n", curr_floor);
            continue;
        }

        // Check if elevator is going up or down
        if (floor_request > curr_floor) {
            direction = 1;
        } else {
            direction = -1;
        }

        printf("\n*** Doors closing. Going %s. ***\n", direction > 0 ? "up" : "down");

        // Move elevator to requested floor 
        while (curr_floor != floor_request) {
            curr_floor += direction;
            printf("Current floor: %d\n", curr_floor);
        }

        printf("*** Doors opening. You have arrived at floor %d. ***\n", curr_floor);

        // Check if there is enough space for more people
        if (num_people == max_capacity) {
            printf("The elevator is full. Sorry, you cannot enter.\n");
            continue;
        }

        printf("Would you like to enter? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            printf("Alright, have a nice day!\n");
            continue;
        }

        num_people++;
        printf("You have entered the elevator. There are now %d people in the elevator.\n", num_people);
        available_space = max_capacity - num_people;
    }

    return 0;
}