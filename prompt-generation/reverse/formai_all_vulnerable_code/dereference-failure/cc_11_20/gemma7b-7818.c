//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20
#define PLAYER_SIZE 2

int main()
{
    // Map creation
    int **map = (int **)malloc(MAP_SIZE * sizeof(int *));
    for(int i = 0; i < MAP_SIZE; i++)
    {
        map[i] = (int *)malloc(MAP_SIZE * sizeof(int));
    }

    // Player placement
    int x = 0, y = 0;
    map[x][y] = PLAYER_SIZE;

    // Game loop
    int game_over = 0;
    while(!game_over)
    {
        // Display the map
        for(int i = 0; i < MAP_SIZE; i++)
        {
            for(int j = 0; j < MAP_SIZE; j++)
            {
                if(map[i][j] == PLAYER_SIZE)
                {
                    printf("P ");
                }
                else
                {
                    printf("%c ", map[i][j]);
                }
            }
            printf("\n");
        }

        // Get player input
        char input;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &input);

        // Move the player
        switch(input)
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
                printf("Invalid move.\n");
                break;
        }

        // Check if the player has won or lost
        if(map[x][y] == 4)
        {
            game_over = 1;
            printf("You have won!\n");
        }
        else if(map[x][y] == -1)
        {
            game_over = 1;
            printf("You have lost.\n");
        }
    }

    // Free the map
    for(int i = 0; i < MAP_SIZE; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}