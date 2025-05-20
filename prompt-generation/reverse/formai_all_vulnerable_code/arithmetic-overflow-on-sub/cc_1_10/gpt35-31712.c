//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic Tac Toe board
char playerSelection; // Player selection 'X' or 'O'
char computerSelection; // Computer selection 'X' or 'O'
int computerMoveX; // Computer move row position
int computerMoveY; // Computer move column position

void InitializeBoard()
{
    // Initialize all board positions with empty space
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j] = ' ';
        }
    }
}

void DisplayBoard()
{
    // Display the Tic Tac Toe board with current player and computer positions
    int i, j;
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf(" %c ", board[i][j]);
            if(j != 2) printf("|");
        }
        if(i != 2) printf("\n-----------\n");
    }
    printf("\n");
}

int CheckWin(char selection)
{
    // Check if the given player or computer has won the game
    int i, j;

    // Check rows
    for(i=0;i<3;i++)
    {
        if(board[i][0] == selection && board[i][1] == selection && board[i][2] == selection) return 1;
    }

    // Check columns
    for(j=0;j<3;j++)
    {
        if(board[0][j] == selection && board[1][j] == selection && board[2][j] == selection) return 1;
    }

    // Check diagonals
    if(board[0][0] == selection && board[1][1] == selection && board[2][2] == selection) return 1;
    if(board[0][2] == selection && board[1][1] == selection && board[2][0] == selection) return 1;

    return 0;
}

int CheckDraw()
{
    // Check if the game is a draw
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void PlayerMove()
{
    // Let the player make a move
    int row, col, validMove = 0;
    while(validMove == 0)
    {
        printf("Your turn! Enter row and column to make your move (e.g. 1 2): ");
        scanf("%d %d", &row, &col);
        row--; // Subtract 1 from user input since board array index starts from 0
        col--; // Subtract 1 from user input since board array index starts from 0
        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = playerSelection;
            validMove = 1;
        }
        else
        {
            printf("Invalid move. Please try again.\n");
        }
    }
}

void ComputerMove()
{
    // Let the computer make a move
    int validMove = 0;
    while(validMove == 0)
    {
        computerMoveX = rand() % 3; // Generate random row position
        computerMoveY = rand() % 3; // Generate random column position
        if(board[computerMoveX][computerMoveY] == ' ')
        {
            board[computerMoveX][computerMoveY] = computerSelection;
            printf("Computer's turn! Computer selected row %d, column %d.\n", computerMoveX+1, computerMoveY+1);
            validMove = 1;
        }
    }
}

int main()
{
    // Initialize random seed
    srand(time(NULL));

    printf("Welcome to Tic Tac Toe!\n");

    // Randomly select player and computer positions
    int playerRandom = rand() % 2; // Generate random number 0 or 1
    if(playerRandom == 0) // Player selected 'X'
    {
        playerSelection = 'X';
        computerSelection = 'O';
        printf("You are playing as 'X'.\n");
    }
    else // Player selected 'O'
    {
        playerSelection = 'O';
        computerSelection = 'X';
        printf("You are playing as 'O'.\n");
    }

    InitializeBoard();

    int gameStatus = 0; // 0=ongoing, 1=player won, 2=computer won, 3=draw

    while(gameStatus == 0)
    {
        DisplayBoard();
        PlayerMove();
        if(CheckWin(playerSelection) == 1)
        {
            gameStatus = 1; // Player won
            break;
        }
        if(CheckDraw() == 1)
        {
            gameStatus = 3; // Draw
            break;
        }
        ComputerMove();
        if(CheckWin(computerSelection) == 1)
        {
            gameStatus = 2; // Computer won
            break;
        }
        if(CheckDraw() == 1)
        {
            gameStatus = 3; // Draw
            break;
        }
    }

    DisplayBoard();

    // Display game result
    if(gameStatus == 1)
    {
        printf("Congratulations! You won!\n");
    }
    else if(gameStatus == 2)
    {
        printf("Sorry, computer won. Better luck next time!\n");
    }
    else
    {
        printf("The game is a draw.\n");
    }

    return 0;
}