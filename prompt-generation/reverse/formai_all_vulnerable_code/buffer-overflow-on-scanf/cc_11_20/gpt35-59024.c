//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // print out the introduction and rules
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You just entered an old, creepy mansion that is known to be haunted.\n");
    printf("Your task is to find a way out of the house before the ghost catches you!\n\n");

    // set up the variables
    int isHaunted = 1;
    int playerLocation = 0;
    int ghostLocation = 4;

    // generate the initial locations of the items
    srand(time(0));
    int keyLocation = rand() % 5;
    int exitLocation = rand() % 5;

    // print out the initial locations of the items
    printf("The key is hidden in room %d.\n", keyLocation);
    printf("The exit is located in room %d.\n", exitLocation);

    // start the game loop
    while (isHaunted) {

        // print out the current location of the player and ask for input
        printf("You are currently in room %d.\n", playerLocation);
        printf("Which direction do you want to go? (0=left, 1=right, 2=up, 3=down): ");
        int direction;
        scanf("%d", &direction);

        // update the player location based on input
        switch (direction) {
            case 0:
                if (playerLocation == 0) {
                    printf("You hit a wall. Ouch!\n");
                    break;
                }
                playerLocation--;
                break;
            case 1:
                if (playerLocation == 4) {
                    printf("You hit a wall. Ouch!\n");
                    break;
                }
                playerLocation++;
                break;
            case 2:
                if (playerLocation < 2) {
                    printf("You hit a wall. Ouch!\n");
                    break;
                }
                playerLocation -= 2;
                break;
            case 3:
                if (playerLocation > 2) {
                    printf("You hit a wall. Ouch!\n");
                    break;
                }
                playerLocation += 2;
                break;
            default:
                printf("Invalid direction. Please try again.\n");
                continue;
        }

        // check if the player found the key
        if (playerLocation == keyLocation) {
            printf("You found the key!\n");
            printf("Now find the exit and get out of this haunted house!\n");
        }

        // check if the player found the exit
        if (playerLocation == exitLocation) {
            printf("Congratulations! You found the exit and escaped the haunted house!\n");
            isHaunted = 0;
            break;
        }

        // check if the player encountered the ghost
        if (playerLocation == ghostLocation) {
            printf("Oh no! You encountered the ghost and got spooked out of your mind!\n");
            printf("Better luck next time.\n");
            isHaunted = 0;
            break;
        }
    }

    return 0;
}