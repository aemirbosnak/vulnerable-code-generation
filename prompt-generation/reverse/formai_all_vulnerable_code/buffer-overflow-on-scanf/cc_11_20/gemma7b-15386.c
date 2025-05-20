//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int i, j, x, y, dir, speed, choice, shape, timer = 0, car_x = 0, car_y = 0;
    char board[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Display the board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Get the user's choice
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Move the car
    switch (choice)
    {
        case 1:
            dir = 0;
            speed = 5;
            break;
        case 2:
            dir = 1;
            speed = 5;
            break;
        case 3:
            dir = 2;
            speed = 5;
            break;
        case 4:
            dir = 3;
            speed = 5;
            break;
    }

    // Update the board
    board[car_x][car_y] = 'C';

    // Move the car
    for (timer = 0; timer < speed; timer++)
    {
        switch (dir)
        {
            case 0:
                car_y++;
                break;
            case 1:
                car_x++;
                break;
            case 2:
                car_y--;
                break;
            case 3:
                car_x--;
                break;
        }

        // Update the board
        board[car_x][car_y] = 'C';

        // Display the board
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Sleep
        sleep(0.1);
    }

    // Display the final board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}