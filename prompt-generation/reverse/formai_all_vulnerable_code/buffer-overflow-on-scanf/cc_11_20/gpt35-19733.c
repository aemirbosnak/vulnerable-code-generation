//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables for the game
    int choice;
    int flashlight = 0;
    int key = 0;
    int ghost_encounter = 0;
    int escape = 0;

    // Introduction
    printf("Welcome to the Haunted House Simulator Game!\n");
    printf("You are currently standing in front of a spooky old house at night.\n");
    printf("Do you dare to enter? Enter 1 for Yes, 2 for No: ");
    scanf("%d", &choice);

    // If the user chooses not to enter
    if (choice == 2) {
        printf("You turn around and quickly run away.\n");
        printf("Game Over!\n");
        return 0;
    }

    // If the user chooses to enter
    printf("You slowly open the door and walk inside the haunted house.\n");

    // The game loop
    while (!escape) {
        // Display the options to the user
        printf("\nSelect an action:\n");
        printf("1. Look for the flashlight\n");
        printf("2. Search for the key\n");
        printf("3. Go to the second floor\n");
        printf("4. Look for the exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // If the user looks for the flashlight
                printf("\nYou are searching for the flashlight...\n");

                if (flashlight == 0) {
                    // If the user finds the flashlight
                    printf("You found the flashlight!\n");
                    flashlight = 1;
                } else {
                    // If the user has already found the flashlight
                    printf("You have already found the flashlight.\n");
                }

                break;

            case 2:
                // If the user searches for the key
                printf("\nYou are searching for the key...\n");

                if (key == 0) {
                    // If the user finds the key
                    printf("You found the key!\n");
                    key = 1;
                } else {
                    // If the user has already found the key
                    printf("You have already found the key.\n");
                }

                break;

            case 3:
                // If the user goes to the second floor
                printf("\nYou climb up the stairs to the second floor...\n");

                if (ghost_encounter == 0) {
                    // If the user hasn't encountered the ghost yet
                    printf("You suddenly hear a loud noise...\n");
                    printf("A ghost appears and blocks your way!\n");

                    if (flashlight == 1) {
                        // If the user has the flashlight
                        printf("You shine the flashlight on the ghost...\n");
                        printf("The ghost disappears!\n");
                        ghost_encounter = 1;
                    } else {
                        // If the user doesn't have the flashlight
                        printf("You don't have anything to defend yourself with!\n");
                        printf("The ghost attacks you and you die.\n");
                        printf("Game Over!\n");
                        return 0;
                    }
                } else {
                    // If the user has already encountered the ghost
                    printf("You've already been to the second floor and encountered the ghost.\n");
                }

                break;

            case 4:
                // If the user looks for the exit
                printf("\nYou're looking for the exit...\n");

                if (key == 1) {
                    // If the user has the key
                    printf("You found the exit and you use the key to open it.\n");
                    printf("Congratulations, you've escaped the haunted house!\n");
                    escape = 1;
                } else {
                    // If the user doesn't have the key
                    printf("The exit is locked. You need to find the key first.\n");
                }

                break;

            default:
                // If the user enters an invalid option
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}