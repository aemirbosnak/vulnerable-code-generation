//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the tic tac toe board
void printBoard(char board[][3]) {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf("| ");
        for(int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// Function to check if someone has won 
char checkWin(char board[][3]) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    
    // Check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    return ' ';
}

// Generate a random move for the computer
void randomMove(char board[][3], int *row, int *col) {
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while(board[*row][*col] != ' ');
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int currentPlayer = 1; // Player 1 goes first
    char winner = ' ';
    int row, col;
    srand(time(NULL));
    
    printf("Welcome to Tic Tac Toe!\n");
    printBoard(board);
    
    while(winner == ' ') {
        if(currentPlayer == 1) {
            // Player's turn
            printf("Player's turn!\n");
            printf("Enter row and column (between 1 to 3): ");
            scanf("%d %d", &row, &col);
            
            row--; // Subtract 1 to convert to 0-indexed
            col--;
            
            if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                // Invalid move
                printf("Invalid move!\n");
                continue;
            }
            
            board[row][col] = 'X';
        } else {
            // Computer's turn
            printf("Computer's turn!\n");
            randomMove(board, &row, &col);
            board[row][col] = 'O';
        }
        
        printBoard(board);
        winner = checkWin(board);
        
        if(winner != ' ') {
            break;
        }
        
        currentPlayer = currentPlayer == 1 ? 2 : 1; // Switch players
    }
    
    printf("%c wins!\n", winner);
    
    return 0;
}