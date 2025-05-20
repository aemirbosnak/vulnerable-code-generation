//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k,l,count=0;
    char board[3][3];
    printf("Player 1: X and Player 2: O\n");
    printf("Enter the coordinates of your symbol (1-3 followed by 1-3): ");
    scanf("%d%d",&i,&j);
    board[i-1][j-1]='X';
    system("clear");
    printf("Tic Tac Toe\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==0 || j==0)
                printf("+---+");
            else if(i==2 || j==2)
                printf("+   +");
            else if(board[i-1][j-1]!='X' && board[i-1][j-1]!='O')
                printf("|   |");
            else
                printf("|%c|",board[i-1][j-1]);
        }
        printf("\n+---+\n");
    }
    while(1)
    {
        system("clear");
        printf("Tic Tac Toe\n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i==0 || j==0)
                    printf("+---+");
                else if(i==2 || j==2)
                    printf("+   +");
                else if(board[i-1][j-1]!='X' && board[i-1][j-1]!='O')
                    printf("|   |");
                else
                    printf("|%c|",board[i-1][j-1]);
            }
            printf("\n+---+\n");
        }
        printf("Enter the coordinates of your symbol (1-3 followed by 1-3): ");
        scanf("%d%d",&k,&l);
        if(board[k-1][l-1]!='X' && board[k-1][l-1]!='O')
        {
            board[k-1][l-1]='O';
            count++;
        }
        else
            printf("Invalid Move\n");
        if(count==5)
        {
            printf("Player 2 wins\n");
            break;
        }
        else if(count==9)
        {
            printf("Draw\n");
            break;
        }
        system("sleep 1");
    }
    return 0;
}