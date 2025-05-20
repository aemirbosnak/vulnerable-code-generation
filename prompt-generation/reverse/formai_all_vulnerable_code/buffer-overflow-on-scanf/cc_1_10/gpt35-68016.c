//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tic Tac Toe game board
char board[3][3];

// initialize the board with blank spaces
void initializeBoard() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}

// display the board
void displayBoard() {
    printf("\n");
    printf("\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]); 
    printf("\n");
}

// check for a winner
char checkWinner() {
    // check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    
    // check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    
    // check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    // check if board is full
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                return ' ';
            }
        }
    }
    
    // if no winner and board is full, it's a tie
    return 'T';
}

// check if the move is valid
int isValidMove(int row, int col) {
    if(row<0 || row>2 || col<0 || col>2) {
        return 0;
    }
    if(board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

// AI's turn (uses random move strategy)
void aiMove() {
    int row, col, valid;
    do {
        row = rand() % 3;
        col = rand() % 3;
        valid = isValidMove(row, col);
    } while(!valid);
    board[row][col] = 'O';
}

int main() {
    srand(time(0)); // seed the random number generator
    
    int row, col;
    char winner;
    
    printf("-----------------------------\n");
    printf(" RETRO TIC-TAC-TOE GAME\n");
    printf("-----------------------------\n");
    printf(" Instructions: Enter row and column number (0-2) to make a move.\n\n");
    
    initializeBoard();
    displayBoard();
    
    // main game loop
    do {
        // human's turn
        do {
            printf("Your turn (X): ");
            scanf("%d%d", &row, &col);
        } while(!isValidMove(row, col));
        board[row][col] = 'X';
        
        // display updated board
        displayBoard();
        
        // check for winner
        winner = checkWinner();
        if(winner != ' ') {
            break;
        }
        
        // AI's turn
        aiMove();
        
        // display updated board
        printf("AI's turn (O):\n");
        displayBoard();
        
        // check for winner
        winner = checkWinner();
    } while(winner == ' ');
    
    // check who won or if it's a tie
    printf("GAME OVER!\n");
    if(winner == 'X') {
        printf("You won!\n");
    } else if(winner == 'O') {
        printf("You lost!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}