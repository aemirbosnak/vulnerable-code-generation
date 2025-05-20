//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];   // 3x3 game board
char player1 = 'X';
char player2 = 'O';

/* Initialize the game board */
void initBoard(){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            board[i][j] = '-';
        }
    }
}

/* Display the game board */
void displayBoard(){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* Check if the game board is full */
int isBoardFull(){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == '-'){
                return 0;
            }
        }
    }
    return 1;
}

/* Check if the game is over */
int isGameOver(){
    int i, j;
    char symbol;

    // Check rows
    for(i=0; i<BOARD_SIZE; i++){
        symbol = board[i][0];
        for(j=1; j<BOARD_SIZE; j++){
            if(board[i][j] != symbol){
                break;
            }
        }
        if(j == BOARD_SIZE){
            return 1;
        }
    }

    // Check columns
    for(j=0; j<BOARD_SIZE; j++){
        symbol = board[0][j];
        for(i=1; i<BOARD_SIZE; i++){
            if(board[i][j] != symbol){
                break;
            }
        }
        if(i == BOARD_SIZE){
            return 1;
        }
    }

    // Check diagonals
    symbol = board[0][0];
    for(i=1; i<BOARD_SIZE; i++){
        if(board[i][i] != symbol){
            break;
        }
    }
    if(i == BOARD_SIZE){
        return 1;
    }

    symbol = board[0][BOARD_SIZE-1];
    for(i=1; i<BOARD_SIZE; i++){
        if(board[i][BOARD_SIZE-i-1] != symbol){
            break;
        }
    }
    if(i == BOARD_SIZE){
        return 1;
    }

    if(isBoardFull()){
        return 2;
    }

    return 0;
}

/* Get a random number between min and max */
int getRandomNumber(int min, int max){
    return min + rand() % (max - min + 1);
}

/* Get the next move for the computer player */
void getComputerMove(int *row, int *col){
    do{
        *row = getRandomNumber(0, BOARD_SIZE-1);
        *col = getRandomNumber(0, BOARD_SIZE-1);
    }while(board[*row][*col] != '-');
}

/* Get the next move for the human player */
void getHumanMove(int *row, int *col){
    printf("Enter row and column (1-3): ");
    scanf("%d %d", row, col);
    (*row)--;
    (*col)--;
}

/* Play the game */
void playGame(int mode){
    int player = 1;
    int row, col;
    int winner = 0;
    srand(time(NULL));  // seed the random number generator

    do{
        if(player == 1){
            if(mode == 1){
                getHumanMove(&row, &col);
            }
            else{
                getComputerMove(&row, &col);
                printf("Computer player chose row %d and column %d\n", row+1, col+1);
            }
            if(board[row][col] == '-'){
                board[row][col] = player1;
                player = 2;
            }
        }
        else{
            if(mode == 1){
                getHumanMove(&row, &col);
            }
            else{
                getComputerMove(&row, &col);
                printf("Computer player chose row %d and column %d\n", row+1, col+1);
            }
            if(board[row][col] == '-'){
                board[row][col] = player2;
                player = 1;
            }
        }

        displayBoard();
        winner = isGameOver();
    }while(winner == 0);

    // Print the game result
    if(winner == 1){
        printf("Player %d (%c) wins!\n", player, player=='X'?'X':'O');
    }
    else{
        printf("It's a draw!\n");
    }
}

/* Main function */
int main(){
    int choice;

    printf("Welcome to Tic Tac Toe Game\n");
    printf("Choose the game mode: \n");
    printf("1. Play against another human player\n");
    printf("2. Play against the computer player\n");
    scanf("%d", &choice);
    initBoard();
    displayBoard();
    playGame(choice);

    return 0;
}