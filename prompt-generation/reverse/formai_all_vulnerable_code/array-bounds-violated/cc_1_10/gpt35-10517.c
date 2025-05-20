//FormAI DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayBoard(int board[3][3]);
void generateRandomMove(int board[3][3]);
int checkWin(int board[3][3], int player);

int main() {
    // initialize the game board with 0's
    int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    
    // print the game instructions
    printf("Welcome to Retro Tic Tac Toe! The first player to get three in a row wins.\n");
    printf("The player with X's will go first. Enter your move as a row, column pair, e.g. 1 2.\n");
    
    // display the initial game board
    displayBoard(board);
    
    // seed the random number generator with the current time
    srand(time(0));
    
    // main game loop
    int player = 1;
    int row, col;
    while (1) {
        if (player == 1) {
            // player's turn
            printf("Player 1, enter your move: ");
            scanf("%d %d", &row, &col);
            // check if move is valid
            if (board[row-1][col-1] != 0) {
                printf("Invalid move, try again.\n");
                continue;
            }
            board[row-1][col-1] = 1;
        } else {
            // computer's turn
            printf("Computer is thinking...\n");
            generateRandomMove(board);
        }
        
        // display the updated game board
        displayBoard(board);
        
        // check for win
        if (checkWin(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        
        // switch to next player
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    return 0;
}

// display the Tic Tac Toe board
void displayBoard(int board[3][3]) {
    printf("\n  1 2 3 \n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// generate a random move for the computer player
void generateRandomMove(int board[3][3]) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != 0);
    board[row][col] = 2;
}

// check if the specified player has won
int checkWin(int board[3][3], int player) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}