//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

char board[3][3]; //2D array to store Tic Tac Toe board
char player = 'X'; //Starting player

//Function to draw Tic Tac Toe board
void draw_board()
{
    printf("\n");
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}

//Function to check if Tic Tac Toe board is full
int is_board_full()
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

//Function to check if player has won
int check_for_win()
{
    int i;
    //Checking rows for win
    for(i=0; i<3; i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }
    //Checking columns for win
    for(i=0; i<3; i++)
    {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }
    //Checking diagonals for win
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return 1;
    }
    return 0;
}

//Function to let AI make move
void ai_move()
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

//Main function
int main()
{
    int row, col;
    //Setting all elements of Tic Tac Toe board to empty
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
    //Game loop
    while(!is_board_full())
    {
        //Drawing board
        draw_board();
        //Getting player's move
        printf("Enter row and column for %c: ",player);
        scanf("%d %d",&row,&col);
        //Checking if the input is valid
        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        {
            printf("Invalid move!\n");
            continue;
        }
        //Placing player's move on Tic Tac Toe board
        board[row][col] = player;
        //Checking if player has won
        if(check_for_win())
        {
            draw_board();
            printf("%c has won!\n",player);
            break;
        }
        //Changing player for next move
        player = player == 'X' ? 'O' : 'X';
        //AI's turn
        if(!is_board_full())
        {
            ai_move();
            //Checking if AI has won
            if(check_for_win())
            {
                draw_board();
                printf("AI has won!\n");
                break;
            }
            //Changing player for next move
            player = player == 'X' ? 'O' : 'X';
        }
    }
    //Game over
    if(is_board_full())
    {
        draw_board();
        printf("It's a tie!\n");
    }
    return 0;
}