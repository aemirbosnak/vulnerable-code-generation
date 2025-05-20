//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, score = 0, matrix[5][5] = {{0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0}};

    printf("Welcome to the Breakout Game!\n");
    printf("Your score: %d\n", score);

    while (1)
    {
        printf("Enter the direction (w, a, s, d): ");
        char direction;
        scanf("%c", &direction);

        switch (direction)
        {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        if (matrix[y][x] == 1)
        {
            printf("Game over! Your score: %d\n", score);
            break;
        }

        if (matrix[y][x] == 0)
        {
            matrix[y][x] = 1;
            score++;
            printf("Your score: %d\n", score);
        }
    }

    return 0;
}