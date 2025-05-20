//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int board[3][3]; // Tic Tac Toe board
int player = 1; // Player turn (1 or 2)
int total_moves = 0; // Total number of moves

// Function to display the board
void display_board() {
    printf("    1   2   3\n");
    for(int i=0;i<3;i++) {
        printf("  +---+---+---+\n");
        printf("%d | ", i+1);
        for(int j=0;j<3;j++) {
            if(board[i][j] == 1) {
                printf("X | ");
            } else if(board[i][j] == 2) {
                printf("O | ");
            } else {
                printf("  | ");
            }
        }
        printf("\n");
    }
    printf("  +---+---+---+\n");
}

// Function to check if the game is over
int check_gameover(int player) {
    // Check if there is a winner
    for(int i=0;i<3;i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    // Check if the game is a tie
    if(total_moves == 9) {
        return 2;
    }
    // Game is not over yet
    return 0;
}

// Function for computer's turn
void computer_turn() {
    int r, c;
    srand(time(NULL)); // Seed the random number generator
    do {
        r = rand() % 3;
        c = rand() % 3;
    } while(board[r][c] != 0); // Keep generating random numbers until an empty space is found
    board[r][c] = 2; // Place computer's turn on the board
    total_moves++; // Increment total number of moves
    printf("Computer placed an O at (%d,%d)\n", r+1, c+1);
}

int main() {
    int row, col, result;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\nComputer: O\n");
    printf("Player 1 goes first.\n\n");
    memset(board, 0, sizeof(board)); // Initialize all elements of board to 0
    do {
        display_board(); // Display the board
        printf("Player %d's turn. Enter row and column to place X: ", player);
        scanf("%d %d", &row, &col);
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input.");
            continue;
        }
        if(board[row-1][col-1] != 0) {
            printf("That spot is already taken. Try again.");
            continue;
        }
        board[row-1][col-1] = 1; // Place player's turn on the board
        total_moves++; // Increment total number of moves
        result = check_gameover(player); // Check if the game is over
        if(result == 1) { // Player has won
            printf("\nCongratulations! Player %d wins!\n", player);
            display_board();
            return 0;
        } else if(result == 2) { // Tie game
            printf("\nTie game! Nobody wins.\n");
            display_board();
            return 0;
        } else { // Game is not over yet, it's the computer's turn
            printf("\nPlayer %d placed an X at (%d,%d)\n", player, row, col);
            player = 2;
            computer_turn();
            result = check_gameover(2); // Check if the game is over
            if(result == 1) { // Computer has won
                printf("\nSorry, the computer wins. Better luck next time!\n");
                display_board();
                return 0;
            } else if(result == 2) { // Tie game
                printf("\nTie game! Nobody wins.\n");
                display_board();
                return 0;
            } else { // Game is not over yet, it's the player's turn again
                player = 1;
            }
        }
    } while(1); // Keep playing until the game is over
    return 0;
}