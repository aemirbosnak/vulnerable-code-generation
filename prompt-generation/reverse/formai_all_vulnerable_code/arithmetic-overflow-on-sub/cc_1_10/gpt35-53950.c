//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include<stdio.h>
#include<stdlib.h>

char board[3][3]; //tic tac toe board

//function to print the board
void printBoard()
{
    int i,j;
    printf("\n");
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf(" %c ", board[i][j]);
            if(j!=2) //for the vertical lines in board
                printf("|");
        }
        printf("\n");
        if(i!=2) //for the horizontal lines in board
            printf("---|---|---\n");
    }
}

//function to check if a player has won or if the game is a tie
int gameResult(int player)
{
    int i;
    //checking for horizontal wins
    for(i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0]!=' ')
        {
            printf("\nPlayer %d wins!\n",player);
            return 1;
        }
    }
    //checking for vertical wins
    for(i=0;i<3;i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i]!=' ')
        {
            printf("\nPlayer %d wins!\n",player);
            return 1;
        }
    }
    //checking for diagonal wins
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0]!=' ')
    {
        printf("\nPlayer %d wins!\n",player);
        return 1;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2]!=' ')
    {
        printf("\nPlayer %d wins!\n",player);
        return 1;
    }
    //checking for tie
    for(i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    printf("\nThe game is a tie!\n");
    return 1;
}

//function to make move for computer player
void computerMove()
{
    int row=0, col=0, i, j;
    
    //checking for winning move
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                board[i][j]='O';
                if(gameResult(2))
                {
                    return;
                }
                else
                {
                    board[i][j]=' ';
                }
            }
        }
    }
    
    //checking for opponent winning move
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                board[i][j]='X';
                if(gameResult(1))
                {
                    board[i][j]='O';
                    return; 
                }
                else
                {
                    board[i][j]=' ';
                }
            }
        }
    }
    
    //if no winning move, play on center or random corners or random side
    if(board[1][1]==' ')
    {
        row=1;
        col=1;
    }
    else 
    {
        while(board[row][col]!=' ')
        {
            row = rand() % 3; 
            col = rand() % 3;
        }
    }
    board[row][col]='O';
}

int main()
{
    int i;
    //initialize board to empty spaces
    for(i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
    
    printBoard();
    int player = 1; //player 1 is user and player 2 is computer
    
    while(!gameResult(player))
    {
        if(player==1)
        {
            int row, col;
            printf("\n\nEnter your move:\n");
            printf("Row(1-3): ");
            scanf("%d", &row);
            printf("Column(1-3): ");
            scanf("%d", &col);
            
            if(board[row-1][col-1] == ' ')
            {
                board[row-1][col-1] = 'X';
                player = 2;
            }
            else
            {
                printf("\nInvalid move! Try again\n");
            }
        }
        
        else
        {
            printf("\n\nComputer's move:\n");
            computerMove();
            printBoard();
            player = 1;
        }
    }
    
    return 0;
}