//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define MAX_TRIES 3

int main() {
    int board[SIZE][SIZE];
    int i, j, k, tries, matches = 0;
    char choice;
    int flag = 0;
    srand(time(NULL));
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }

    printf("\n\nWelcome to the Memory Game!\n");
    printf("There are %d cards on the board.\n", SIZE * SIZE / 2);
    printf("You have %d tries to match all the pairs.\n\n", MAX_TRIES);

    while (flag == 0 && tries < MAX_TRIES) {
        system("clear");
        printf("\n\nTurn %d:\n", tries + 1);
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == 1) {
                    printf(" %c ", 'A' + (i * SIZE + j));
                } else {
                    printf(" _ ");
                }
            }
            printf("\n");
        }

        printf("\nEnter your choice (row col): ");
        scanf("%c%c", &choice, &choice);
        i = choice - 'A';
        j = (choice - 'A') % SIZE;

        if (board[i][j] == 1) {
            printf("\nCorrect!\n");
            board[i][j] = 0;
            matches++;
        } else {
            printf("\nIncorrect. Try again.\n");
            board[i][j] = 2;
        }

        if (matches == SIZE * SIZE / 2) {
            flag = 1;
            printf("\nCongratulations! You win!\n");
        }

        tries++;
    }

    if (flag == 0) {
        printf("\nGame Over. You lose.\n");
    }

    return 0;
}