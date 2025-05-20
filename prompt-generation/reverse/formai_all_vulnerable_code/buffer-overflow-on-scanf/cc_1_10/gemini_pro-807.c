//GEMINI-pro DATASET v1.0 Category: Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the game board
char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

// Define the game state
enum GameState {
    PLAYING,
    X_WON,
    O_WON,
    DRAW
};

// Define the player symbols
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';

// Get the player symbol based on the player number
char get_player_symbol(int player) {
    return player == 1 ? X_SYMBOL : O_SYMBOL;
}

// Check if a row is a winning row
bool is_winning_row(char row[3]) {
    return row[0] == row[1] && row[1] == row[2] && row[0] != '-';
}

// Check if a column is a winning column
bool is_winning_column(char board[3][3], int column) {
    return board[0][column] == board[1][column] && board[1][column] == board[2][column] && board[0][column] != '-';
}

// Check if a diagonal is a winning diagonal
bool is_winning_diagonal(char board[3][3]) {
    return (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
           (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
}

// Check if the game is over
enum GameState check_game_over(char board[3][3]) {
    // Check for a winning row
    for (int i = 0; i < 3; i++) {
        if (is_winning_row(board[i])) {
            return board[i][0] == X_SYMBOL ? X_WON : O_WON;
        }
    }

    // Check for a winning column
    for (int i = 0; i < 3; i++) {
        if (is_winning_column(board, i)) {
            return board[0][i] == X_SYMBOL ? X_WON : O_WON;
        }
    }

    // Check for a winning diagonal
    if (is_winning_diagonal(board)) {
        return board[0][0] == X_SYMBOL ? X_WON : O_WON;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return PLAYING;
            }
        }
    }

    return DRAW;
}

// Print the game board
void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the game state
    enum GameState game_state = PLAYING;

    // Get the player input
    int player = 1;
    while (game_state == PLAYING) {
        printf("Player %d's turn:\n", player);
        print_board(board);

        int row, column;
        printf("Enter the row and column (1-3): ");
        scanf("%d %d", &row, &column);

        // Validate the input
        while (row < 1 || row > 3 || column < 1 || column > 3 || board[row - 1][column - 1] != '-') {
            printf("Invalid input. Enter the row and column (1-3): ");
            scanf("%d %d", &row, &column);
        }

        // Place the player's symbol on the board
        board[row - 1][column - 1] = get_player_symbol(player);

        // Check if the game is over
        game_state = check_game_over(board);

        // Switch to the next player
        player = 3 - player;
    }

    // Print the game result
    switch (game_state) {
        case X_WON:
            printf("Player 1 (X) wins!\n");
            break;
        case O_WON:
            printf("Player 2 (O) wins!\n");
            break;
        case DRAW:
            printf("Draw!\n");
            break;
    }

    return 0;
}