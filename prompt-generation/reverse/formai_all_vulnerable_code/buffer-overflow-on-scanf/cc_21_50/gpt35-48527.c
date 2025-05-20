//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaration of functions used in the program
void displayInstructions();
void displayBoard(int board[3][3]);
void playerTurn(int board[3][3], int playerMove);
void computerTurn(int board[3][3]);
int checkGameState(int board[3][3]);

// Main function
int main() {
    int board[3][3] = {0}; // A 3x3 2D array to represent the board where 0 represents empty cell, 1 represents player's move and 2 represents computer's move
    int playerMove; // To store player's move
    int gameState = 0; // To store current game state where 0 = ongoing, 1 = Player Wins, 2 = Computer Wins, 3 = Draw

    srand(time(0)); // To seed random number generator

    displayInstructions(); // Display game instructions
    displayBoard(board); // Display initial board

    // Loop until game is won or draw
    while(gameState == 0) {
        // Player's turn
        do {
            printf("Enter your move (1-9): ");
            scanf("%d", &playerMove);

            if(playerMove < 1 || playerMove > 9 || board[(playerMove-1)/3][(playerMove-1)%3] != 0) {
                printf("Invalid move! Try again.\n");
            }
        } while(playerMove < 1 || playerMove > 9 || board[(playerMove-1)/3][(playerMove-1)%3] != 0);

        playerTurn(board, playerMove); // Update board with player's move
        displayBoard(board); // Display updated board

        gameState = checkGameState(board); // Check game state after each turn

        if(gameState == 1) {
            printf("Congratulations! You won!\n");
            break;
        }
        else if(gameState == 3) {
            printf("It's a draw!\n");
            break;
        }

        // Computer's turn
        printf("Computer's turn:\n");
        computerTurn(board); // Update board with computer's move
        displayBoard(board); // Display updated board

        gameState = checkGameState(board); // Check game state after each turn

        if(gameState == 2) {
            printf("Sorry! You lost!\n");
            break;
        }
        else if(gameState == 3) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

// Function to display game instructions
void displayInstructions() {
    printf("Welcome to the Tic-Tac-Toe game!\n");
    printf("You will be playing against the computer.\n");
    printf("The game board is a 3x3 grid where each cell is numbered from 1 to 9.\n");
    printf("To make your move, enter the number of the cell where you want to place your X.\n");
    printf("The computer's moves will be represented with O.\n\n");
}

// Function to display current board
void displayBoard(int board[3][3]) {
    printf("    1   2   3\n");
    printf("1   %c | %c | %c \n", board[0][0]==1?'X':board[0][0]==2?'O':' ', board[0][1]==1?'X':board[0][1]==2?'O':' ', board[0][2]==1?'X':board[0][2]==2?'O':' ');
    printf("   -----------\n");
    printf("2   %c | %c | %c \n", board[1][0]==1?'X':board[1][0]==2?'O':' ', board[1][1]==1?'X':board[1][1]==2?'O':' ', board[1][2]==1?'X':board[1][2]==2?'O':' ');
    printf("   -----------\n");
    printf("3   %c | %c | %c \n", board[2][0]==1?'X':board[2][0]==2?'O':' ', board[2][1]==1?'X':board[2][1]==2?'O':' ', board[2][2]==1?'X':board[2][2]==2?'O':' ');
    printf("\n");
}

// Function to update board with player's move
void playerTurn(int board[3][3], int playerMove) {
    board[(playerMove-1)/3][(playerMove-1)%3] = 1;
}

// Function to update board with computer's move
void computerTurn(int board[3][3]) {
    int i, j;

    // Check for possible win for computer in each row, column and diagonal
    // First check for rows
    for(i=0; i<3; i++) {
        if(board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 0) {
            board[i][2] = 2;
            return;
        }
        else if(board[i][0] == 2 && board[i][2] == 2 && board[i][1] == 0) {
            board[i][1] = 2;
            return;
        }
        else if(board[i][1] == 2 && board[i][2] == 2 && board[i][0] == 0) {
            board[i][0] = 2;
            return;
        }
    }

    // Then check for columns
    for(j=0; j<3; j++) {
        if(board[0][j] == 2 && board[1][j] == 2 && board[2][j] == 0) {
            board[2][j] = 2;
            return;
        }
        else if(board[0][j] == 2 && board[2][j] == 2 && board[1][j] == 0) {
            board[1][j] = 2;
            return;
        }
        else if(board[1][j] == 2 && board[2][j] == 2 && board[0][j] == 0) {
            board[0][j] = 2;
            return;
        }
    }

    // Finally check for diagonals
    if(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 0) {
        board[2][2] = 2;
        return;
    }
    else if(board[0][0] == 2 && board[2][2] == 2 && board[1][1] == 0) {
        board[1][1] = 2;
        return;
    }
    else if(board[1][1] == 2 && board[2][2] == 2 && board[0][0] == 0) {
        board[0][0] = 2;
        return;
    }
    else if(board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 0) {
        board[2][0] = 2;
        return;
    }
    else if(board[0][2] == 2 && board[2][0] == 2 && board[1][1] == 0) {
        board[1][1] = 2;
        return;
    }
    else if(board[1][1] == 2 && board[2][0] == 2 && board[0][2] == 0) {
        board[0][2] = 2;
        return;
    }

    // Check for possible blocking of player
    // First check for rows
    for(i=0; i<3; i++) {
        if(board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 0) {
            board[i][2] = 2;
            return;
        }
        else if(board[i][0] == 1 && board[i][2] == 1 && board[i][1] == 0) {
            board[i][1] = 2;
            return;
        }
        else if(board[i][1] == 1 && board[i][2] == 1 && board[i][0] == 0) {
            board[i][0] = 2;
            return;
        }
    }

    // Then check for columns
    for(j=0; j<3; j++) {
        if(board[0][j] == 1 && board[1][j] == 1 && board[2][j] == 0) {
            board[2][j] = 2;
            return;
        }
        else if(board[0][j] == 1 && board[2][j] == 1 && board[1][j] == 0) {
            board[1][j] = 2;
            return;
        }
        else if(board[1][j] == 1 && board[2][j] == 1 && board[0][j] == 0) {
            board[0][j] = 2;
            return;
        }
    }

    // Finally check for diagonals
    if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 0) {
        board[2][2] = 2;
        return;
    }
    else if(board[0][0] == 1 && board[2][2] == 1 && board[1][1] == 0) {
        board[1][1] = 2;
        return;
    }
    else if(board[1][1] == 1 && board[2][2] == 1 && board[0][0] == 0) {
        board[0][0] = 2;
        return;
    }
    else if(board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 0) {
        board[2][0] = 2;
        return;
    }
    else if(board[0][2] == 1 && board[2][0] == 1 && board[1][1] == 0) {
        board[1][1] = 2;
        return;
    }
    else if(board[1][1] == 1 && board[2][0] == 1 && board[0][2] == 0) {
        board[0][2] = 2;
        return;
    }

    // If no possible winning or blocking moves are found, make a random move
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while(board[i][j] != 0);

    board[i][j] = 2;
}

// Function to check current game state
int checkGameState(int board[3][3]) {
    int i, j;

    // Check for winning moves for both players in each row
    for(i=0; i<3; i++) {
        if(board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
            return 1; // player wins
        }
        else if(board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2) {
            return 2; // computer wins
        }
    }

    // Check for winning moves for both players in each column
    for(j=0; j<3; j++) {
        if(board[0][j] == 1 && board[1][j] == 1 && board[2][j] == 1) {
            return 1; // player wins
        }
        else if(board[0][j] == 2 && board[1][j] == 2 && board[2][j] == 2) {
            return 2; // computer wins
        }
    }

    // Check for winning moves for both players in each diagonal
    if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        return 1; // player wins
    }
    else if(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        return 2; // computer wins
    }
    else if(board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        return 1; // player wins
    }
    else if(board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        return 2; // computer wins
    }

    // Check for draw
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == 0) {
                return 0; // Game is still ongoing
            }
        }
    }

    return 3; // Draw
}