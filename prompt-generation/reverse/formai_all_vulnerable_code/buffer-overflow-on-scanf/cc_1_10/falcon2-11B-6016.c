//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10

int main() {
    int i;
    int current_floor = 0;
    int destination_floor = 0;
    int floor_taken = 0;
    int total_floors = 0;

    printf("Welcome to the post-apocalyptic elevator simulator!\n");
    printf("To start, enter the current floor number: ");
    scanf("%d", &current_floor);

    while (floor_taken < NUM_FLOORS) {
        printf("Enter the destination floor number: ");
        scanf("%d", &destination_floor);

        if (destination_floor == current_floor) {
            printf("You are already on this floor, no need to move.\n");
            continue;
        }

        printf("Destination floor: %d\n", destination_floor);
        printf("Current floor: %d\n", current_floor);

        if (destination_floor > current_floor) {
            for (i = current_floor; i < destination_floor; i++) {
                printf("Going up to floor %d...\n", i);
                floor_taken++;
                total_floors++;
            }
        } else if (destination_floor < current_floor) {
            for (i = current_floor; i > destination_floor; i--) {
                printf("Going down to floor %d...\n", i);
                floor_taken++;
                total_floors++;
            }
        } else {
            printf("Destination floor is already reached.\n");
            continue;
        }

        printf("Total floors reached: %d\n", total_floors);

        printf("Do you want to continue using the elevator? (y/n): ");
        char input;
        scanf(" %c", &input);

        if (input!= 'y') {
            break;
        }

        current_floor = destination_floor;
    }

    printf("Thank you for using the post-apocalyptic elevator simulator!\n");

    return 0;
}