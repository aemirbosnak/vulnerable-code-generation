//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 4
#define MAX_COUNT 8

int count;
int arr[ROW][COL] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int pos_row,pos_col;
int player_row,player_col;
int flag = 0;
int choice;

void draw_board()
{
    system("clear");
    printf("\n");
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
}

void move(int row,int col)
{
    if(row >= 0 && row < ROW && col >= 0 && col < COL)
    {
        if(arr[row][col]!= 0)
        {
            player_row = row;
            player_col = col;
            count++;
            if(count == MAX_COUNT)
            {
                printf("\nPlayer wins!");
                flag = 1;
            }
        }
        else
        {
            printf("\nInvalid move!");
        }
    }
    else
    {
        printf("\nInvalid move!");
    }
}

void computer_move()
{
    int row = rand()%ROW;
    int col = rand()%COL;
    while(arr[row][col] == 0)
    {
        row = rand()%ROW;
        col = rand()%COL;
    }
    arr[row][col] = 0;
    draw_board();
    if(count == MAX_COUNT)
    {
        printf("\nComputer wins!");
        flag = 1;
    }
}

int main()
{
    srand(time(NULL));
    draw_board();
    while(flag == 0)
    {
        printf("\nEnter your move (row and column): ");
        scanf("%d%d",&pos_row,&pos_col);
        move(pos_row,pos_col);
        if(flag == 0)
        {
            computer_move();
        }
    }
    return 0;
}