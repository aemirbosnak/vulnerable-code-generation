//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 3

char board[SIZE][SIZE]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard(char board[SIZE][SIZE]) {
    int i,j;
    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;
    for(i=0;i<SIZE;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return 1;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return 1;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return 1;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(0));
    int player=0;
    int choice;
    int flag=0;

    while(flag==0) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's Turn\n",player+1);
        printf("Enter your move: ");
        scanf("%d",&choice);
        if(choice<1 || choice>9) {
            printf("Invalid Move! Try Again.\n");
            continue;
        }
        int row=choice/3;
        int col=choice%3;

        if(board[row][col]!='1' && board[row][col]!='2' && board[row][col]!='3') {
            board[row][col]='1';
            player++;
            flag=checkWin(board);
        }
        else {
            printf("Invalid Move! Try Again.\n");
        }
    }

    system("clear");
    drawBoard(board);
    printf("\nPlayer %d Wins!\n",player);

    return 0;
}