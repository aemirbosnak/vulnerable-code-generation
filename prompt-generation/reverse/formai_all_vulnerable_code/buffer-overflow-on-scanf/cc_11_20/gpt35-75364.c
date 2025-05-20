//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function prototypes
void display_board(char board[][3]);
int check_winner(char board[][3]);

int main()
{
    char board[3][3]={'1','2','3','4','5','6','7','8','9'};  // initializing the board with numbers
    
    srand(time(NULL)); // to generate random numbers
    
    int count=1,position,player=1,winner=0;
    // count - to keep track of number of moves
    // position - input choice of the player
    // player - decides player 1 or player 2
    // winner - stores the status of the game (0 - continue, 1 - draw, 2 - player 1 wins, 3 - player 2 wins)
    
    while(count<=9) // there can be maximum of 9 moves
    {
        display_board(board);
        
        // decide the player
        if(count%2==0)
        {
            player=2;
        }
        else
        {
            player=1;
        }
        
        printf("Player %d's turn: ",player);
        scanf("%d",&position);
        
        // check if input is valid
        if(position<1 || position>9)
        {
            printf("Invalid position! Try again!\n");
            continue;
        }
        // check if input position is already filled
        int row=(position-1)/3;
        int col=(position-1)%3;
        
        if(board[row][col]=='X' || board[row][col]=='O')
        {
            printf("Position already filled! Try again!\n");
            continue;
        }
        
        // place the marker (X or O) in the chosen position
        if(player==1)
        {
            board[row][col]='X';
        }
        else
        {
            board[row][col]='O';
        }
        
        // check for winner
        winner=check_winner(board);
        if(winner)
        {
            break;
        }
        
        count++;
    }
    
    display_board(board);
    
    if(winner==1)
    {
        printf("Game ends in a draw!\n");
    }
    else if(winner==2)
    {
        printf("Player 1 wins!\n");
    }
    else if(winner==3)
    {
        printf("Player 2 wins!\n");
    }
    
    return 0;
}

void display_board(char board[][3])
{
    printf("\n");
    printf("\t%s  |  %s  |  %s \n", &board[0][0], &board[0][1], &board[0][2]);
    printf("\t==============\n");
    printf("\t%s  |  %s  |  %s \n", &board[1][0], &board[1][1], &board[1][2]);
    printf("\t==============\n");
    printf("\t%s  |  %s  |  %s \n", &board[2][0], &board[2][1], &board[2][2]);
    printf("\n");
}

int check_winner(char board[][3])
{
    // check for rows
    for(int i=0; i<3; i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        {
            if(board[i][0]=='X')
            {
                return 2;
            }
            else if(board[i][0]=='O')
            {
                return 3;
            }
        }
    }
    
    // check for columns
    for(int i=0; i<3; i++)
    {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
        {
            if(board[0][i]=='X')
            {
                return 2;
            }
            else if(board[0][i]=='O')
            {
                return 3;
            }
        }
    }
    
    // check for diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        if(board[0][0]=='X')
        {
            return 2;
        }
        else if(board[0][0]=='O')
        {
            return 3;
        }
    }
    
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        if(board[0][2]=='X')
        {
            return 2;
        }
        else if(board[0][2]=='O')
        {
            return 3;
        }
    }
    
    // check for draw
    int count=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j]=='X' || board[i][j]=='O')
            {
                count++;
            }
        }
    }
    
    if(count==9)
    {
        return 1;
    }
    
    // game continues
    return 0;
}