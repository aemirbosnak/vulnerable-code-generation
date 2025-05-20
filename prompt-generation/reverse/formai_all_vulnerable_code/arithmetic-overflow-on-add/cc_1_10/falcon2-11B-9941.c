//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 1000

int main() {
    srand(time(NULL));  // Seed the random number generator

    int rolls = 0;
    int wins[2];
    int player1, player2;

    while (rolls < MAX_ROLLS) {
        player1 = rand() % 6 + 1;
        player2 = rand() % 6 + 1;

        printf("Player 1 rolled %d\n", player1);
        printf("Player 2 rolled %d\n", player2);

        // Check if both players rolled the same number
        if (player1 == player2) {
            printf("Both players rolled the same number!\n");
        } else {
            // Check if Player 1 or Player 2 won the round
            if (player1 > player2) {
                printf("Player 1 wins the round!\n");
                wins[0]++;
            } else if (player2 > player1) {
                printf("Player 2 wins the round!\n");
                wins[1]++;
            }
        }

        printf("Rolls: %d\n", rolls);
        printf("Player 1 wins: %d\n", wins[0]);
        printf("Player 2 wins: %d\n\n", wins[1]);

        printf("Do you want to roll again? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
        rolls++;
    }

    printf("Game over!\n");
    printf("Player 1 wins: %d\n", wins[0]);
    printf("Player 2 wins: %d\n\n", wins[1]);

    return 0;
}