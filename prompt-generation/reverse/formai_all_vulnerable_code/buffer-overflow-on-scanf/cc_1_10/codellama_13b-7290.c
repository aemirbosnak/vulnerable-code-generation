//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: creative
/*
* Elevator Simulation in C
*
* This program simulates an elevator in a building with 5 floors.
* The elevator has 3 buttons: 1st, 2nd, and 3rd.
* The elevator starts at the 1st floor and can only go up or down.
* The user can press the buttons to move the elevator to the desired floor.
* The program displays the current floor and the direction of the elevator.
*/

#include <stdio.h>

#define NUM_FLOORS 5

int main() {
    int current_floor = 1;
    char direction = 'u';
    int button_pressed = 0;

    while (1) {
        printf("Current floor: %d\n", current_floor);
        printf("Direction: %c\n", direction);

        // Get user input
        printf("Press 1 to go to the 1st floor, 2 to go to the 2nd floor, or 3 to go to the 3rd floor.\n");
        scanf("%d", &button_pressed);

        // Validate user input
        if (button_pressed < 1 || button_pressed > 3) {
            printf("Invalid input.\n");
            continue;
        }

        // Move elevator to the desired floor
        if (button_pressed == 1) {
            if (current_floor > 1) {
                direction = 'd';
                current_floor--;
            } else {
                printf("Already at the 1st floor.\n");
            }
        } else if (button_pressed == 2) {
            if (current_floor < 2) {
                direction = 'u';
                current_floor++;
            } else {
                printf("Already at the 2nd floor.\n");
            }
        } else if (button_pressed == 3) {
            if (current_floor < 3) {
                direction = 'u';
                current_floor++;
            } else {
                printf("Already at the 3rd floor.\n");
            }
        }

        // Print the current floor and direction
        printf("Current floor: %d\n", current_floor);
        printf("Direction: %c\n", direction);
    }

    return 0;
}