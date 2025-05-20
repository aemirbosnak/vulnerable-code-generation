//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, isGhostAppeared = 0, isPlayerEscaped = 0;
    char playerName[50];

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("What's your name? ");
    scanf("%s", playerName);
    printf("\n");

    printf("You are standing in front of a haunted house.\n");
    printf("Do you want to enter? (1 for yes / 2 for no) ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 2) {
        printf("You decide not to enter the haunted house. The end.\n");
        return 0;
    }

    printf("As you enter the haunted house, the door creaks loudly behind you. You feel a chill run down your spine. \n\n");

    while (!isPlayerEscaped) {
        printf("You are currently in the foyer of the haunted house.\n");
        printf("There are three doors in front of you. One to your left, one in front of you and one to your right.\n");
        printf("Which door do you want to enter? (1 for left / 2 for front / 3 for right) ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("You enter the room on your left and find yourself in a dusty library. \n");
                printf("Suddenly, you hear a book fall behind you. You turn around to see the book floating in mid-air. \n");
                printf("Do you want to investigate the book or leave the room? (1 for investigate / 2 for leave) ");
                scanf("%d", &choice);
                printf("\n");

                if (choice == 1) {
                    printf("You walk towards the floating book and it suddenly flies towards you. \n");
                    printf("You panic and run out of the room. \n");
                    break;
                } else {
                    printf("You decide to leave the room and go back to the foyer. \n");
                    break;
                }

            case 2:
                printf("You enter the room in front of you and find yourself in a dark hallway. \n");
                printf("As you walk down the hallway, you see a figure at the end of it. \n");
                printf("The figure suddenly disappears. \n");
                printf("Do you want to investigate or leave the room? (1 for investigate / 2 for leave) ");
                scanf("%d", &choice);
                printf("\n");

                if (choice == 1) {
                    printf("You walk towards the end of the hallway and see nothing. Suddenly, the lights go out. \n");
                    printf("You hear footsteps, coming towards you. \n");
                    printf("Do you want to run back or stay? (1 for run / 2 for stay) ");
                    scanf("%d", &choice);
                    printf("\n");

                    if (choice == 1) {
                        printf("You try to run back, but trip and fall on the ground. \n");
                        printf("You hear a ghostly voice whisper 'Your time has come'.\n");
                        isGhostAppeared = 1;
                        break;
                    } else {
                        printf("You decide to stay calm and feel a cold breeze surround you. \n");
                        printf("Suddenly, the lights come back on and you notice the figure standing in front of you. \n");
                        printf("It's a ghost! You run out of the room.\n");
                        isGhostAppeared = 1;
                        break;
                    }

                } else {
                    printf("You decide to leave the room and go back to the foyer. \n");
                    break;
                }

            case 3:
                printf("You enter the room on your right and find yourself in a ballroom. \n");
                printf("You hear music playing in the background. Suddenly, you feel something tug at your dress. \n");
                printf("Do you want to investigate or leave the room? (1 for investigate / 2 for leave) ");
                scanf("%d", &choice);
                printf("\n");

                if (choice == 1) {
                    printf("You start to investigate the room and notice a pair of ghostly dancers. \n");
                    printf("They stop dancing and start to move towards you. You run out of the room. \n");
                    break;
                } else {
                    printf("You decide to leave the room and go back to the foyer. \n");
                    break;
                }
        }

        if (isGhostAppeared) {
            printf("%s has been caught by the ghost. Game Over.\n", playerName);
            break;
        } else {
            printf("Do you want to continue exploring? (1 for yes / 2 for no) ");
            scanf("%d", &choice);
            printf("\n");

            if (choice == 2) {
                printf("%s has escaped the haunted house. Congratulations!.\n", playerName);
                isPlayerEscaped = 1;
            }
        }
    }

    return 0;
}