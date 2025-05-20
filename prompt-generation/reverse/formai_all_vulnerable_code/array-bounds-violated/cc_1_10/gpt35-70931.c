//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to draw the tic-tac-toe board
void draw_board(char *board)
{
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("-----------");
    printf("\n %c | %c | %c \n", board[3], board[4], board[5]);
    printf("-----------");
    printf("\n %c | %c | %c \n", board[6], board[7], board[8]);
}

//Function to check if there is any winner
int check_winner(char *board, char player)
{
    if((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Function to get the player move
int get_player_move(char *board)
{
    int move;
    do {
        printf("Enter your move (0-8): ");
        scanf("%d", &move);
    } while (board[move] != ' ');
    return move;
}

//Function to get the computer move
int get_computer_move(char *board, char player)
{
    int i, j, move;
    //Checking if we can win in one move
    for(i=0; i<9; i++)
    {
        if(board[i] == ' ')
        {
            board[i] = player;
            if(check_winner(board, player))
            {
                return i;
            }
            board[i] = ' ';
        }
    }
    //Checking if the player can win in one move
    char opponent = (player == 'X') ? 'O' : 'X';
    for(i=0; i<9; i++)
    {
        if(board[i] == ' ')
        {
            board[i] = opponent;
            if(check_winner(board, opponent))
            {
                return i;
            }
            board[i] = ' ';
        }
    }
    //Making a move in the center
    if(board[4] == ' ')
    {
        return 4;
    }
    //Making a random move
    do {
        move = rand() % 9;
    } while (board[move] != ' ');
    return move;
}

int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    draw_board(board);
    char player = 'X';
    int move;
    while(1)
    {
        if(player == 'X')
        {
            //Getting player's move
            move = get_player_move(board);
            board[move] = player;
            draw_board(board);
            if(check_winner(board, player))
            {
                printf("Player %c won!\n", player);
                return 0;
            }
            player = 'O';
        }
        else
        {
            printf("Computer's move: ");
            //Getting computer's move
            move = get_computer_move(board, player);
            board[move] = player;
            draw_board(board);
            if(check_winner(board, player))
            {
                printf("Computer won!\n");
                return 0;
            }
            player = 'X';
        }
    }
    return 0;
}