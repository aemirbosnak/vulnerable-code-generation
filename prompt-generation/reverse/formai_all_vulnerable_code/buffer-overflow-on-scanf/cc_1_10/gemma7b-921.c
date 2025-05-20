//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    // Game Board
    int board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Player's Turn
    int turn = 0;

    // Game Loop
    while (!board[4][4] && turn < MAX_SIZE * MAX_SIZE)
    {
        // Get Player's Move
        int x, y;
        printf("Enter move (x, y): ");
        scanf("%d %d", &x, &y);

        // Validate Move
        if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place Piece
        board[x][y] = turn;

        // Toggle Turn
        turn++;
    }

    // Game Over
    printf("Game over!\n");

    // Print Board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}