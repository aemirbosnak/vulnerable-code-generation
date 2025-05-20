//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include <stdio.h>

#define SIZE 8

int main() {
    char board[SIZE][SIZE] = {
        {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
        {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
        {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
        {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
        {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '}
    };

    int player = 1, row, col;
    char move[3];

    printf("Welcome to Checkers Game!\n");
    printf("Player 1: Red pieces (r)\n");
    printf("Player 2: Black pieces (b)\n");

    while(1) {
        printf("\nCurrent board:\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", i+1);
            for (int j = 0; j < SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("  a b c d e f g h\n");

        if (player == 1) {
            printf("Player 1 (Red), enter move (e.g. a3-b4): ");
        } else {
            printf("Player 2 (Black), enter move (e.g. a6-b5): ");
        }
        scanf("%s", move);

        col = move[0] - 'a';
        row = move[1] - '1';

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[row][col] == ' ') {
            printf("No piece in that location.\n");
            continue;
        }

        if (player == 1 && board[row][col] != 'r') {
            printf("Invalid piece selected.\n");
            continue;
        }

        if (player == 2 && board[row][col] != 'b') {
            printf("Invalid piece selected.\n");
            continue;
        }

        if (move[2] != '-' || row > 6) {
            printf("Invalid move.\n");
            continue;
        }

        int end_col = move[3] - 'a';
        int end_row = move[4] - '1';

        if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        int diff_col = end_col - col;
        int diff_row = end_row - row;

        if (board[end_row][end_col] != ' ' || (diff_col != 1 && diff_col != -1) || (diff_row != 1 && diff_row != -1)) {
            printf("Invalid move.\n");
            continue;
        }

        if (player == 1 && diff_row != -1) {
            printf("Invalid move.\n");
            continue;
        }

        if (player == 2 && diff_row != 1) {
            printf("Invalid move.\n");
            continue;
        }

        board[row][col] = ' ';
        if (player == 1) {
            board[end_row][end_col] = 'r';
        } else {
            board[end_row][end_col] = 'b';
        }

        if (diff_col == 2) {
            int capture_row = row + (diff_row / 2);
            int capture_col = col + (diff_col / 2);
            board[capture_row][capture_col] = ' ';
            printf("Captured piece at %c%d.\n", capture_col+'a', capture_row+1);
        }

        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    return 0;
}