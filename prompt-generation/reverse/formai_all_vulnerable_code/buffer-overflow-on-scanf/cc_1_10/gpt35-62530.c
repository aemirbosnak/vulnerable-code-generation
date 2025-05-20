//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3]; 

//function to display the current state of the game board
void displayBoard()
{
    printf("\nCurrent Board Status:\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

//function to check if someone has won the game
char checkWinner()
{
    int i;
    //check for horizontal win
    for (i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

    //check for vertical win
    for (i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];

    //check for diagonal win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

//function to check if the game has tied
bool checkTie()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

//function to get the move from user
void playerMove(char playerChar)
{
    int x, y;
    printf("\n%s's move: ", (playerChar == 'X') ? "Player" : "Computer");
    while (true)
    {
        scanf("%d%d", &x, &y);
        if (x < 0 || x > 2 || y < 0 || y > 2)
            printf("\nInvalid move! Try again: ");
        else if (board[x][y] == ' ')
        {
            board[x][y] = playerChar;
            return;
        }
        else
            printf("\nThat spot is taken! Try again: ");
    }
}

//function to get the move from computer
void computerMove(char computerChar, char playerChar)
{
    int i = 0, j = 0;
    printf("\nComputer's move: ");
    while (true)
    {
        i = rand() % 3;
        j = rand() % 3;
        if (board[i][j] == ' ')
        {
            board[i][j] = computerChar;
            return;
        }
    }
}

//function to check if the game is over
bool checkGameOver(char computerChar, char playerChar)
{
    if (checkWinner() == computerChar)
    {
        printf("\nOops! The computer just won the game!\n");
        return true;
    }
    else if (checkWinner() == playerChar)
    {
        printf("\nCongrats! You won the game!\n");
        return true;
    }
    else if (checkTie())
    {
        printf("\nIt's a tie!\n");
        return true;
    }
    return false;
}

//function to start the game
void startGame()
{
    char computerChar = 'O', playerChar = 'X';
    int choice = 0;
    printf("\nWelcome to the Tic Tac Toe Game!\n");
    printf("1. First Turn: Player\n2. First Turn: Computer\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 2)
    {
        computerMove(computerChar, playerChar);
        displayBoard();
    }
    while (true)
    {
        playerMove(playerChar);
        displayBoard();
        if (checkGameOver(computerChar, playerChar))
            break;
        computerMove(computerChar, playerChar);
        displayBoard();
        if (checkGameOver(computerChar, playerChar))
            break;
    }
}

int main()
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
    startGame();
    return 0;
}