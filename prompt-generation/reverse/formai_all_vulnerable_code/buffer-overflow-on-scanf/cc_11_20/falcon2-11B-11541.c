//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[100];
    printf("Welcome to the Adventure Game! What is your name? ");
    scanf("%s", name);

    printf("Hello %s! You are in a dark and mysterious forest. You can go north, south, east or west. Which way do you want to go? \n", name);
    char direction;
    scanf(" %c", &direction);

    if (direction == 'n') {
        printf("You walk north and find a small cave. What do you want to do? \n");
        printf("1. Enter the cave \n2. Go back \n");
        int choice;
        scanf(" %d", &choice);

        if (choice == 1) {
            printf("You enter the cave and find a treasure chest. What do you want to do? \n");
            printf("1. Open the chest \n2. Leave the cave \n");
            int choice2;
            scanf(" %d", &choice2);

            if (choice2 == 1) {
                printf("You open the chest and find a shiny diamond. Congratulations! You won the game. \n");
            } else {
                printf("You leave the cave and continue your journey. \n");
            }
        } else {
            printf("You go back the way you came. \n");
        }
    } else if (direction =='s') {
        printf("You walk south and find a river. What do you want to do? \n");
        printf("1. Cross the river \n2. Go back \n");
        int choice;
        scanf(" %d", &choice);

        if (choice == 1) {
            printf("You cross the river and find a castle. What do you want to do? \n");
            printf("1. Enter the castle \n2. Go back \n");
            int choice2;
            scanf(" %d", &choice2);

            if (choice2 == 1) {
                printf("You enter the castle and find a dragon guarding a treasure. What do you want to do? \n");
                printf("1. Fight the dragon \n2. Leave the castle \n");
                int choice3;
                scanf(" %d", &choice3);

                if (choice3 == 1) {
                    printf("You fight the dragon and win! You get the treasure. Congratulations! You won the game. \n");
                } else {
                    printf("You leave the castle and continue your journey. \n");
                }
            } else {
                printf("You go back the way you came. \n");
            }
        } else {
            printf("You go back the way you came. \n");
        }
    } else if (direction == 'e') {
        printf("You walk east and find a village. What do you want to do? \n");
        printf("1. Enter the village \n2. Go back \n");
        int choice;
        scanf(" %d", &choice);

        if (choice == 1) {
            printf("You enter the village and find a blacksmith. What do you want to do? \n");
            printf("1. Ask the blacksmith to make you a sword \n2. Leave the village \n");
            int choice2;
            scanf(" %d", &choice2);

            if (choice2 == 1) {
                printf("You ask the blacksmith to make you a sword and he does. Congratulations! You won the game. \n");
            } else {
                printf("You leave the village and continue your journey. \n");
            }
        } else {
            printf("You go back the way you came. \n");
        }
    } else if (direction == 'w') {
        printf("You walk west and find a cave. What do you want to do? \n");
        printf("1. Enter the cave \n2. Go back \n");
        int choice;
        scanf(" %d", &choice);

        if (choice == 1) {
            printf("You enter the cave and find a mysterious portal. What do you want to do? \n");
            printf("1. Go through the portal \n2. Leave the cave \n");
            int choice2;
            scanf(" %d", &choice2);

            if (choice2 == 1) {
                printf("You go through the portal and find yourself in a different world. Congratulations! You won the game. \n");
            } else {
                printf("You leave the cave and continue your journey. \n");
            }
        } else {
            printf("You go back the way you came. \n");
        }
    } else {
        printf("Invalid input. Please try again. \n");
    }
}