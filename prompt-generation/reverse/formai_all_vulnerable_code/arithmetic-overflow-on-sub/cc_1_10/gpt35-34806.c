//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = {'1','2','3','4','5','6','7','8','9'};   //Initialize the board with values

void display_board()
{
    printf("\n ");
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n-----------\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n-----------\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);  //Function to display the Tic Tac Toe board
}

int check_win()
{
    for(int i=0;i<3;i++)
    {
        if((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
           (board[0][i] == board[1][i] && board[0][i] == board[2][i]) ||    
           (board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
           (board[0][2] == board[1][1] && board[0][2] == board[2][0]))    //Checking if there is a winning combination
           return 1;
    }
    return 0;
}

int check_board_full()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return 1;
            }
        }
    }
    return 0;   //Checking if the board is full or not
}

int evaluate(char player)
{
    for(int i=0;i<3;i++)
    {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
           (board[0][i] == player && board[1][i] == player && board[2][i] == player) ||
           (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player))   //Checking for winning combination of a given player
           return 10;
    }
    return 0;
}

int minimax(char player, int depth)
{
    int score = evaluate(player);
    if(score == 10)
    {
        return score - depth;
    }
    if(check_board_full() == 0)
        return 0;

    if(player == 'O')   //Checking for maximizing player
    {
        int best_score = -1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j] != 'X' && board[i][j] != 'O')
                {
                    board[i][j] = player;

                    int current_score = minimax('X',depth+1);
                    best_score = (best_score > current_score ? best_score : current_score);

                    board[i][j] = (i*3+j)+'1';
                }
            }
        }
        return best_score;
    }
    else if(player == 'X')    //Checking for minimizing player
    {
        int best_score = 1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j] != 'X' && board[i][j] != 'O')
                {
                    board[i][j] = player;

                    int current_score = minimax('O',depth+1);
                    best_score = (best_score < current_score ? best_score : current_score);

                    board[i][j] = (i*3+j)+'1';
                }
            }
        }
        return best_score;
    }
}
void computer_move()
{
    int best_score = -10000;
    int move_i,move_j;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                board[i][j] = 'O';

                int current_score = minimax('X',0);
                if(current_score > best_score)
                {
                    best_score = current_score;
                    move_i = i;
                    move_j = j;
                }

                board[i][j] = (i*3+j)+'1';
            }
        }
    }  //Computer moves to maximize its score
    board[move_i][move_j] = 'O';
}

int main()
{
    display_board();
    while(1)
    {
        int x,y;
        printf("\n Enter row: ");
        scanf("%d",&x);
        printf("\n Enter column: ");
        scanf("%d",&y);
        x--;
        y--;
        if(x < 0 || x > 2 || y < 0 || y > 2)
        {
            printf("\n Invalid move!! Try again\n");  //Taking user input and checking validity of the move
            continue;
        }
        if(board[x][y] == 'X' || board[x][y] == 'O')
        {
            printf("\n Invalid move!! Try again\n");
            continue;
        }
        board[x][y] = 'X';
        display_board();
        if(check_win())
        {
            printf("\n Congratulation!! You win!!\n");
            break;
        }
        if(check_board_full()==0)
        {    
            printf("\n It's a tie!!\n");
            break;
        }
        computer_move();
        display_board();
        if(check_win())
        {
            printf("\n You lost!! Better luck next time!!\n");
            break;
        }
        if(check_board_full()==0)
        { 
            printf("\n It's a tie!!\n");
            break;
        }
    }
    return 0;
}