//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(int board[ROWS][COLS]){
    printf("  1 2 3 4 5\n");
    for(int i=0; i<ROWS; i++){
        printf("%c ", 'A' + i);
        for(int j=0; j<COLS; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int validateRowCol(int row, int col){
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
        return 0;
    }
    return 1;
}

int validateMove(int board[ROWS][COLS], int row, int col){
    if(!validateRowCol(row, col)){
        printf("Invalid row and column selected. Try again.\n");
        return 0;
    }
    if(board[row][col] != 0){
        printf("That position is already taken. Try again.\n");
        return 0;
    }
    return 1;
}

int checkWin(int board[ROWS][COLS]){
    // Check for horizontal win
    for(int i=0; i<ROWS; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]){
            return 1;
        }
    }
    // Check for vertical win
    for(int j=0; j<COLS; j++){
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]){
            return 1;
        }
    }
    // Check for diagonal win
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]){
        return 1;
    }
    if(board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]){
        return 1;
    }
    return 0;
}

int main(){
    srand(time(NULL)); // seed the random number generator
    int board[ROWS][COLS] = {0}; // initialize the board with all zeros
    printBoard(board);
    int player1Turn = 1; // player 1 goes first
    while(1){
        int row, col;
        if(player1Turn){
            printf("Player 1 turn. Enter row and column (e.g. B3): ");
            scanf(" %c%d", &row, &col);
        }
        else{
            printf("Player 2 turn. Enter row and column (e.g. B3): ");
            scanf(" %c%d", &row, &col);
        }
        row -= 'A'; // convert row to index
        col -= 1; // convert col to index
        if(validateMove(board, row, col)){
            board[row][col] = player1Turn ? 1 : 2; // update the board with player's symbol
            printBoard(board);
            if(checkWin(board)){
                if(player1Turn){
                    printf("Player 1 wins!\n");
                }
                else{
                    printf("Player 2 wins!\n");
                }
                break;
            }
            player1Turn = !player1Turn; // switch turns
        }
    }
    return 0;
}