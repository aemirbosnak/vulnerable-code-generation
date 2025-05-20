//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

#define LEFT_WALL 0
#define RIGHT_WALL WIDTH - 1
#define TOP_WALL 0
#define BOTTOM_WALL HEIGHT - 1

int main()
{

    int x = 2;
    int y = 2;

    // Game loop
    while (1)
    {
        // Display the maze
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (x == j && y == i)
                {
                    printf("O ");
                }
                else if (j == LEFT_WALL || j == RIGHT_WALL || i == TOP_WALL || i == BOTTOM_WALL)
                {
                    printf("# ");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Get the user input
        char input;
        scanf(" %c", &input);

        // Move the paddle
        switch (input)
        {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            default:
                break;
        }

        // Check if the paddle has moved out of the bounds
        if (x < LEFT_WALL || x > RIGHT_WALL)
        {
            x = 2;
        }
        if (y < TOP_WALL || y > BOTTOM_WALL)
        {
            y = 2;
        }
    }

    return 0;
}