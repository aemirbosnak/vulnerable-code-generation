//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int score = 0;
    int room = 1;
    int exitFound = 0;
    int ghostCount = 0;
    int treasureFound = 0;
    int keyFound = 0;

    printf("Welcome to the Haunted House!\n");
    printf("You are in room %d.\n", room);

    while (exitFound == 0) {
        printf("What would you like to do?\n");
        printf("1. Explore the room\n");
        printf("2. Search for an exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("You search the room and find a treasure!\n");
            treasureFound = 1;
            score += 10;
            break;
        case 2:
            if (room == 1) {
                printf("You find a key!\n");
                keyFound = 1;
            }
            else if (room == 2) {
                printf("You find an exit!\n");
                exitFound = 1;
            }
            else if (room == 3) {
                printf("You find an exit!\n");
                exitFound = 1;
            }
            break;
        default:
            printf("Invalid choice.\n");
        }

        if (room == 1) {
            if (ghostCount == 0) {
                printf("A ghost appears!\n");
                ghostCount++;
            }
        }
        else if (room == 2) {
            if (keyFound == 0 && ghostCount == 0) {
                printf("A ghost appears!\n");
                ghostCount++;
            }
        }
        else if (room == 3) {
            if (treasureFound == 0 && ghostCount == 0) {
                printf("A ghost appears!\n");
                ghostCount++;
            }
        }

        if (ghostCount > 0) {
            printf("You lose 5 points for being scared by the ghost.\n");
            score -= 5;
            ghostCount = 0;
        }
    }

    printf("You escape the haunted house with a score of %d!\n", score);

    return 0;
}