//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>

// Constants
#define BOARD_SIZE 3
#define EMPTY_CELL ' '

// Functions
char get_player_input();
void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_for_winner(char board[BOARD_SIZE][BOARD_SIZE]);
void make_ai_move(char board[BOARD_SIZE][BOARD_SIZE]);

// Main function
int main() {
    // Initialize the board
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
    };

    // Display an empty board
    display_board(board);

    // Get the player's input
    char player_input = get_player_input();

    // Place the player's move on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_CELL) {
                board[i][j] = player_input;
                break;
            }
        }
    }

    // Check for a winner
    int winner = check_for_winner(board);
    if (winner == 0) {
        // No winner yet
        make_ai_move(board);
    }

    // Display the updated board
    display_board(board);

    // Check for a winner again
    winner = check_for_winner(board);
    if (winner == 0) {
        // No winner yet
        printf("It's a tie!\n");
    } else if (winner == 1) {
        // Player 1 wins
        printf("Player 1 wins!\n");
    } else {
        // AI wins
        printf("The AI wins!\n");
    }

    return 0;
}

// Get the player's input
char get_player_input() {
    // Get the player's input
    char input;
    printf("Enter your move (X or O): ");
    scanf(" %c", &input);

    // Validate the player's input
    while (input != 'X' && input != 'O') {
        printf("Invalid input. Please enter X or O: ");
        scanf(" %c", &input);
    }

    return input;
}

// Display the board
void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check for a winner
int check_for_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check for a winner in the rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY_CELL && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? 1 : 2;
        }
    }

    // Check for a winner in the columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != EMPTY_CELL && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j] == 'X' ? 1 : 2;
        }
    }

    // Check for a winner in the diagonals
    if (board[0][0] != EMPTY_CELL && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 'X' ? 1 : 2;
    }
    if (board[0][2] != EMPTY_CELL && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 'X' ? 1 : 2;
    }

    // No winner yet
    return 0;
}

// Make the AI move
void make_ai_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Find an empty cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_CELL) {
                // Place the AI's move on the board
                board[i][j] = 'O';
                return;
            }
        }
    }
}