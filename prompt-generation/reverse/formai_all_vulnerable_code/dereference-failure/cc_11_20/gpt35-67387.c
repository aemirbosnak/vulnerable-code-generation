//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_board(int n, char board[][n]);
int check_winner(int n, char board[][n], char c);

int main() {
    int n;
    printf("Enter board size: ");
    scanf("%d", &n);

    // dynamically allocate two-dimensional array
    char **board = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        board[i] = malloc(n * sizeof(char));
    }

    // initialize board with all spaces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = ' ';
        }
    }

    int moves_left = n * n;
    char player = 'X';

    while (moves_left > 0) {
        display_board(n, board);

        printf("\nPlayer %c's turn.", player);
        int row, col;

        do {
            // get valid move from player
            printf("\nEnter row and column numbers (1 to %d): ", n);
            scanf("%d %d", &row, &col);
            row--;
            col--;
        } while (row < 0 || row >= n || col < 0 || col >= n || board[row][col] != ' ');

        board[row][col] = player;

        // check for winner
        if (check_winner(n, board, player)) {
            printf("\nPlayer %c wins!\n", player);
            display_board(n, board);
            return 0;
        }

        // switch players
        player = (player == 'X') ? 'O' : 'X';
        moves_left--;
    }

    // tie game
    printf("\nTie game!\n");
    display_board(n, board);

    // free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

// function to display the board
void display_board(int n, char board[][n]) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf(" %c |", board[i][0]);
        for (int j = 1; j < n; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        if (i != n-1) {
            printf("---+");
            for (int j = 1; j < n; j++){
                printf("---+");
            }
            printf("\n");
        }
    }
}

// function to check for a winner
int check_winner(int n, char board[][n], char c) {
    // check rows
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == c) {
                count++;
            }
        }
        if (count == n) {
            return 1;
        }
    }

    // check columns
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][j] == c) {
                count++;
            }
        }
        if (count == n) {
            return 1;
        }
    }

    // check diagonals
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (board[i][i] == c) {
            count++;
        }
    }
    if (count == n) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (board[i][n-i-1] == c) {
            count++;
        }
    }
    if (count == n) {
        return 1;
    }

    return 0;
}