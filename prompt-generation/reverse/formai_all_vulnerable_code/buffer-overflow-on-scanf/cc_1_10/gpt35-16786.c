//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3];
int player = 1;

void init_board();
void display_board();
void player_turn();
void computer_turn();
int check_win();

int main()
{
    int round = 1;
    srand(time(NULL)); //Set seed for random function
    
    init_board();
    
    printf("Welcome to Tic Tac Toe AI!\n");
    printf("You are player 'X'. The computer is 'O'.\n");
    
    while(round <= 9)
    {
        display_board();
        
        if(player == 1)
        {
            player_turn();
        }
        else
        {
            computer_turn();
        }
        
        if(check_win())
        {
            display_board();
            if(player == 1)
            {
                printf("Congratulation! You won!\n");
            }
            else
            {
                printf("The computer won. Better luck next time.\n");
            }
            return 0;
        }
        
        player = (player == 1) ? 2 : 1;
        round++;
    }
    
    display_board();
    printf("It's a tie!\n");
    
    return 0;
}

void init_board()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

void display_board()
{
    printf("  1 2 3 \n");
    printf(" -------\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%d|", i+1);
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
            {
                printf(" |");
            }
            else if(board[i][j] == 1)
            {
                printf("X|");
            }
            else
            {
                printf("O|");
            }
        }
        printf("\n");
        printf(" -------\n");
    }
}

void player_turn()
{
    int row, col;
    printf("It's your turn. Enter row number (1-3): ");
    scanf("%d", &row);
    printf("Enter column number (1-3): ");
    scanf("%d", &col);
    
    if(board[row-1][col-1] != 0)
    {
        printf("Invalid move. Try again.\n");
        player_turn();
    }
    else
    {
        board[row-1][col-1] = 1;
    }
}

void computer_turn()
{
    printf("It's the computer's turn.\n");
    int row = rand() % 3;
    int col = rand() % 3;
    
    if(board[row][col] != 0)
    {
        computer_turn();
    }
    else
    {
        board[row][col] = 2;
    }
}

int check_win()
{
    //Check rows and columns for winner
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return 1;
        }
        if(board[0][i] != 0 && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return 1;
        }
    }
    
    //Check diagonals for winner
    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return 1;
    }
    if(board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return 1;
    }
    
    return 0;
}