//FormAI DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_MOVES 50

int main() {
    // Initialize game board
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Initialize player positions
    int player1_x = BOARD_SIZE/2, player1_y = BOARD_SIZE/2;
    int player2_x = BOARD_SIZE/2 + 1, player2_y = BOARD_SIZE/2 + 1;

    // Initialize game variables
    int moves = 0;
    int player_turn = 1;

    // Seed RNG
    srand(time(NULL));

    // Loop until maximum moves are reached
    while (moves < MAX_MOVES) {
        // Print board
        printf("Player %d's turn (%d moves left)\n", player_turn, MAX_MOVES - moves);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (i == player1_x && j == player1_y) {
                    printf("1");
                } else if (i == player2_x && j == player2_y) {
                    printf("2");
                } else {
                    printf("%d", board[i][j]);
                }
            }
            printf("\n");
        }

        // Get user input for move
        int move_x, move_y;
        printf("Enter x and y coordinates of move (separated by a space): ");
        scanf("%d %d", &move_x, &move_y);

        // Check if move is valid
        if (move_x >= 0 && move_x < BOARD_SIZE && move_y >= 0 && move_y < BOARD_SIZE) {
            if (abs(player1_x - move_x) <= 1 && abs(player1_y - move_y) <= 1 &&
                    abs(player2_x - move_x) > 1 && abs(player2_y - move_y) > 1) {
                // Move player 1
                player1_x = move_x;
                player1_y = move_y;

                // Increment moves and switch player turn
                moves++;
                player_turn = 2;
            } else if (abs(player2_x - move_x) <= 1 && abs(player2_y - move_y) <= 1 &&
                    abs(player1_x - move_x) > 1 && abs(player1_y - move_y) > 1) {
                // Move player 2
                player2_x = move_x;
                player2_y = move_y;

                // Increment moves and switch player turn
                moves++;
                player_turn = 1;
            } else {
                // Invalid move
                printf("Invalid move! Try again.\n");
            }
        } else {
            // Invalid coordinates
            printf("Invalid coordinates! Try again.\n");
        }
    }

    // Print game over message
    printf("Game over! Maximum moves reached.\n");

    return 0;
}