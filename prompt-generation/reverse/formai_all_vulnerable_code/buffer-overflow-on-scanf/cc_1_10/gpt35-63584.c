//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define constants
#define NUM_ROWS 3
#define NUM_COLS 3
#define MAX_PLAYERS 2

// Define global variables
int board[NUM_ROWS][NUM_COLS];
int current_turn;
char player_names[MAX_PLAYERS][20];
int player_scores[MAX_PLAYERS];

// Function to reset the game board
void reset_board() {
    // Set all cells to 0
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to display the game board
void display_board() {
    printf("\n");
    // Print the column numbers
    printf("  ");
    for (int j = 0; j < NUM_COLS; j++) {
        printf("%d ", j+1);
    }
    printf("\n");

    // Print the row numbers and cells
    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j] == 0) {
                printf("_ ");
            } else if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            }
        }
        printf("\n");
    }
}

// Function to check if the game is over
int check_game_over() {
    // Check rows
    for (int i = 0; i < NUM_ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < NUM_COLS; j++) {
            sum += board[i][j];
        }
        if (sum == 3 || sum == 6) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < NUM_COLS; j++) {
        int sum = 0;
        for (int i = 0; i < NUM_ROWS; i++) {
            sum += board[i][j];
        }
        if (sum == 3 || sum == 6) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] + board[1][1] + board[2][2] == 3 || board[0][2] + board[1][1] + board[2][0] == 3 || board[0][0] + board[1][1] + board[2][2] == 6 || board[0][2] + board[1][1] + board[2][0] == 6) {
        return 1;
    }

    // Check for a tie
    int count = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j] != 0) {
                count++;
            }
        }
    }
    if (count == NUM_ROWS*NUM_COLS) {
        return 2;
    }

    // Game is not over
    return 0;
}

// Function to get the next player's turn
int get_next_turn() {
    if (current_turn == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to handle a player's turn
void handle_turn() {
    // Display the game board
    display_board();

    // Get the player's input
    int row, col;
    while (1) {
        printf("%s's turn (X): ", player_names[current_turn]);
        scanf("%d%d", &row, &col);
        if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
            printf("Invalid input. Please enter row and column numbers between 1 and %d.\n", NUM_ROWS);
        } else if (board[row-1][col-1] != 0) {
            printf("That cell is already occupied. Please choose another cell.\n");
        } else {
            break;
        }
    }

    // Place the player's mark on the board
    board[row-1][col-1] = 1;

    // Check if the game is over
    int game_over = check_game_over();
    if (game_over == 1) {
        printf("%s wins!\n", player_names[current_turn]);
        player_scores[current_turn]++;
        reset_board();
    } else if (game_over == 2) {
        printf("Game over. It's a tie.\n");
        reset_board();
    } else {
        // Switch to the next player's turn
        current_turn = get_next_turn();
    }
}

// Main function
int main() {
    // Initialize the game
    reset_board();

    // Get the player names
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", player_names[i]);
    }

    // Set the first player's turn
    srand(time(NULL));
    current_turn = rand() % 2;

    // Start the game loop
    while (1) {
        handle_turn();
    }

    return 0;
}