//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY '.'

char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3)
                    board[i][j] = PLAYER1; // Player 1's pieces
                else if (i > 4)
                    board[i][j] = PLAYER2; // Player 2's pieces
                else
                    board[i][j] = EMPTY; 
            } else {
                board[i][j] = EMPTY; // Even squares are empty
            }
        }
    }
}

// Function to print the board
void print_board() {
    printf("Current Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to validate player move
int is_valid_move(int start_x, int start_y, int end_x, int end_y, char player) {
    // Check if the move is within bounds
    if (end_x < 0 || end_x >= BOARD_SIZE || end_y < 0 || end_y >= BOARD_SIZE) return 0;
    // Check if the start position has player's piece
    if (board[start_x][start_y] != player) return 0;
    // Check if end position is empty
    if (board[end_x][end_y] != EMPTY) return 0;

    // Check the direction of the move
    if (player == PLAYER1) {
        if (end_x - start_x == 1 && abs(end_y - start_y) == 1) return 1; // Normal move
        if (end_x - start_x == 2 && abs(end_y - start_y) == 2 && 
            board[(start_x + end_x) / 2][(start_y + end_y) / 2] == PLAYER2) {
            board[(start_x + end_x) / 2][(start_y + end_y) / 2] = EMPTY; // Capture move
            return 1;
        }
    } else if (player == PLAYER2) {
        if (start_x - end_x == 1 && abs(end_y - start_y) == 1) return 1; // Normal move
        if (start_x - end_x == 2 && abs(end_y - start_y) == 2 && 
            board[(start_x + end_x) / 2][(start_y + end_y) / 2] == PLAYER1) {
            board[(start_x + end_x) / 2][(start_y + end_y) / 2] = EMPTY; // Capture move
            return 1;
        }
    }
    return 0;
}

// Function to execute the player's move
void make_move(int start_x, int start_y, int end_x, int end_y, char player) {
    if (is_valid_move(start_x, start_y, end_x, end_y, player)) {
        board[end_x][end_y] = player;
        board[start_x][start_y] = EMPTY;
    } else {
        printf("Invalid move attempt! Please try again.\n");
    }
}

// Main game loop
int main() {
    initialize_board();
    print_board();
    
    int current_turn = 0;
    char players[2] = {PLAYER1, PLAYER2};
    int start_x, start_y, end_x, end_y;

    while (1) {
        printf("Player %d's turn (%c). Enter your move (start_x start_y end_x end_y): ", (current_turn + 1), players[current_turn]);
        if (scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y) != 4) {
            printf("Input error! Please use numbers only.\n");
            // Clear input buffer in case of error
            while (getchar() != '\n');
            continue;
        }
        
        if (start_x < 0 || start_x >= BOARD_SIZE || start_y < 0 || start_y >= BOARD_SIZE ||
            end_x < 0 || end_x >= BOARD_SIZE || end_y < 0 || end_y >= BOARD_SIZE) {
            printf("Coordinates out of bounds! Please try again.\n");
            continue;
        }

        make_move(start_x, start_y, end_x, end_y, players[current_turn]);
        print_board();
        current_turn = 1 - current_turn; // Switch turns between Player 1 and Player 2
    }
    return 0;
}