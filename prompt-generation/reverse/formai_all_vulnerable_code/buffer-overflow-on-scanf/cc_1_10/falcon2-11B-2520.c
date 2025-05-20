//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A global variable to keep track of the game state
int game_state = 0;

// A function to print the current state of the game
void print_board() {
    printf("  1 | 2 | 3\n");
    printf("---+---+---\n");
    printf("  4 | 5 | 6\n");
    printf("---+---+---\n");
    printf("  7 | 8 | 9\n");
}

// A function to check if the game is over
bool is_game_over() {
    // Check if the game is a tie
    if (game_state == 10) {
        return true;
    }
    // Check if the game has been won by player 1
    if (game_state == 1 || game_state == 2 || game_state == 3) {
        return true;
    }
    // Check if the game has been won by player 2
    if (game_state == 4 || game_state == 5 || game_state == 6) {
        return true;
    }
    // If none of the above conditions are met, the game is not over
    return false;
}

// A function to place a piece on the board
void place_piece(int row, int col) {
    // Check if the row and column are valid
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move!\n");
        return;
    }
    // Check if the cell is already occupied
    if (game_state & (1 << row)) {
        printf("Cell already occupied!\n");
        return;
    }
    // Mark the cell as occupied
    game_state |= (1 << row);
    // Print the updated board
    print_board();
}

// A function to play the game
int main() {
    int player_choice = 0;
    while (!is_game_over()) {
        // Print the current state of the game
        print_board();
        // Prompt the player to make a move
        printf("Player 1: Enter row and column (0-2): ");
        int row = scanf("%d", &player_choice);
        if (row == EOF) {
            printf("Invalid input!\n");
            continue;
        }
        int col = scanf("%d", &player_choice);
        if (col == EOF) {
            printf("Invalid input!\n");
            continue;
        }
        // Place the piece on the board
        place_piece(row, col);
        // Check if the game has been won by player 1
        if (is_game_over()) {
            printf("Player 1 wins!\n");
            break;
        }
    }
    return 0;
}