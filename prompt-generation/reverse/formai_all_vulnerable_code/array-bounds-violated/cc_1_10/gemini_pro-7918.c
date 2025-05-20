//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// The board is represented as a 2D array of characters.
char board[BOARD_SIZE][BOARD_SIZE];

// The player's symbol is 'X' and the AI's symbol is 'O'.
char player_symbol = 'X';
char ai_symbol = 'O';

// Function to initialize the board.
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board.
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

// Function to check if the player has won.
int player_wins() {
    // Check rows.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player_symbol && board[i][1] == player_symbol && board[i][2] == player_symbol) {
            return 1;
        }
    }

    // Check columns.
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player_symbol && board[1][j] == player_symbol && board[2][j] == player_symbol) {
            return 1;
        }
    }

    // Check diagonals.
    if (board[0][0] == player_symbol && board[1][1] == player_symbol && board[2][2] == player_symbol) {
        return 1;
    }
    if (board[0][2] == player_symbol && board[1][1] == player_symbol && board[2][0] == player_symbol) {
        return 1;
    }

    return 0;
}

// Function to check if the AI has won.
int ai_wins() {
    // Check rows.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == ai_symbol && board[i][1] == ai_symbol && board[i][2] == ai_symbol) {
            return 1;
        }
    }

    // Check columns.
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == ai_symbol && board[1][j] == ai_symbol && board[2][j] == ai_symbol) {
            return 1;
        }
    }

    // Check diagonals.
    if (board[0][0] == ai_symbol && board[1][1] == ai_symbol && board[2][2] == ai_symbol) {
        return 1;
    }
    if (board[0][2] == ai_symbol && board[1][1] == ai_symbol && board[2][0] == ai_symbol) {
        return 1;
    }

    return 0;
}

// Function to check if the game is a tie.
int is_tie() {
    // Check if all cells are filled.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

// Function to get the best move for the AI.
int get_best_move() {
    // Check if the AI can win in the next move.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai_symbol;
                if (ai_wins()) {
                    board[i][j] = ' ';
                    return i * 3 + j;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Check if the player can win in the next move.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player_symbol;
                if (player_wins()) {
                    board[i][j] = ' ';
                    return i * 3 + j;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Play the center square if it is available.
    if (board[1][1] == ' ') {
        return 4;
    }

    // Play a corner square if it is available.
    for (int i = 0; i < BOARD_SIZE; i += 2) {
        for (int j = 0; j < BOARD_SIZE; j += 2) {
            if (board[i][j] == ' ') {
                return i * 3 + j;
            }
        }
    }

    // Play a side square if it is available.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 1; j < BOARD_SIZE - 1; j += 2) {
            if (board[i][j] == ' ') {
                return i * 3 + j;
            }
        }
    }

    // Return -1 if no move is available.
    return -1;
}

// Function to play a move.
void play_move(int move) {
    int row = move / 3;
    int col = move % 3;
    board[row][col] = player_symbol;
}

// Function to play the game.
void play_game() {
    init_board();

    print_board();

    while (1) {
        // Get the player's move.
        printf("Enter your move (1-9): ");
        int move;
        scanf("%d", &move);

        // Play the player's move.
        play_move(move - 1);

        // Print the board.
        print_board();

        // Check if the player has won.
        if (player_wins()) {
            printf("You win! :)\n");
            break;
        }

        // Check if the game is a tie.
        if (is_tie()) {
            printf("Tie! :| \n");
            break;
        }

        // Get the AI's move.
        move = get_best_move();

        // Play the AI's move.
        play_move(move);

        // Print the board.
        print_board();

        // Check if the AI has won.
        if (ai_wins()) {
            printf("I win! :D\n");
            break;
        }

        // Check if the game is a tie.
        if (is_tie()) {
            printf("Tie! :| \n");
            break;
        }
    }
}

int main() {
    play_game();
    return 0;
}