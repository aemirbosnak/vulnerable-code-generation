//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#define Board_Size 9 // size of the game board

char board[Board_Size] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X'; // user will always go first

void draw_board(void);
void player_turn(void);
void computer_turn(void);
int check_win(void);

int main()
{
    draw_board();

    while(check_win() == 0) // keep playing until someone wins
    {
        player_turn(); // player's turn
        computer_turn(); // computer's turn
    }

    return 0;
}

void draw_board(void)
{
    system("clear"); // clear the console screen

    printf("\n\tTic Tac Toe\n\n");
    printf("Player (X)  -  Computer (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);
    printf("     |     |     \n");
}

void player_turn(void)
{
    int position;

    printf("Player's turn (X).\n");
    printf("Enter a position: ");
    scanf("%d", &position);

    // check if input is valid
    while(position < 1 || position > 9 || board[position-1] == 'X' || board[position-1] == 'O')
    {
        printf("Invalid position. Please enter a valid position (1-9): ");
        scanf("%d", &position);
    }

    board[position-1] = player; // place the player's move on the board
    draw_board(); // draw the updated board
}

void computer_turn(void)
{
    int position;

    printf("Computer's turn (O).\n");

    // AI for the computer's move
    if(board[4] == '5') // computer's first move, go for the center
        position = 5;
    else
    {
        // check for any winning moves
        for(int i = 0; i < Board_Size; i++)
        {
            if(board[i] != 'X' && board[i] != 'O')
            {
                char temp = board[i];

                board[i] = 'O';
                if(check_win() == 1)
                {
                    position = i+1;
                    board[i] = temp;
                    goto COMPUTER_MOVE;
                }
                else
                    board[i] = temp;
            }
        }

        // check for any blocking moves
        for(int i = 0; i < Board_Size; i++)
        {
            if(board[i] != 'X' && board[i] != 'O')
            {
                char temp = board[i];

                board[i] = 'X';
                if(check_win() == 2)
                {
                    position = i+1;
                    board[i] = temp;
                    goto COMPUTER_MOVE;
                }
                else
                    board[i] = temp;
            }
        }

        // try to take a corner
        if(board[0] == '1')
            position = 1;
        else if(board[2] == '3')
            position = 3;
        else if(board[6] == '7')
            position = 7;
        else if(board[8] == '9')
            position = 9;
        // take any open position
        else
        {
            for(int i = 0; i < Board_Size; i++)
            {
                if(board[i] != 'X' && board[i] != 'O')
                {
                    position = i+1;
                    break;
                }
            }
        }
    }

    // place the computer's move on the board
    COMPUTER_MOVE:
    board[position-1] = 'O';
    draw_board(); // draw the updated board
}

int check_win(void)
{
    // check for horizontal wins
    if((board[0] == board[1] && board[1] == board[2]) ||
       (board[3] == board[4] && board[4] == board[5]) ||
       (board[6] == board[7] && board[7] == board[8]))
    {
        if(board[0] == 'X')
            return 1;
        else if(board[0] == 'O')
            return 2;
    }
    // check for vertical wins
    else if((board[0] == board[3] && board[3] == board[6]) ||
            (board[1] == board[4] && board[4] == board[7]) ||
            (board[2] == board[5] && board[5] == board[8]))
    {
        if(board[0] == 'X')
            return 1;
        else if(board[0] == 'O')
            return 2;
    }
    // check for diagonal wins
    else if((board[0] == board[4] && board[4] == board[8]) ||
            (board[2] == board[4] && board[4] == board[6]))
    {
        if(board[0] == 'X')
            return 1;
        else if(board[0] == 'O')
            return 2;
    }
    // check for a tie
    else if(board[0] != '1' && board[1] != '2' && board[2] != '3' &&
            board[3] != '4' && board[4] != '5' && board[5] != '6' &&
            board[6] != '7' && board[7] != '8' && board[8] != '9')
        return 3;
    // continue playing
    else
        return 0;
}