//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// function to display the Tic Tac Toe board
void displayBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\t\t\t%c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
        {
            printf("\t\t\t---------\n");
        }
    }
    printf("\n\n");
}

// function to check if there is a winner or not
int checkWinner(char player)
{
    if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||  // first row
        (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||  // second row
        (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||  // third row
        (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||  // first column
        (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||  // second column
        (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||  // third column
        (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // diagonal 1
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))    // diagonal 2
    {
        return 1;  // player won
    }
    return 0;
}

// function to make a move for the human player
void playerMove(char player)
{
    int move;
    printf("\t\t\tEnter your move (1-9): ");
    scanf("%d", &move);
    while (move < 1 || move > 9 || board[(move-1)/3][(move-1)%3] == 'X' || board[(move-1)/3][(move-1)%3] == 'O')
    {
        printf("\t\t\tInvalid move. Please enter a valid move (1-9): ");
        scanf("%d", &move);
    }
    board[(move-1)/3][(move-1)%3] = player;
}

// function to make a move for the computer player
void computerMove(char player)
{
    int move;
    srand(time(NULL));
    do
    {
        move = rand() % 9 + 1;
    } while (board[(move-1)/3][(move-1)%3] == 'X' || board[(move-1)/3][(move-1)%3] == 'O');
    printf("\t\t\tComputer choose %d.\n", move);
    board[(move-1)/3][(move-1)%3] = player;
}

int main()
{
    char humanPlayer, computerPlayer;
    int turn, winner = 0;

    printf("\n\t\t--- WELCOME TO TIC TAC TOE ---\n\n");
    printf("\t\tSelect your symbol (X/O): ");
    scanf("%c", &humanPlayer);

    while (humanPlayer != 'X' && humanPlayer != 'O')  // validating the input
    {
        printf("\t\tInvalid input. Please select X or O: ");
        scanf(" %c", &humanPlayer);
    }

    computerPlayer = (humanPlayer == 'X') ? 'O' : 'X';  // assigning opposite symbol to computer

    printf("\n\t\tYou are %c, and computer is %c.\n", humanPlayer, computerPlayer);

    turn = rand() % 2;  // randomly selecting the turn
    printf("\t\t%s will go first.\n", (turn == 1) ? "You" : "Computer");

    while (!winner)
    {
        if (turn == 1)  // human's turn
        {
            printf("\n\t\tYour turn:\n");
            displayBoard();
            playerMove(humanPlayer);
            if (checkWinner(humanPlayer))
            {
                winner = 1;
                printf("\t\t*** CONGRATULATIONS! YOU WON! ***\n\n");
            }
            else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
                board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
                board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
            {
                winner = 1;  // tie
                printf("\t\t*** IT'S A TIE! ***\n\n");
            }
            else
            {
                turn = 0;  // computer's turn
            }
        }
        else  // computer's turn
        {
            printf("\n\t\tComputer's turn:\n");
            displayBoard();
            computerMove(computerPlayer);
            if (checkWinner(computerPlayer))
            {
                winner = 1;
                printf("\t\t*** SORRY! COMPUTER WON! ***\n\n");
            }
            else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
                board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
                board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
            {
                winner = 1;  // tie
                printf("\t\t*** IT'S A TIE! ***\n\n");
            }
            else
            {
                turn = 1;  // human's turn
            }
        }
    }
    displayBoard();
    return 0;
}