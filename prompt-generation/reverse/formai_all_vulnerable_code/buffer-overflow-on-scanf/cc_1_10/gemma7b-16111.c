//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0, direction = 1, map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    system("clear");
    printf("Welcome to the Cave Adventure!\n");
    printf("------------------------\n");

    while (x != 9 || y != 9)
    {
        system("clear");
        printf("You are at (%d, %d).\n", x, y);
        printf("Map:\n");

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }

        printf("Enter direction (N, S, E, W): ");
        char direction_input;
        scanf(" %c", &direction_input);

        switch (direction_input)
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        if (map[x][y] == 1)
        {
            printf("Congratulations! You have found the treasure!\n");
            break;
        }
    }

    system("clear");
    printf("Thank you for playing! See you next time.\n");

    return 0;
}