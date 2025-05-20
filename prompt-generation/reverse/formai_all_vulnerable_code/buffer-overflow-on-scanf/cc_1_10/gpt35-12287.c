//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 3
#define COL 3

char board[ROW][COL];
int row,col;

void displayBoard(){
    printf("\n");
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf(" %c ", board[i][j]);   
            if(j < COL-1) printf("|");
        }
        printf("\n");
        if(i < ROW-1) printf("---|---|---\n");
    }
}

int checkWin(){
    for(int i=0; i<COL; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) return 1;
    }
    for(int i=0; i<ROW; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) return 1;
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) return 1;
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) return 1;
    return 0;
}

int checkDraw(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(board[i][j] == ' ') return 0;   
        }
    }
    return 1;
}

void playerTurn(){
    int x,y,validInput;
    do{
        validInput = 1;
        printf("Enter row and col number to play (eg: 1 2) : ");
        scanf("%d %d", &x, &y);
        if(x < 1 || x > 3 || y < 1 || y > 3 || board[x-1][y-1] != ' ') {
            printf("Invalid input!\n");
            validInput = 0;
        } else {
            board[x-1][y-1] = 'X';
        }
    }while(validInput == 0);
}

void computerTurn(){
    int r,c;
    do{
        r = rand() % 3;
        c = rand() % 3;
    }while(board[r][c] != ' ');
    board[r][c] = 'O';
}

void startGame(){
    int currentPlayer, gameOver = 0;
    memset(board, ' ', sizeof(board));
    do{
        displayBoard();
        currentPlayer = currentPlayer == 0 ? 1 : 0;
        if(currentPlayer == 0) playerTurn();
        else computerTurn();
        if(checkWin()){
            displayBoard();
            printf("Player %d wins!\n", currentPlayer+1);
            gameOver = 1;
        } else if(checkDraw()){
            displayBoard();
            printf("Game draw!\n");
            gameOver = 1;
        }
    }while(gameOver == 0);
}

int main(){
    char choice;
    do{
        printf("Press any key to start the game...\n");
        scanf(" %c", &choice);
        startGame();
        printf("Play Again? (Y/N) : ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');
    return 0;
}