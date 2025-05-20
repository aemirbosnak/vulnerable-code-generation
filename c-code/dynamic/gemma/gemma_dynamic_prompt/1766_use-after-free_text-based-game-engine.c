#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < 10 && y >= 0 && y < 10 && map[x][y] == 0)
    {
        map[x][y] = 1;
        printf("Move successful!\n");
    }
    else
    {
        printf("Invalid move. Please try again.\n");
    }

    return 0;
}
