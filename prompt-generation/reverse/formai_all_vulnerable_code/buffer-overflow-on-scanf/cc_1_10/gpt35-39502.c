//FormAI DATASET v1.0 Category: Table Game ; Style: Donald Knuth
//Donald Knuth inspired C table game program
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printGameBoard(int board[3][3]){
    printf("\n");
    for(int i=0;i<3;i++){
        printf("\t\t|---|---|---|\n");
        for(int j=0;j<3;j++){
            if(board[i][j]==0)
                printf("\t\t|   ");
            else if(board[i][j]==1)
                printf("\t\t| X ");
            else
                printf("\t\t| O ");
        }
        printf("\t\t|\n");
    }
    printf("\t\t|---|---|---|\n\n");
}

void checkForResult(int board[3][3], int *winner){
    //Checking Rows for result
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            *winner = board[i][0];
            return;
        }
    }
    //Checking Columns for result
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            *winner = board[0][i];
            return;
        }
    }
    //Checking Diagonals for result
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        *winner=board[0][0];
        return;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        *winner=board[0][2];
        return;
    }
}

int main(){
    printf("\n\nWelcome to C Table Game!\n");
    printf("The game board is denoted by the numbers 1-9.\n");
    printf("Player X goes first and O follows.\n");
    printf("The game is won by the player who first gets three of their respective symbols in a row, column or diagonal.\n\n");

    int gameBoard[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int turns=0;
    int player=1;
    int winner=0;
    int i,j,pos;

    while(turns < 9 && winner==0){
        printGameBoard(gameBoard);
        printf("Player %d, enter a location: ",player);
        scanf("%d",&pos);
        if(pos < 1 || pos > 9){
            printf("Invalid position entered!\n");
            continue;
        }
        i=(pos-1)/3;
        j=(pos-1)%3;
        if(gameBoard[i][j]!=0){
            printf("Position already marked!\n");
            continue;
        }
        gameBoard[i][j]=player;
        checkForResult(gameBoard,&winner);
        turns++;
        player=player==1?2:1;
    }
    printGameBoard(gameBoard);
    if(winner>0)
        printf("The winner is Player %d\n",winner);
    else
        printf("The game is a tie.\n");
    return 0;
}