//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
// Tic Tac Toe AI in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Define the board size
#define BOARD_SIZE 3

// Define the players
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the possible moves
#define MOVE_TOP_LEFT 1
#define MOVE_TOP_MIDDLE 2
#define MOVE_TOP_RIGHT 3
#define MOVE_MIDDLE_LEFT 4
#define MOVE_MIDDLE_MIDDLE 5
#define MOVE_MIDDLE_RIGHT 6
#define MOVE_BOTTOM_LEFT 7
#define MOVE_BOTTOM_MIDDLE 8
#define MOVE_BOTTOM_RIGHT 9

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Function to print the board
void print_board() {
    printf("  1 | 2 | 3 \n");
    printf("  ---------\n");
    printf("  4 | 5 | 6 \n");
    printf("  ---------\n");
    printf("  7 | 8 | 9 \n");
}

// Function to get the current player
char get_current_player() {
    static char current_player = PLAYER_X;
    if (current_player == PLAYER_X) {
        current_player = PLAYER_O;
    } else {
        current_player = PLAYER_X;
    }
    return current_player;
}

// Function to get the computer's move
int get_computer_move() {
    // Get a random move
    int move = rand() % 9 + 1;
    return move;
}

// Function to get the human's move
int get_human_move() {
    int move;
    while (true) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        if (move >= 1 && move <= 9) {
            break;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    return move;
}

// Function to check if the game is over
bool game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

// Function to make a move
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int move) {
    char current_player = get_current_player();
    board[move / BOARD_SIZE][move % BOARD_SIZE] = current_player;
}

// Function to play the game
void play_game() {
    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    // Print the board
    print_board();
    // Game loop
    while (true) {
        // Get the current player
        char current_player = get_current_player();
        // Get the current player's move
        int move;
        if (current_player == PLAYER_X) {
            move = get_human_move();
        } else {
            move = get_computer_move();
        }
        // Make the move
        make_move(board, move);
        // Check if the game is over
        if (game_over(board)) {
            break;
        }
        // Print the board
        print_board();
    }
    // Print the final board
    print_board();
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}