//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro() {
    printf("Welcome to the Retro Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the legendary treasure of the lost city of Atlantis.\n");
    printf("Are you ready to begin your journey? (y/n)");
    char choice;
    scanf("%c", &choice);
    if (choice == 'n') {
        exit(0);
    }
}

void game() {
    int health = 100;
    int gold = 0;
    int location = 1;
    char choice;
    srand(time(NULL));

    while (health > 0) {
        printf("\nYou are currently in location %d.\n", location);
        printf("You have %d gold and %d health.\n", gold, health);

        switch (location) {
            case 1:
                printf("You are standing at the entrance of a dark and mysterious forest.\n");
                printf("Do you want to enter the forest? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y') {
                    location = 2;
                } else {
                    printf("You turn back and leave the forest.\n");
                }
                break;
            case 2:
                printf("You are deep in the heart of the forest.\n");
                printf("You see a fork in the path ahead.\n");
                printf("Do you want to take the left path or the right path? (l/r)");
                scanf("%c", &choice);
                if (choice == 'l') {
                    location = 3;
                } else {
                    location = 4;
                }
                break;
            case 3:
                printf("You follow the left path and come across a river.\n");
                printf("Do you want to cross the river? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y') {
                    printf("You successfully cross the river.\n");
                    gold += rand() % 10 + 1;
                } else {
                    printf("You decide to turn back.\n");
                }
                break;
            case 4:
                printf("You follow the right path and come across a cave.\n");
                printf("Do you want to enter the cave? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y') {
                    location = 5;
                } else {
                    printf("You decide to turn back.\n");
                }
                break;
            case 5:
                printf("You are inside the dark and eerie cave.\n");
                printf("You see a shiny object in the distance.\n");
                printf("Do you want to investigate? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y') {
                    printf("You approach the object and realize it's a treasure chest!\n");
                    gold += rand() % 50 + 1;
                } else {
                    printf("You decide to leave the cave.\n");
                }
                break;
            default:
                printf("Invalid location.\n");
        }
    }

    if (health <= 0) {
        printf("\nGame over! You have died.\n");
    } else {
        printf("\nCongratulations! You have completed the game with %d gold.\n", gold);
    }
}

int main() {
    intro();
    game();
    return 0;
}