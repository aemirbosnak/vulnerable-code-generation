//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 8

void initBoard(char board[][SIZE])
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            board[i][j]=' ';
        }
    }
}

void drawBoard(char board[][SIZE])
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void placePiece(char board[][SIZE],char piece,int x,int y)
{
    board[x][y]=piece;
}

int checkWin(char board[][SIZE],char piece)
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        if(board[i][0]==piece && board[i][1]==piece && board[i][2]==piece)
            return 1;
        if(board[0][i]==piece && board[1][i]==piece && board[2][i]==piece)
            return 1;
    }
    for(i=0;i<3;i++)
    {
        if(board[i][0]==piece && board[i][1]==piece && board[i][2]==piece)
            return 1;
        if(board[2-i][0]==piece && board[2-i][1]==piece && board[2-i][2]==piece)
            return 1;
    }
    if(board[0][0]==piece && board[1][1]==piece && board[2][2]==piece)
        return 1;
    if(board[0][2]==piece && board[1][1]==piece && board[2][0]==piece)
        return 1;
    return 0;
}

int main()
{
    srand(time(NULL));
    char board[SIZE][SIZE];
    initBoard(board);
    int x,y;
    int player=1;
    int flag=0;
    while(flag==0)
    {
        drawBoard(board);
        printf("Player %d's turn\n",player);
        scanf("%d %d",&x,&y);
        x--;y--;
        if(board[x][y]!=' ')
        {
            printf("Invalid move\n");
            continue;
        }
        placePiece(board,player==1?'X':'O',x,y);
        flag=checkWin(board,player==1?'X':'O');
        player=player==1?2:1;
    }
    drawBoard(board);
    printf("Game over. Player %d wins!\n",player);
    return 0;
}