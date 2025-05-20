//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    int turn;
} player_t;

player_t players[MAX_PLAYERS];

void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // No winner yet
    return 0;
}

int main() {
    // Initialize the game board
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Initialize the players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].turn = 0;
    }

    // Start the game loop
    int game_over = 0;
    while (!game_over) {
        // Get the current player
        int current_player = 0;
        while (players[current_player].turn == 0) {
            current_player++;
        }

        // Print the game board
        print_board(board);

        // Get the player's move
        int row, column;
        printf("%s, it's your turn. Enter the row and column of your move (e.g. 1 2): ", players[current_player].name);
        scanf("%d %d", &row, &column);

        // Check if the move is valid
        if (row < 1 || row > 3 || column < 1 || column > 3 || board[row - 1][column - 1] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Update the game board
        board[row - 1][column - 1] = players[current_player].name[0];

        // Check if the game is over
        int winner = check_winner(board);
        if (winner != 0) {
            game_over = 1;
            printf("%s wins!\n", winner);
        }

        // Update the player's turn
        players[current_player].turn = 0;
    }

    return 0;
}