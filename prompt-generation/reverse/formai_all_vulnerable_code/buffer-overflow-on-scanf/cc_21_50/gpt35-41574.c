//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the game board
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    // Randomize starting player
    srand(time(NULL));
    int player = rand() % 2;
    printf("Player %d goes first!\n", player + 1);

    // Game loop
    int turn = 0;
    int winner = 0;
    while (!winner && turn < 9) {
        // Print current board state
        printf("   1   2   3\n");
        printf("1  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("  ---+---+---\n");
        printf("2  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("  ---+---+---\n");
        printf("3  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

        // Get current player's move
        int row, col;
        do {
            printf("Player %d, enter your move (row column): ", player + 1);
            scanf("%d %d", &row, &col);
            row--;
            col--;
        } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-');

        // Make move
        board[row][col] = player ? 'O' : 'X';

        // Check for winner
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
                winner = player + 1;
                break;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
                winner = player + 1;
                break;
            }
        }
        if (!winner && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
            winner = player + 1;
        }
        if (!winner && board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
            winner = player + 1;
        }

        // Switch players for next turn
        player = !player;

        turn++;
    }

    // Print final board state
    printf("   1   2   3\n");
    printf("1  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

    // Print winner or tie
    if (winner) {
        printf("Player %d is the winner!\n", winner);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}