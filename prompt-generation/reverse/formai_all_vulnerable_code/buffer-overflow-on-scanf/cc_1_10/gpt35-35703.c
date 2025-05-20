//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3]; // tic-tac-toe 3 x 3 board
int selectedRow, selectedCol;

// function to display the board
void displayBoard() {
    printf("\n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c  \n\n", board[2][0], board[2][1], board[2][2]);
}

// function to check if given location is empty
int isLocationEmpty(int row, int col) {
    if(board[row][col] == ' ')
        return 1;
    else
        return 0;
}

// function to check if game has ended or not
int isGameOver() {
    int i, j;
    
    // check if any row or col has all the same symbols
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    
    // check if any diagonal has all the same symbols
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    
    // check if board is full
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    
    // game is tied
    return 2;
}

// function to get user's row and col input
void getUserInput() {
    printf("Enter the row and column where you want to place your symbol (e.g. 1 2): ");
    scanf("%d%d", &selectedRow, &selectedCol);
    selectedRow--;
    selectedCol--;
    
    if(selectedRow<0 || selectedRow>2 || selectedCol<0 || selectedCol>2) {
        printf("Invalid input. Row and column numbers must be between 1 and 3.\n");
        getUserInput();
    }
    
    if(!isLocationEmpty(selectedRow, selectedCol)) {
        printf("Selected location is not empty. Please select an empty location.\n");
        getUserInput();
    }
}

// function to generate AI player's random row and col
void generateAIInput() {
    srand(time(NULL));
    selectedRow = rand()%3;
    selectedCol = rand()%3;
    
    if(!isLocationEmpty(selectedRow, selectedCol))
        generateAIInput();
}

// function for AI player's turn
void aiTurn() {
    printf("AI player's turn.\n");
    generateAIInput();
    board[selectedRow][selectedCol] = 'O';
    displayBoard();
}

// main function
int main() {
    int gameStatus, playerTurn=1;
    
    // initialize the board
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
    
    // display the board
    displayBoard();
    
    // game loop
    while(1) {
        if(playerTurn) {
            getUserInput();
            board[selectedRow][selectedCol] = 'X';
            displayBoard();
            gameStatus = isGameOver();
            if(gameStatus == 1) {
                printf("You win!\n");
                break;
            }
            else if(gameStatus == 2) {
                printf("Game tied. Nobody wins.\n");
                break;
            }
            playerTurn = 0;
        }
        else {
            aiTurn();
            gameStatus = isGameOver();
            if(gameStatus == 1) {
                printf("AI player wins! Better luck next time.\n");
                break;
            }
            else if(gameStatus == 2) {
                printf("Game tied. Nobody wins.\n");
                break;
            }
            playerTurn = 1;
        }
    }
    
    return 0;
}