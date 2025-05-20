//FormAI DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the board
void display(int board[][3]) {
    printf("\n");
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if there is a winner
int isWinner(int board[][3]) {
    int i, j;
    
    // Check horizontally
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    
    // Check vertically
    for(j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    
    // Check diagonally
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    
    // No winner
    return 0;
}

// Function to check if the board is full
int isFull(int board[][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Initialize board
    int board[3][3] = {{' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};
    
    // Initialize variables
    int player = 1;
    int row, col;
    
    // Display empty board
    display(board);
    
    // Game loop
    while(1) {
        // Get input from players
        printf("Player %d's turn. Enter row and column (1-3): ", player);
        scanf("%d %d", &row, &col);
        
        // Check for valid input
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if(board[row-1][col-1] != ' ') {
            printf("That spot is already taken. Try again.\n");
            continue;
        }
        
        // Update board
        if(player == 1) {
            board[row-1][col-1] = 'X';
        } else {
            board[row-1][col-1] = 'O';
        }
        
        // Display board
        display(board);
        
        // Check for winner or tie
        if(isWinner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        if(isFull(board)) {
            printf("It's a tie!\n");
            break;
        }
        
        // Switch players
        if(player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    
    return 0;
}