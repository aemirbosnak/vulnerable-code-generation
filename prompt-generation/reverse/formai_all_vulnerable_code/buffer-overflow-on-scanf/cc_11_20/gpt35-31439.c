//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // Elevator parameters
    const int floors = 10;
    const int max_people = 5;
    const int max_floors = 5;

    int current_floor = 1;
    int destination_floor = 0;
    int num_people = 0;

    bool up = true;
    bool doors_open = false;

    while (true) {

        // Display elevator status
        printf("\nElevator on floor %d, %d people\n", current_floor, num_people);
        printf("Doors %s\n\n", doors_open ? "open" : "closed");

        // Ask user for input
        printf("Choose your destination floor:\n");
        scanf("%d", &destination_floor);

        printf("How many people are entering the elevator? (max %d)\n", max_people);
        scanf("%d", &num_people);

        // Validate input
        if (destination_floor < 1 || destination_floor > floors) {
            printf("Invalid floor selected. Please choose a number between 1 and %d\n", floors);
            continue;
        }

        if (num_people < 1 || num_people > max_people) {
            printf("Invalid number of people entered. Please choose a number between 1 and %d\n", max_people);
            continue;
        }

        // Close doors and start moving
        if (!doors_open) {
            printf("Doors are closing...\n");
            doors_open = false;
        }

        if (current_floor < destination_floor) {
            up = true;
            printf("Going up...\n");
        } else {
            up = false;
            printf("Going down...\n");
        }

        // Move to destination floor
        while (current_floor != destination_floor) {
            if (up) {
                current_floor++;
            } else {
                current_floor--;
            }
            printf("Elevator on floor %d\n", current_floor);
        }

        printf("Arrived at floor %d. Doors opening...\n", current_floor);
        doors_open = true;

        // Wait for people to enter/exit
        while (num_people > 0 && doors_open) {
            printf("%d people entering the elevator...\n", num_people);
            printf("%d people exiting the elevator...\n", num_people);
            num_people = 0;
        }

        // Close doors and set new direction
        printf("Doors closing...\n");
        doors_open = false;

        if (current_floor == max_floors) {
            up = false;
            printf("Going down...\n");
        } else if (current_floor == 1) {
            up = true;
            printf("Going up...\n");
        }
    }

    return 0;
}