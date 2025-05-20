//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic Tac Toe board
int player_turn = 1; // Player 1 plays first
int game_over = 0; // Game starts as not over

// Function to print Tic Tac Toe board
void printBoard() {
    printf("-------------\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("-------------\n");
    }
}

// Function to check if game is over (win/draw)
void checkGameOver() {
    // Check if any row has all same symbol
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            game_over = 1;
            return;
        }
    }
    // Check if any column has all same symbol
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            game_over = 1;
            return;
        }
    }
    // Check if any diagonal has all same symbol
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        game_over = 1;
        return;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        game_over = 1;
        return;
    }
    // Check if all positions have been occupied (draw)
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return;
            }
        }
    }
    game_over = 1; // Game is a draw
}

// Function for AI's move
void aiMove() {
    srand(time(NULL)); // Seed random number generator
    int i, j;
    i = rand() % 3; // Generate random row index
    j = rand() % 3; // Generate random column index
    while(board[i][j] != '-') { // Make sure position is unoccupied
        i = rand() % 3;
        j = rand() % 3;
    }
    board[i][j] = 'O'; // Place AI's symbol at position
    printf("AI played at: (%d,%d)\n", i+1, j+1);
}

// Main function
int main() {
    // Initialize board with blank spaces
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
    while(!game_over) {
        printBoard(); // Print board before each move
        if(player_turn == 1) {
            // Player's move
            int i, j;
            printf("Enter row (1-3): ");
            scanf("%d", &i);
            printf("Enter column (1-3): ");
            scanf("%d", &j);
            if(board[i-1][j-1] != '-') {
                printf("Invalid move. Please try again.\n");
                continue;
            }
            board[i-1][j-1] = 'X'; // Place player's symbol at position
        } else {
            // AI's move
            aiMove();
        }
        checkGameOver(); // Check if game is over after each move
        player_turn = !player_turn; // Switch turn between player and AI
    }
    if(!player_turn) {
        printf("Player wins!\n");
    } else {
        printf("AI wins!\n");
    }
    printBoard(); // Print final board
    return 0;
}