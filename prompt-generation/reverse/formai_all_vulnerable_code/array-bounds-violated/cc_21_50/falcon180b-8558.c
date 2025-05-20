//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLS 4

int main()
{
    int i,j,m,n,flag=0,ch;
    char board[ROWS][COLS]={{'1','2','3','4'},{'5','6','7','8'},{'9','10','11','12'},{'13','14','15','16'}};
    char mark;

    srand(time(0));
    m = rand()%ROWS;
    n = rand()%COLS;

    board[m][n] = '*';
    board[m][n+1] = '*';

    while(1)
    {
        system("clear");
        printf("\n");
        for(i=0;i<ROWS;i++)
        {
            for(j=0;j<COLS;j++)
            {
                if(i==m && j==n)
                    printf("\033[1;31m%c\033[0m ",board[i][j]);
                else if(i==m && j==n+1)
                    printf("\033[1;31m%c\033[0m ",board[i][j]);
                else
                    printf("%c ",board[i][j]);
            }
            printf("\n");
        }

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        if(ch==1 && m>0 && n>0)
            m--;
        else if(ch==2 && m<ROWS-1 && n>0)
            m++;
        else if(ch==3 && m>0 && n<COLS-1)
            n++;
        else if(ch==4 && m<ROWS-1 && n<COLS-1)
            n++;

        if(board[m][n]!='*')
        {
            printf("\nSorry, you lose!!!\n");
            flag=1;
            break;
        }
        else if(board[m][n]=='*' && board[m][n+1]=='*')
        {
            printf("\nCongratulations, you won!!!\n");
            flag=1;
            break;
        }
    }

    if(!flag)
        printf("\nThanks for playing!!!");

    return 0;
}