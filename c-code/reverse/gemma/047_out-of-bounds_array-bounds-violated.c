#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    int player = 1;
    int row, col;

    // Game loop
    while (!board[row][col])
    {
        printf("Enter row (0-2): ");
        scanf("%d", &row);

        printf("Enter column (0-2): ");
        scanf("%d", &col);

        // Out-of-bounds check
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        board[row][col] = player;
        player = (player == 1) ? 2 : 1;
    }

    // Game over
    printf("Game over! The winner is: %d\n", board[row][col]);

    return 0;
}
