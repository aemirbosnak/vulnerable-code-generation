//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

// The current state of the board
char board[BOARD_SIZE][BOARD_SIZE];

// The player who is currently taking their turn
char current_player;

// The winner of the game, if there is one
char winner;

// Initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the game board to the console
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the game is over
bool is_game_over() {
    // Check for a win in any row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
            return true;
        }
    }

    // Check for a win in any column
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            winner = board[0][j];
            return true;
        }
    }

    // Check for a win in either diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = board[0][2];
        return true;
    }

    // Check for a tie
    bool tie = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                tie = false;
            }
        }
    }
    if (tie) {
        winner = 'T';
        return true;
    }

    // The game is not over yet
    return false;
}

// Get the next move from the player
void get_player_move() {
    int row, col;
    printf("Enter your move (row, col): ");
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        printf("Invalid move. Please enter a valid move (row, col): ");
        scanf("%d %d", &row, &col);
    }

    // Make the move
    board[row][col] = current_player;
}

// Get the next move from the AI
void get_ai_move() {
    // TODO: Implement the AI algorithm

    // For now, the AI will just make a random move
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != ' ');

    // Make the move
    board[row][col] = current_player;
}

// Play a game of Tic Tac Toe
void play_game() {
    // Initialize the game board
    init_board();

    // Set the current player to X
    current_player = 'X';

    // Play the game until it is over
    while (!is_game_over()) {
        // Get the next move from the current player
        if (current_player == 'X') {
            get_player_move();
        } else {
            get_ai_move();
        }

        // Print the game board
        print_board();

        // Switch the current player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    // Print the winner
    if (winner == 'X' || winner == 'O') {
        printf("%c wins!\n", winner);
    } else {
        printf("Tie!\n");
    }
}

// The main function
int main() {
    // Play a game of Tic Tac Toe
    play_game();

    return 0;
}