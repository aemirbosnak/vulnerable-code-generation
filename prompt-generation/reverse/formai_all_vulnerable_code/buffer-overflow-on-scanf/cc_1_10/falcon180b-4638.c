//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 8

int board[SIZE][SIZE]; //Chess board

void initBoard(){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            board[i][j]=0;
        }
    }
}

void printBoard(){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(){
    int i,j;
    for(i=0;i<SIZE;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]!=0)
            return 1;
    }
    for(j=0;j<SIZE;j++){
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[2][j]!=0)
            return 1;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]!=0)
        return 1;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]!=0)
        return 1;

    return 0;
}

void AI(){
    int i,j;
    srand(time(0));
    int move=rand()%9;
    while(move==-1){
        move=rand()%9;
    }
    int x,y;
    switch(move){
        case 0:
            x=0;
            y=0;
            break;
        case 1:
            x=0;
            y=1;
            break;
        case 2:
            x=0;
            y=2;
            break;
        case 3:
            x=1;
            y=0;
            break;
        case 4:
            x=1;
            y=1;
            break;
        case 5:
            x=1;
            y=2;
            break;
        case 6:
            x=2;
            y=0;
            break;
        case 7:
            x=2;
            y=1;
            break;
        case 8:
            x=2;
            y=2;
            break;
    }
    if(board[x][y]==0){
        board[x][y]=1;
        return;
    }
    else{
        AI();
    }
}

int main(){
    int player=1;
    initBoard();
    while(1){
        printBoard();
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>=0 && x<SIZE && y>=0 && y<SIZE && board[x][y]==0){
            board[x][y]=player;
            if(checkWin()){
                printf("Player %d wins!\n",player);
                break;
            }
            else{
                player=!player;
            }
        }
        else{
            printf("Invalid move!\n");
        }
    }
    return 0;
}