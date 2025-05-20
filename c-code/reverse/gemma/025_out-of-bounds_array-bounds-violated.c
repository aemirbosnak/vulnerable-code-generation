#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 5
#define MAX_COLS 5

int main()
{
    char map[MAX_ROWS][MAX_COLS] = {{'A', 'B', 'C', 'D', 'E'},
                              {'F', 'G', 'H', 'I', 'J'},
                              {'K', 'L', 'M', 'N', 'O'},
                              {'P', 'Q', 'R', 'S', 'T'},
                              {'U', 'V', 'W', 'X', 'Y'}};

    int row, col;
    printf("Enter row and column (e.g. 2 3): ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS)
    {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    if (map[row][col] == 'O' || map[row][col] == 'S')
    {
        printf("You have reached a boundary condition!\n");
    }
    else
    {
        printf("You are at position (%d, %d).", row, col);
    }

    return 0;
}
