//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up random generator
    srand(time(NULL));

    // Initializing variables
    int ghost_appears = 0;
    int flashlight_batteries = 2;
    int num_attempts = 0;

    // Intro message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a spooky old house.\n");
    printf("You have a flashlight with %d batteries left.\n", flashlight_batteries);

    // Main game loop
    while (1) {
        // Prompt for action
        printf("\nWhat would you like to do? (1 = enter house, 2 = leave game)\n");
        int action;
        scanf("%d", &action);

        if (action == 1) {
            // Random chance of ghost appearing
            if (rand() % 2 == 0) {
                printf("\nA ghost suddenly appears and scares you!\n");
                ghost_appears = 1;
            }

            // Check for flashlight battery usage
            if (flashlight_batteries > 0) {
                printf("\nYou enter the house and use your flashlight to look around.\n");
                printf("You find a dusty old painting on the wall and a creaky staircase leading up to the second floor.\n");

                // Prompt for action on the first floor
                printf("\nWhat would you like to do? (1 = look at painting, 2 = go upstairs)\n");
                scanf("%d", &action);

                if (action == 1) {
                    printf("\nYou examine the painting and don't find anything out of the ordinary.\n");
                }
                else if (action == 2) {
                    printf("\nYou climb the creaky staircase to the second floor.\n");

                    // Check for flashlight battery usage
                    if (rand() % 2 == 0 && flashlight_batteries > 0) {
                        printf("\nYour flashlight flickers and goes out, leaving you in complete darkness!\n");
                        flashlight_batteries--;
                    }
                    else {
                        printf("\nYou reach the second floor and find a dark hallway with several closed doors.\n");

                        // Prompt for action on the second floor
                        printf("\nWhat would you like to do? (1 = try first door, 2 = try second door, 3 = try third door)\n");
                        scanf("%d", &action);

                        if (action == 1 || action == 2 || action == 3) {
                            printf("\nYou try to open the door, but it is locked.\n");
                        }
                        else {
                            printf("\nInvalid input!\n");
                            continue;
                        }
                    }
                }
                else {
                    printf("\nInvalid input!\n");
                    continue;
                }
            }
            else {
                printf("\nYour flashlight is out of batteries and you can't enter the house.\n");
                continue;
            }
        }
        else if (action == 2) {
            // Exit game option
            printf("\nThanks for playing the Haunted House Simulator!\n");
            break;
        }
        else {
            printf("\nInvalid input!\n");
            continue;
        }

        // Increment number of attempts
        num_attempts++;

        if (ghost_appears) {
            printf("\nGame over! You were too scared by the ghost and ran away after %d attempts.\n", num_attempts);
            break;
        }
        else if (num_attempts >= 10) {
            printf("\nCongratulations, you successfully explored the haunted house without encountering any ghosts!\n");
            break;
        }
    }

    return 0;
}