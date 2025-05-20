//Falcon-180B DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int player_x = rand() % 10;
    int player_y = rand() % 10;

    int maze[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    int score = 0;

    while(1)
    {
        system("clear");
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(maze[i][j] == 1)
                {
                    printf("\033[1;31m");
                }
                else
                {
                    printf("\033[1;32m");
                }
                printf("  ");
            }
            printf("\n");
        }

        printf("\033[1;33m");
        printf("Score: %d\n", score);
        printf("\033[0m");

        if(player_x == 0 && player_y == 0)
        {
            printf("\033[1;31m");
            printf("Game Over\n");
            printf("\033[0m");
            break;
        }

        char move;
        scanf("%c", &move);

        switch(move)
        {
            case 'w':
                if(player_y > 0 && maze[player_x][player_y-1] == 0)
                {
                    player_y--;
                    score++;
                }
                break;

            case 'a':
                if(player_x > 0 && maze[player_x-1][player_y] == 0)
                {
                    player_x--;
                    score++;
                }
                break;

            case's':
                if(player_y < 9 && maze[player_x][player_y+1] == 0)
                {
                    player_y++;
                    score++;
                }
                break;

            case 'd':
                if(player_x < 9 && maze[player_x+1][player_y] == 0)
                {
                    player_x++;
                    score++;
                }
                break;

            default:
                printf("\033[1;31m");
                printf("Invalid move\n");
                printf("\033[0m");
        }

        usleep(500000);
    }

    return 0;
}