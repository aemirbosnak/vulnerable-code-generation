//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Enter the dimensions of the room (in squares): ");
    scanf("%d %d", &x, &y);

    int **map = malloc(x * sizeof(int *)), **map_data = malloc(x * y * sizeof(int));

    for (int i = 0; i < x; i++)
    {
        map[i] = malloc(y * sizeof(int));
        for (int j = 0; j < y; j++)
        {
            map[i][j] = 0;
        }
    }

    printf("Enter the number of monsters: ");
    int num_monsters = atoi(stdin);

    for (int i = 0; i < num_monsters; i++)
    {
        printf("Enter the position of the monster (in squares): ");
        int monster_x = atoi(stdin);
        int monster_y = atoi(stdin);

        map[monster_x][monster_y] = 1;
    }

    printf("Enter the position of the hero (in squares): ");
    int hero_x = atoi(stdin);
    int hero_y = atoi(stdin);

    map[hero_x][hero_y] = 2;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            switch (map[i][j])
            {
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("M");
                    break;
                case 2:
                    printf("H");
                    break;
            }
        }
        printf("\n");
    }

    free(map);
    free(map_data);

    return 0;
}