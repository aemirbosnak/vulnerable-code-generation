//FormAI DATASET v1.0 Category: Table Game ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

typedef struct{
    int x;
    int y;
}position;

void Display (int mat[ROW][COL])
{
    printf("\n\n\t\t\tTic-Tac-Toe\n");
    printf("\tPlayer 1 (X) : Player 2 (O)\n\n\n");
    for(int i=0;i<ROW;i++)
    {
        printf("\t\t\t");
        for(int j=0;j<COL;j++)
        {
            if(mat[i][j] == 1)
            {
                printf(" X ");
            }
            else if(mat[i][j] == -1)
            {
                printf(" O ");
            }
            else
            {
                printf("   ");
            }

            if(j!=2) printf("|");
        }
        printf("\n");
        if(i!=2) printf("\t\t\t-----------\n");
    }
}

position Player_Move(int mat[ROW][COL])
{
    srand(time(NULL));
    position p;
    p.x = rand() % 3;
    p.y = rand() % 3;

    while(mat[p.x][p.y]!=0)
    {
        p.x = rand() % 3;
        p.y = rand() % 3;
    }

    return p;
}

int Check_Win(int mat[ROW][COL])
{
    int sum[8]={0};
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            sum[i]+=mat[i][j];
            sum[j+3]+=mat[i][j];
            if(i==j)
            {
                sum[6]+=mat[i][j];
            }
            if(i+j==2)
            {
                sum[7]+=mat[i][j];
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        if(sum[i]==3)
        {
            return 1;
        }
        else if(sum[i]==-3)
        {
            return -1;
        }
    }
    return 0;
}

void Play_Game()
{
    int mat[ROW][COL]={0};
    position p;
    int game_over=0;
    int player=1;
    while(game_over==0)
    {
        Display(mat);

        if(player==1)
        {
            printf("\n\nPlayer 1's turn : ");
            scanf("%d%d",&p.x,&p.y);

            while(mat[p.x][p.y]!=0)
            {
                printf("Invalid move!\n");
                printf("\n\nPlayer 1's turn : ");
                scanf("%d%d",&p.x,&p.y);
            }

            mat[p.x][p.y]=1;
        }
        else
        {
            p=Player_Move(mat);
            printf("\n\nPlayer 2's turn : Computer\n");
            mat[p.x][p.y]=-1;
        }

        if(Check_Win(mat)==1)
        {
            Display(mat);
            printf("\n\nPlayer 1 won the game!\n");
            game_over=1;
        }
        else if(Check_Win(mat)==-1)
        {
            Display(mat);
            printf("\n\nPlayer 2 won the game!\n");
            game_over=1;
        }
        else
        {
            int count=0;
            for(int i=0;i<ROW;i++)
            {
                for(int j=0;j<COL;j++)
                {
                    if(mat[i][j]!=0)
                    {
                        count++;
                    }
                }
            }
            if(count==ROW*COL)
            {
                Display(mat);
                printf("\n\nGame Drawn!\n");
                game_over=1;
            }
            else
            {
                if(player==1)
                {
                    player=2;
                }
                else
                {
                    player=1;
                }
            }
        }
    }
}

int main()
{
    Play_Game();
    return 0;
}