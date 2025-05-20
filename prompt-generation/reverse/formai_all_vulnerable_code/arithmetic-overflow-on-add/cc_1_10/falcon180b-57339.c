//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 5

void drawBoard(bool board[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            if(board[i][j]==true) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void updateBoard(bool board[SIZE][SIZE],int x,int y) {
    int count=0;
    for(int i=-1;i<=1;i++) {
        for(int j=-1;j<=1;j++) {
            if(i!=0 || j!=0) {
                count+=board[x+i][y+j];
            }
        }
    }
    if(board[x][y]==true) {
        if(count<2) {
            board[x][y]=false;
        }
    } else {
        if(count==3) {
            board[x][y]=true;
        }
    }
}

int main() {
    bool board[SIZE][SIZE];
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            board[i][j]=false;
        }
    }
    board[2][2]=true;
    board[2][3]=true;
    board[3][2]=true;
    int x=2,y=2;
    while(true) {
        drawBoard(board);
        usleep(500000);
        updateBoard(board,x,y);
        if(board[x][y]==false) {
            break;
        }
        x++;
        if(x==SIZE) {
            x=0;
            y++;
        }
        if(y==SIZE) {
            y=0;
        }
    }
    return 0;
}