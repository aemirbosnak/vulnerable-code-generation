//FormAI DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SIZE 3

void initializeBoard(char board[][SIZE]);
void printBoard(char board[][SIZE]);
int getPlayerMove(int player, char board[][SIZE]);
int validateMove(char move, char board[][SIZE]);
int checkWin(char board[][SIZE]);
int checkDraw(char board[][SIZE]);
void getComputerMove(char board[][SIZE]);

int main()
{
    char board[SIZE][SIZE];
    int currentPlayer = 1;

    initializeBoard(board);

    printf("Welcome to the Tic Tac Toe game!\n\n");

    while (1)
    {
        int move = 0;

        printBoard(board);

        if (currentPlayer == 1)
        {
            move = getPlayerMove(currentPlayer, board);
        }
        else
        {
            getComputerMove(board);
        }

        board[(move-1)/SIZE][(move-1)%SIZE] = (currentPlayer == 1) ? 'X' : 'O';

        if (checkWin(board))
        {
            printf("Player %d has won the game!\n", currentPlayer);
            break;
        }
        else if (checkDraw(board))
        {
            printf("The game is a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

void initializeBoard(char board[][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][SIZE])
{
    int i, j;

    printf("  ");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", i+1);
    }

    printf("\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", i+1);

        for (j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int getPlayerMove(int player, char board[][SIZE])
{
    char move;
    int validMove = 0;

    printf("Player %d, enter your move (1-9): ", player);

    do
    {
        scanf(" %c", &move);

        if (validateMove(move, board))
        {
            validMove = 1;
        }
        else
        {
            printf("Invalid move. Please try again: ");
        }
    } while (!validMove);

    return move - '0';
}

int validateMove(char move, char board[][SIZE])
{
    int i, j;

    if (!isdigit(move))
    {
        return 0;
    }

    int position = move - '0';

    if (position < 1 || position > SIZE*SIZE)
    {
        return 0;
    }

    i = (position-1) / SIZE;
    j = (position-1) % SIZE;

    return board[i][j] == '-';
}

int checkWin(char board[][SIZE])
{
    int i, j, count;

    // Check rows
    for (i = 0; i < SIZE; i++)
    {
        count = 0;

        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'X')
            {
                count++;
            }
            else if (board[i][j] == 'O')
            {
                count--;
            }
        }

        if (count == SIZE || count == -SIZE)
        {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < SIZE; j++)
    {
        count = 0;

        for (i = 0; i < SIZE; i++)
        {
            if (board[i][j] == 'X')
            {
                count++;
            }
            else if (board[i][j] == 'O')
            {
                count--;
            }
        }

        if (count == SIZE || count == -SIZE)
        {
            return 1;
        }
    }

    // Check diagonal
    count = 0;

    for (i = 0; i < SIZE; i++)
    {
        if (board[i][i] == 'X')
        {
            count++;
        }
        else if (board[i][i] == 'O')
        {
            count--;
        }
    }

    if (count == SIZE || count == -SIZE)
    {
        return 1;
    }

    // Check reverse diagonal
    count = 0;

    for (i = 0; i < SIZE; i++)
    {
        if (board[i][SIZE-1-i] == 'X')
        {
            count++;
        }
        else if (board[i][SIZE-1-i] == 'O')
        {
            count--;
        }
    }

    if (count == SIZE || count == -SIZE)
    {
        return 1;
    }

    return 0;
}

int checkDraw(char board[][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '-')
            {
                return 0;
            }
        }
    }

    return 1;
}

void getComputerMove(char board[][SIZE])
{
    int i, j, validMove;
    srand(time(NULL));

    do
    {
        validMove = 1;
        i = rand() % SIZE;
        j = rand() % SIZE;

        if (board[i][j] != '-')
        {
            validMove = 0;
        }

    } while (!validMove);

    printf("The computer has played at position %d, %d\n", i+1, j+1);
}