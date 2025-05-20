//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3];

void display_board();
int check_win();
void user_turn();
void ai_turn();

int main()
{
    int choice;
    printf("\nWelcome to Tic Tac Toe!\n");
    printf("\nSelect an option :\n");
    printf("\n1. AI goes first\n2. Player goes first\n");
    scanf("%d",&choice);
    int count=0;
    int game_over=0;
    int win=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]='-';
        }
    }

    if(choice==1)
    {
        ai_turn();
        display_board();
        count++;
    }

    while(count<9 && game_over==0)
    {
        user_turn();
        win=check_win();
        if(win==1)
        {
            printf("\nYou won!\n");
            game_over=1;
            break;
        } else if(win==-1)
        {
            printf("\nAI won!\n");
            game_over=1;
            break;
        }

        count++;
        if(count>=9)
        {
            printf("\nIt's a tie!\n");
            break;  
        }

        ai_turn();
        display_board();
        count++;
        win=check_win();
        if(win==1)
        {
            printf("\nYou won!\n");
            game_over=1;
            break;
        } else if(win==-1)
        {
            printf("\nAI won!\n");
            game_over=1;
            break;
        }
    }

    return 0;
}

void display_board()
{
    printf("\n");

    for(int i=0;i<3;i++)
    {
        printf(" ");
        for(int j=0;j<3;j++)
        {
            printf("%c  ",board[i][j]);
        }
        printf("\n");
    }
}

int check_win()
{
    // For Rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        {
            if(board[i][0]=='X')
            {
                return 1;
            }
            else if(board[i][0]=='O')
            {
                return -1;
            }
        }
    }

    // For Columns
    for(int i=0;i<3;i++)
    {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
        {
            if(board[0][i]=='X')
            {
                return 1;
            }
            else if(board[0][i]=='O')
            {
                return -1;
            }   
        }
    }

    // For Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        if(board[0][0]=='X')
        {
            return 1;
        }
        else if(board[0][0]=='O')
        {
            return -1;
        }   
    }

    if(board[2][0]==board[1][1] && board[1][1]==board[0][2])
    {
        if(board[2][0]=='X')
        {
            return 1;
        }
        else if(board[2][0]=='O')
        {
            return -1;
        }   
    }

    return 0;
}

void user_turn()
{
    int row,col;
    printf("\nEnter the co-ordinates of your move(row,col): ");
    scanf("%d,%d",&row,&col);
    while(board[row-1][col-1]!='-' || row<1 || row>3 || col<1 || col>3)
    {
        printf("\nInvalid Move! Try again.\n");
        printf("\nEnter the co-ordinates of your move(row,col):");
        scanf("%d,%d",&row,&col);
    }
    board[row-1][col-1]='X';
    display_board();
}

void ai_turn()
{
    int row,col;
    srand(time(NULL));
    do
    {
        row=rand()%3;
        col=rand()%3;
    }while(board[row][col]!='-');
    board[row][col]='O';
}