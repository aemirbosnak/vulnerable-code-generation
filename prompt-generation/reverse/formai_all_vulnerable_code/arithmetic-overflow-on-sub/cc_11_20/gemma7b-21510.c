//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int x, y, score = 0, direction = 0;
    char board[WIDTH][HEIGHT] = {{'.', '.', '.', '.', '.'},
                               {'.', '#', '.', '.', '.'},
                               {'.', '.', '#', '.', '.'},
                               {'.', '.', '.', '#', '.'},
                               {'.', '.', '.', '.', '.'}};

    system("clear");
    printf("Score: %d\n", score);

    while (1)
    {
        printf("Enter direction (w, a, s, d): ");
        char dir = getchar();

        switch (dir)
        {
            case 'w':
                direction = 0;
                break;
            case 'a':
                direction = 1;
                break;
            case 's':
                direction = 2;
                break;
            case 'd':
                direction = 3;
                break;
            default:
                printf("Invalid input.\n");
                continue;
        }

        switch (direction)
        {
            case 0:
                if (y - 1 >= 0)
                    y--;
                break;
            case 1:
                if (x - 1 >= 0)
                    x--;
                break;
            case 2:
                if (y + 1 < HEIGHT)
                    y++;
                break;
            case 3:
                if (x + 1 < WIDTH)
                    x++;
                break;
        }

        if (board[x][y] == '#')
        {
            printf("Game over!\n");
            break;
        }

        board[x][y] = 'O';
        system("clear");
        printf("Score: %d\n", score);
        printf("Board:\n");

        for (y = 0; y < HEIGHT; y++)
        {
            for (x = 0; x < WIDTH; x++)
            {
                printf("%c ", board[x][y]);
            }

            printf("\n");
        }
    }

    return 0;
}