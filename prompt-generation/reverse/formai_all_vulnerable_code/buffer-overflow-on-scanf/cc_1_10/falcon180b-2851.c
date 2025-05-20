//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to print the game board
void printBoard(int board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

//Function to check if the game is won
int checkWin(int board[3][3]) {
    int i, j;
    //Check rows
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    //Check columns
    for(j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    //Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

//Function to initialize the game board
void initBoard(int board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = 0;
        }
    }
}

//Function to get input from the user
int getInput(int board[3][3]) {
    int x, y;
    printf("Enter your move: ");
    scanf("%d %d", &x, &y);
    if(x >= 1 && x <= 3 && y >= 1 && y <= 3 && board[x-1][y-1] == 0) {
        board[x-1][y-1] = 1;
        return 1;
    }
    return 0;
}

//Main function
int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player1 = 1, player2 = 2;
    int whoseTurn = 1;
    int gameWon = 0;
    int i;

    //Seed the random number generator
    srand(time(NULL));

    //Initialize the game board
    initBoard(board);

    //Print the game board
    printf("Tic Tac Toe\n");
    printBoard(board);

    while(gameWon == 0 && whoseTurn == 1) {
        if(getInput(board)) {
            //Check if the game is won
            if(checkWin(board)) {
                printf("Player %d wins!\n", whoseTurn);
                gameWon = 1;
            } else {
                whoseTurn = 2;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    while(gameWon == 0 && whoseTurn == 2) {
        if(getInput(board)) {
            //Check if the game is won
            if(checkWin(board)) {
                printf("Player %d wins!\n", whoseTurn);
                gameWon = 1;
            } else {
                whoseTurn = 1;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    //Print the game board
    printf("Tic Tac Toe\n");
    printBoard(board);

    return 0;
}