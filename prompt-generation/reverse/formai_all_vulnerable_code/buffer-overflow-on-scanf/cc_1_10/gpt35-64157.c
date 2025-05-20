//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen() {
    system("clear || cls");
}

void pause() {
    printf("Press enter to continue...");
    while(getchar() != '\n');
    getchar();
}

int main() {
    int choice;
    char playerName[20];

    clearScreen();
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("Please enter your name: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = 0;

    clearScreen();
    printf("Hello, %s! You find yourself in a dark forest. What would you like to do?\n\n", playerName);

    while(choice != 3) {
        printf("1. Look around\n");
        printf("2. Walk forward\n");
        printf("3. Quit game\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                clearScreen();
                printf("You look around and see a torch. Do you pick it up?\n\n");
                printf("1. Yes\n");
                printf("2. No\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                if(choice == 1) {
                    clearScreen();
                    printf("You pick up the torch and see a door in front of you. What would you like to do?\n\n");
                    printf("1. Try to open the door\n");
                    printf("2. Walk away\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);

                    if(choice == 1) {
                        clearScreen();
                        printf("You open the door and find a room full of treasure! Congratulations, you win!\n\n");
                        pause();
                        choice = 3;
                    } else if (choice == 2) {
                        clearScreen();
                        printf("You decide to walk away and get lost in the forest.\n\n");
                        pause();
                    } else {
                        clearScreen();
                        printf("Invalid choice. Please try again.\n\n");
                        pause();
                    }
                } else if (choice == 2) {
                    clearScreen();
                    printf("You leave the torch behind and continue walking. You stumble upon a river. What would you like to do?\n\n");
                    printf("1. Follow the river\n");
                    printf("2. Cross the river\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);

                    if(choice == 1) {
                        clearScreen();
                        printf("You follow the river and find a village. Congratulations, you win!\n\n");
                        pause();
                        choice = 3;
                    } else if (choice == 2) {
                        clearScreen();
                        printf("You attempt to cross the river and drown. Game over.\n\n");
                        pause();
                        choice = 3;
                    } else {
                        clearScreen();
                        printf("Invalid choice. Please try again.\n\n");
                        pause();
                    }
                } else {
                    clearScreen();
                    printf("Invalid choice. Please try again.\n\n");
                    pause();
                }
                break;
            case 2:
                clearScreen();
                printf("You walk forward and fall into a pit. Game over.\n\n");
                pause();
                choice = 3;
                break;
            case 3:
                clearScreen();
                printf("Thank you for playing, %s!\n\n", playerName);
                break;
            default:
                clearScreen();
                printf("Invalid choice. Please try again.\n\n");
                pause();
                break;
        }
    }

    return 0;
}