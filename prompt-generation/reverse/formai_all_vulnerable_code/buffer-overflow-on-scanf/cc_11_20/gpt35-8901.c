//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int ghosts = rand() % 10 + 1;
    int rooms = rand() % 10 + 1;
    int currentRoom = 1;
    int hasKey = 0;
    int isAlive = 1;

    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("You are currently in room %d.\n", currentRoom);

    while (isAlive && currentRoom <= rooms) {
        if (currentRoom == rooms) {
            if (hasKey) {
                printf("\nCongratulations! You have found the key and escaped the haunted house!\n");
            } else {
                printf("\nYou have reached the last room of the house, but you do not have the key to escape.\n");
                printf("You are trapped in the haunted house forever. Game over!\n");
            }
            break;
        }

        printf("\nYou hear something in the distance...\n");
        if (rand() % 2) {
            printf("Oh no! You have encountered a ghost!\n");
            if (ghosts == 1) {
                printf("There is 1 ghost in the room with you... Good luck!\n");
            } else {
                printf("There are %d ghosts in the room with you... Good luck!\n", ghosts);
            }

            int escaped = 0;
            while (ghosts && !escaped) {
                printf("\nWhat will you do?\n");
                printf("1. Run\n");
                printf("2. Fight\n");
                int choice;
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        if (rand() % 2) {
                            printf("\nYou successfully escaped the ghosts!\n");
                            escaped = 1;
                        } else {
                            printf("\nSorry, you failed to escape the ghosts and lost a life.\n");
                            ghosts--;
                            if (!ghosts) {
                                printf("You have died! Game over!\n");
                                isAlive = 0;
                            }
                        }
                        break;
                    case 2:
                        if (rand() % 2) {
                            printf("\nYou successfully defeated the ghosts!\n");
                            ghosts--;
                        } else {
                            printf("\nSorry, you failed to defeat the ghosts and lost a life.\n");
                            ghosts--;
                            if (!ghosts) {
                                printf("You have died! Game over!\n");
                                isAlive = 0;
                            }
                        }
                        break;
                    default:
                        printf("\nInvalid choice!\n");
                }
            }
        } else {
            printf("Phew! That was a close one. There are no ghosts in the room.\n");
        }

        if (isAlive) {
            printf("\nYou can choose to go to the next room or search the current room for a key.\n");
            printf("1. Go to the next room\n");
            printf("2. Search for key\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    currentRoom++;
                    printf("\nYou are now in room %d.\n", currentRoom);
                    break;
                case 2:
                    if (rand() % 2) {
                        printf("\nCongratulations! You have found the key!\n");
                        hasKey = 1;
                    } else {
                        printf("\nSorry, you did not find the key.\n");
                    }
                    break;
                default:
                    printf("\nInvalid choice!\n");
            }
        }
    }

    return 0;
}