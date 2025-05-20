//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int randomNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Variable declaration
    int i, choice, door_num, ghost_door, win_door;
    char play_again;

    // Seed random number generator with current time
    srand(time(0));

    printf("Welcome to the Haunted House Simulator!\n");

    do {
        printf("\nChoose a door number (1, 2, or 3): ");
        scanf("%d", &choice);

        // Validate user input
        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }

        printf("You have chosen door number %d.\n", choice);

        // Determine which door has the ghost
        ghost_door = randomNum(1, 3);

        // Exclude user's choice and the ghost door to determine win door
        for (i = 1; i <= 3; i++) {
            if (i != choice && i != ghost_door) {
                win_door = i;
                break;
            }
        }

        printf("Door number %d does not have the ghost.\n", win_door);

        printf("Would you like to switch doors (y/n)? ");
        scanf(" %c", &play_again);

        // Determine which door the user has switched to
        if (play_again == 'y') {
            for (i = 1; i <= 3; i++) {
                if (i != choice && i != win_door) {
                    door_num = i;
                    break;
                }
            }
        }
        else {
            door_num = choice;
        }

        // Determine if user has won or lost
        if (door_num == ghost_door) {
            printf("BOO! You have been haunted by a ghost!\n");
        }
        else {
            printf("Congratulations! You have survived the haunted house!\n");
        }

        printf("Would you like to play again (y/n)? ");
        scanf(" %c", &play_again);

    } while (play_again == 'y');

    return 0;   
}