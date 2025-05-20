//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int board[8][8];
int flag=0;
int player=1;
int x,y;

void drawBoard()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

void initializeBoard()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            board[i][j]=0;
        }
    }
}

void placePiece(int piece, int x, int y)
{
    if(piece==1)
    {
        board[x][y]=1;
    }
    else if(piece==2)
    {
        board[x][y]=2;
    }
}

int checkWin()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
        {
            return 1;
        }
    }
    for(j=0;j<8;j++)
    {
        if(board[0][j]==player && board[1][j]==player && board[2][j]==player)
        {
            return 1;
        }
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
    {
        return 1;
    }
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
    {
        return 1;
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int i,j;
    initializeBoard();
    while(1)
    {
        system("clear");
        drawBoard();
        printf("\nPlayer %d's Turn\n",player);
        int ch;
        scanf("%d %d",&x,&y);
        if(x<0 || x>7 || y<0 || y>7)
        {
            printf("Invalid Move\n");
            continue;
        }
        if(board[x][y]!=0)
        {
            printf("Square Already Occupied\n");
            continue;
        }
        placePiece(player,x,y);
        if(checkWin())
        {
            printf("%d Wins!\n",player);
            flag=1;
            break;
        }
        player=3-player;
    }
    return 0;
}