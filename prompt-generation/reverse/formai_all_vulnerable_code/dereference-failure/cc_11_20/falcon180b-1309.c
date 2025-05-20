//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int i, j, n, matches = 0;
    char **board;
    char *choices = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    srand(time(NULL));

    board = (char **)malloc(SIZE * sizeof(char *));
    for (i = 0; i < SIZE; i++) {
        board[i] = (char *)malloc(SIZE * sizeof(char));
        for (j = 0; j < SIZE; j++) {
            board[i][j] = choices[rand() % 26];
        }
    }

    printf("Welcome to the Memory Game!\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    while (matches < SIZE * SIZE) {
        printf("Your turn: ");
        scanf("%d%d", &i, &j);
        if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && board[i][j]!= '\0') {
            printf("You chose %c\n", board[i][j]);
            if (board[i][j] == board[i][j + 1]) {
                matches++;
                board[i][j] = '\0';
                board[i][j + 1] = '\0';
            } else {
                board[i][j] = 'X';
                board[i][j + 1] = 'X';
            }
        } else {
            printf("Invalid choice.\n");
        }
        printf("\n");
    }

    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    if (matches == SIZE * SIZE) {
        printf("\nCongratulations! You won!\n");
    } else {
        printf("\nSorry, you lost.\n");
    }

    for (i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}