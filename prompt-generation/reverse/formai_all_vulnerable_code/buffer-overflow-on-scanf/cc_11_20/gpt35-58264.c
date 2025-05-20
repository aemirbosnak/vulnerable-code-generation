//FormAI DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function that displays the game board
void displayBoard(char board[9])
{
    printf("\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);
    printf("     |     |     \n\n");
}

//Function that checks if the game has ended
int gameEnd(char board[9])
{
    if ((board[0] == board[1] && board[1] == board[2]) || (board[3] == board[4] && board[4] == board[5]) ||
            (board[6] == board[7] && board[7] == board[8]) || (board[0] == board[3] && board[3] == board[6]) ||
            (board[1] == board[4] && board[4] == board[7]) || (board[2] == board[5] && board[5] == board[8]) ||
            (board[0] == board[4] && board[4] == board[8]) || (board[2] == board[4] && board[4] == board[6]))
    {
        return 1;
    }
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' &&
             board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

//Function that lets the user make a move
void playerMove(char board[9], char player, int position)
{
    if (position == 1 && board[0] == '1')
        board[0] = player;
    else if (position == 2 && board[1] == '2')
        board[1] = player;
    else if (position == 3 && board[2] == '3')
        board[2] = player;
    else if (position == 4 && board[3] == '4')
        board[3] = player;
    else if (position == 5 && board[4] == '5')
        board[4] = player;
    else if (position == 6 && board[5] == '6')
        board[5] = player;
    else if (position == 7 && board[6] == '7')
        board[6] = player;
    else if (position == 8 && board[7] == '8')
        board[7] = player;
    else if (position == 9 && board[8] == '9')
        board[8] = player;
}

int main()
{
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player = 1, position, gameStatus;
    char symbol;

    do
    {
        displayBoard(board);
        player = (player % 2) ? 1 : 2;
        symbol = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter the position where you want to make a move: ", player);
        scanf("%d", &position);

        playerMove(board, symbol, position);

        gameStatus = gameEnd(board);

        if (gameStatus == 1)
        {
            displayBoard(board);
            printf("\n\aPlayer %d wins!\n\n", player);
        }
        else if (gameStatus == 0)
        {
            displayBoard(board);
            printf("\n\aGame ended! It's a draw!\n\n");
        }

        player++;
    } while (gameStatus == -1);

    return 0;
}