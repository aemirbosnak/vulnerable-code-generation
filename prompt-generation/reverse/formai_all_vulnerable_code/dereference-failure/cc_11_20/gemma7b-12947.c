//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 5
#define MAX_HEIGHT 5

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

int main() {
    // Create a 2D array to store the game board
    char **board = (char**)malloc(MAX_HEIGHT * sizeof(char*));
    for (int i = 0; i < MAX_HEIGHT; i++) {
        board[i] = (char*)malloc(MAX_WIDTH * sizeof(char));
    }

    // Initialize the game board
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            board[i][j] = EMPTY_CHAR;
        }
    }

    // Place the player piece on the board
    board[2][2] = PLAYER_CHAR;

    // Game loop
    int game_over = 0;
    while (!game_over) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (x < 0 || x >= MAX_WIDTH || y < 0 || y >= MAX_HEIGHT) {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is safe
        if (board[y][x] == WALL_CHAR) {
            printf("You hit a wall.\n");
            continue;
        }

        // Make the move
        board[y][x] = PLAYER_CHAR;

        // Check if the player has won
        game_over = check_win(board);

        // Print the board
        for (int i = 0; i < MAX_HEIGHT; i++) {
            for (int j = 0; j < MAX_WIDTH; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    // Free the game board
    for (int i = 0; i < MAX_HEIGHT; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

int check_win(char **board) {
    // Check rows
    for (int i = 0; i < MAX_HEIGHT; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == PLAYER_CHAR) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_WIDTH; j++) {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == PLAYER_CHAR) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == PLAYER_CHAR) {
        return 1;
    }

    // If all else fails, the player has not won
    return 0;
}