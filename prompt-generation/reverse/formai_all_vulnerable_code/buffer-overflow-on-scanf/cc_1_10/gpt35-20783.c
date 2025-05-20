//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 30

void init_map(char map[HEIGHT][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            map[i][j] = '#';
        }
    }
}

void print_map(char map[HEIGHT][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generate_map(char map[HEIGHT][WIDTH], int seed)
{
    int i, j;
    
    srand(seed);

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (rand() % 100 < 40)
            {
                map[i][j] = '.';
            }
        }
    }
}

int main()
{
    char map[HEIGHT][WIDTH];
    int seed;

    printf("Enter the seed:");
    scanf("%d", &seed);

    init_map(map);
    generate_map(map, seed);
    print_map(map);

    return 0;
}