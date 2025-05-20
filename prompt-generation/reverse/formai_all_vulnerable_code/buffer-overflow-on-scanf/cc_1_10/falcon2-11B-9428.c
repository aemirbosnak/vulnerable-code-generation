//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    // Prompt the user for their name
    printf("Welcome to the Adventure Game! What is your name? ");
    char name[20];
    scanf("%s", name);

    // Welcome the user
    printf("Hello %s, welcome to the Adventure Game! \n", name);

    // Start the game
    printf("You find yourself in a dark forest. \n");

    // Options for the user
    printf("1. Walk straight\n2. Walk left\n3. Walk right\n4. Go back\n");

    // Get user input
    printf("What do you want to do? ");
    scanf("%d", &choice);

    // Handle user input
    switch (choice) {
        case 1:
            printf("You stumble upon a house. \n");
            printf("1. Knock on the door\n2. Keep walking\n");
            break;
        case 2:
            printf("You fall into a pit. \n");
            break;
        case 3:
            printf("You walk into a cave. \n");
            printf("1. Go in\n2. Go back\n");
            break;
        case 4:
            printf("You go back to the start of the game. \n");
            break;
        default:
            printf("Invalid option. \n");
            break;
    }

    // Continue looping until the user decides to quit
    while (choice!= 4) {
        printf("What do you want to do? ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("You find a treasure chest! \n");
                printf("1. Open it\n2. Leave it\n");
                break;
            case 2:
                printf("You continue your journey. \n");
                break;
            case 3:
                printf("You fall into a pit. \n");
                break;
            case 4:
                printf("You go back to the start of the game. \n");
                break;
            default:
                printf("Invalid option. \n");
                break;
        }
    }

    // End the game
    printf("Game over. Thanks for playing! \n");

    return 0;
}