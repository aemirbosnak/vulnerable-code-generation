//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: standalone
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seeds the random number generator
    srand(time(NULL));
    // Introduction to the simulator
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself in front of an old, spooky mansion.\n");
    printf("Do you dare to enter? (y/n): ");

    char answer;
    scanf("%c", &answer);
    // Checks if the user wants to enter the haunted house
    if (answer == 'y') {
        printf("\nYou slowly open the creaky door and step inside...\n\n");
        bool has_key = false;
        // Generate a random number to determine the key's location
        int key_location = rand() % 3 + 1;
        printf("You are in the entrance hall of the haunted house.\n");
        printf("There are four doors in front of you and one behind you.\n");
        printf("Which door would you like to open? (1-4): ");

        int door_choice;
        scanf("%d", &door_choice);
        // Check which door the user wants to open and handle accordingly
        switch (door_choice) {
            case 1:
                printf("\nYou enter the first room.\n");
                printf("Oh no! The door is locked.\n");
                printf("You'll need to find a key to open it.\n");
                // Check if the user has the key
                if (has_key) {
                    printf("You use the key to unlock the door.\n");
                    printf("Inside, you find a dusty bookshelf filled with creepy books.\n");
                } else {
                    printf("You don't have the key. You'll need to find it.\n");
                }
                break;
            case 2:
                printf("\nYou enter the second room.\n");
                printf("It's dark and you can't see anything.\n");
                printf("You hear a strange noise in the distance.\n");
                printf("Do you want to use your flashlight? (y/n): ");

                scanf(" %c", &answer);
                if (answer == 'y') {
                    printf("\nYou turn on your flashlight and see a pile of bones on the floor.\n");
                } else {
                    printf("\nYou hear the strange noise getting closer...\n");
                    printf("Uh oh! Something just brushed up against your leg!\n");
                }
                break;
            case 3:
                printf("\nYou enter the third room.\n");
                printf("It's a small room with a chest in the middle.\n");
                printf("As you approach the chest, it suddenly opens and a ghostly figure appears!\n");
                printf("You faint from fear and wake up back at the entrance of the house.\n");
                printf("Would you like to try again? (y/n): ");

                scanf(" %c", &answer);
                if (answer == 'y') {
                    main();
                    return 0;
                } else {
                    printf("Thanks for playing!\n");
                    return 0;
                }
                break;
            case 4:
                printf("\nYou enter the fourth room.\n");
                printf("It's a kitchen with pots and pans hanging from the ceiling.\n");
                printf("You smell something delicious cooking on the stove.\n");
                printf("Do you want to eat it? (y/n): ");

                scanf(" %c", &answer);
                if (answer == 'y') {
                    printf("\nYou take a bite of the food and immediately regret it.\n");
                    printf("You feel sick and start hallucinating.\n");
                    printf("You see strange, terrifying visions and pass out.\n");
                    printf("When you wake up, you're back at the entrance of the house.\n");
                    printf("Would you like to try again? (y/n): ");

                    scanf(" %c", &answer);
                    if (answer == 'y') {
                        main();
                        return 0;
                    } else {
                        printf("Thanks for playing!\n");
                        return 0;
                    }
                } else {
                    printf("\nYou decide not to eat the food and explore the rest of the house.\n");
                }
                break;
            default:
                printf("That's not a valid choice. Please try again.\n");
                break;
        }
        // Check if the user found the key
        if (!has_key) {
            printf("\nYou look around the entrance hall and find a key on a dusty table.\n");
            printf("This must be the key to the locked room!\n");
            has_key = true;
        }
        // The user can leave the haunted house if they reach this point
        printf("You decide to leave the haunted house.\n");
        printf("Thanks for playing!\n");
    } else {
        printf("You decide not to enter the haunted house. Better safe than sorry!\n");
    }
    return 0;
}