//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void game();
void end();

int main() {
    srand(time(NULL));
    int choice;

    intro();

    while(1) {
        printf("\nWhat would you like to do? ");
        printf("1. Play the game\n2. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                game();
                break;
            case 2:
                end();
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void intro() {
    printf("\nWelcome to the funniest text-based adventure game ever!\n");
    printf("You are a brave adventurer on a quest to find the legendary\n");
    printf("treasure of the ancient kingdom of Lulzoria. Good luck!\n\n");
}

void game() {
    int choice, random;
    char name[20];

    printf("\nFirst, let's create your character. What is your name? ");
    scanf("%s", name);

    printf("\nWelcome to Lulzoria, %s! You find yourself in front of a\n", name);
    printf("mysterious cave. Do you want to enter it? (y/n) ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        printf("\nYou enter the cave and see a fork in the road. Which way do you go?\n");
        printf("1. Left\n2. Right\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou go left and find a treasure chest! Do you open it? (y/n) ");
                scanf(" %c", &choice);

                if(choice == 'y' || choice == 'Y') {
                    printf("\nCongratulations! You found the legendary treasure of Lulzoria!\n");
                    printf("But wait... it was all a dream! You wake up in your bed.\n");
                    printf("Thanks for playing! Press any key to exit.\n");
                    getchar();
                    end();
                } else {
                    printf("\nYou decide not to open the chest and continue your journey.\n");
                }
                break;
            case 2:
                printf("\nYou go right and find a troll blocking your path. Do you fight it? (y/n) ");
                scanf(" %c", &choice);

                if(choice == 'y' || choice == 'Y') {
                    random = rand() % 2;

                    if(random == 0) {
                        printf("\nYou defeat the troll and continue your journey.\n");
                    } else {
                        printf("\nThe troll defeats you. Game over.\n");
                        printf("Press any key to try again.\n");
                        getchar();
                        main();
                    }
                } else {
                    printf("\nYou decide not to fight the troll and turn back.\n");
                }
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } else {
        printf("\nYou decide not to enter the cave and go home.\n");
        printf("Thanks for playing! Press any key to exit.\n");
        getchar();
        end();
    }
}

void end() {
    printf("\nThanks for playing the funniest text-based adventure game ever!\n");
    printf("Press any key to exit.\n");
    getchar();
}