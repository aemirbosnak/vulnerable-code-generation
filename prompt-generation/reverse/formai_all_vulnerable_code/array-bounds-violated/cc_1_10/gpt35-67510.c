//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int player=0;

void display_board()
{
    printf("\n\n");
    printf("=====================\n");
    printf("   Tic Tac Toe Game   \n");
    printf("=====================\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[0][0],board[0][1],board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1][0],board[1][1],board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[2][0],board[2][1],board[2][2]);
    printf("     |     |     \n\n");
}

void play_game(int row, int col, char symbol)
{
    if(board[row][col] == ' ')
    {
        board[row][col] = symbol;
        player=(player==0)?1:0;
    }
    else
    {
        printf("\nThat move is already taken.\n");
    }
    
}

int check_win()
{
    for(int i=0;i<3;i++)
    {
        if((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][0]!=' '))
            return 1;
        if((board[0][i]==board[1][i]) && (board[1][i]==board[2][i]) && (board[0][i]!=' '))
            return 1;
    }
    if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]) && (board[0][0]!=' '))
        return 1;
    if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) && (board[0][2]!=' '))
        return 1;
    return 0;
}

int main()
{
    printf("===========Welcome to Tic Tac Toe==========\n\n");
    int row,col;
    char symbol;
    int win=0;
    display_board();
    
    do
    {
        if(player%2==0)
            symbol='X';
        else
            symbol='O';
        
        printf("Player %d, enter row (0-2) and column (0-2) to play: ",player+1);
        scanf("%d%d",&row,&col);
        play_game(row, col, symbol);
        display_board();
        win=check_win();
    }while(win!=1);
    
    printf("\n\n*********************\n");
    printf("PLAYER %d WINS!\n",player==0?2:1);
    printf("*********************\n");
    
    return 0;
}