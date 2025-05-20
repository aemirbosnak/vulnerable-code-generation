//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>

#define SIZE 8

void printBoard(char board[][SIZE]);
int moveIsLegal(char board[][SIZE], int fromX, int fromY, int toX, int toY);

int main()
{
    char board[SIZE][SIZE] = {
        {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
        {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
        {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'r', '_', 'r', '_', 'r', '_', 'r', '_'},
        {'_', 'r', '_', 'r', '_', 'r', '_', 'r'},
        {'r', '_', 'r', '_', 'r', '_', 'r', '_'}
    };

    printBoard(board);

    int fromX, fromY, toX, toY;
    printf("Enter coordinates for move (fromX, fromY, toX, toY):\n");
    scanf("%d %d %d %d", &fromX, &fromY, &toX, &toY);

    if (moveIsLegal(board, fromX, fromY, toX, toY))
    {
        board[toY][toX] = board[fromY][fromX];
        board[fromY][fromX] = '_';
        printBoard(board);
        printf("Move successful!\n");
    }
    else
    {
        printBoard(board);
        printf("Illegal move. Try again.\n");
    }

    return 0;
}

void printBoard(char board[][SIZE])
{
    printf("\n   0 1 2 3 4 5 6 7\n");
    for (int y = 0; y < SIZE; y++)
    {
        printf("%d  ", y);
        for (int x = 0; x < SIZE; x++)
        {
            printf("%c ", board[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

int moveIsLegal(char board[][SIZE], int fromX, int fromY, int toX, int toY)
{
    // Moves off the board are not allowed
    if (fromX < 0 || fromX >= SIZE || fromY < 0 || fromY >= SIZE || toX < 0 || toX >= SIZE || toY < 0 || toY >= SIZE)
    {
        return 0;
    }

    // Only diagonals moves are allowed
    if ((toX - fromX) != (toY - fromY) && (toX - fromX) != -(toY - fromY))
    {
        return 0;
    }

    // Destination position is occupied
    if (board[toY][toX] != '_')
    {
        return 0;
    }

    // Moving backwards is not allowed
    if (board[fromY][fromX] == 'r' && toY > fromY)
    {
        return 0;
    }

    if (board[fromY][fromX] == 'b' && toY < fromY)
    {
        return 0;
    }

    return 1;
}