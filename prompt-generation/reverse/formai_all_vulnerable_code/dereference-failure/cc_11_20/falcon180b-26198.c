//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, num_matches = 0, player_turn = 1;
    int **board;
    char choice;
    srand(time(NULL));

    // Initialize the board with random numbers
    rows = 4;
    cols = 4;
    board = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        board[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            board[i][j] = rand() % 10;
        }
    }

    // Print the initial board
    printf("Welcome to the Memory Game!\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Start the game
    while (num_matches < 8) {
        printf("\nPlayer %d's turn.\n", player_turn);
        printf("Enter row and column: ");
        scanf("%d%c", &i, &choice);
        j = (choice - '0');
        if (board[i][j] == -1) {
            printf("You've already chosen this card!\n");
        } else if (board[i][j]!= -2) {
            board[i][j] = -1;
            if (board[i][j] == board[i][j + 1]) {
                num_matches++;
                board[i][j] = -2;
                board[i][j + 1] = -2;
            } else {
                board[i][j] = 0;
                printf("Try again!\n");
            }
        }
        if (num_matches == 8) {
            printf("\nCongratulations! You've won the game!\n");
            break;
        }
        if (player_turn == 1) {
            player_turn = 2;
        } else {
            player_turn = 1;
        }
    }

    // Print the final board
    printf("\nThe final board:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j]!= -2) {
                printf("%d ", board[i][j]);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}