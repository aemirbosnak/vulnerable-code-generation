//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>

int main() {
    int board[8][8];
    int player = 1;
    int moves = 0;

    // Initialize the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = 0;
            } else if (i < 3) {
                board[i][j] = 1;
            } else if (i > 4) {
                board[i][j] = 2;
            } else {
                board[i][j] = 0;
            }
        }
    }

    // Play the game
    while (1) {
        // Print the board
        printf("\n");
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 0) {
                    printf(" ");
                } else if (board[i][j] == 1) {
                    printf("o");
                } else if (board[i][j] == 2) {
                    printf("x");
                }
            }
            printf("\n");
        }

        // Get the player's move
        int from_x, from_y, to_x, to_y;
        printf("Player %d's move: ", player);
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);

        // Check if the move is valid
        if (board[from_x][from_y] != player ||
            (player == 1 && from_x > to_x) ||
            (player == 2 && from_x < to_x) ||
            (to_x < 0 || to_x > 7 ||
             to_y < 0 || to_y > 7)) {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is a capture
        int captured = 0;
        if (abs(to_x - from_x) == 2 &&
            abs(to_y - from_y) == 2 &&
            board[(from_x + to_x) / 2][(from_y + to_y) / 2] != 0) {
            captured = 1;
            board[(from_x + to_x) / 2][(from_y + to_y) / 2] = 0;
        }

        // Make the move
        board[from_x][from_y] = 0;
        board[to_x][to_y] = player;

        // Check if the player has won
        int won = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == (3 - player)) {
                    won = 0;
                }
            }
        }

        if (won) {
            printf("Player %d wins!\n", player);
            break;
        }

        // Switch players
        player = 3 - player;
        moves++;
    }

    return 0;
}