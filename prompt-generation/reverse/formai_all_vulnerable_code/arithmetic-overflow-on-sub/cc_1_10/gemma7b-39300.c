//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Pacman
{
    int x;
    int y;
    int direction;
} Pacman;

Pacman pacman;

void draw_map(void)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == pacman.x && y == pacman.y)
            {
                printf("P");
            }
            else if (x == 0 || x == WIDTH - 1)
            {
                printf("=");
            }
            else if (y == 0 || y == HEIGHT - 1)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void move_pacman(void)
{
    switch (pacman.direction)
    {
        case 0:
            pacman.x++;
            break;
        case 1:
            pacman.y++;
            break;
        case 2:
            pacman.x--;
            break;
        case 3:
            pacman.y--;
            break;
    }

    if (pacman.x < 0 || pacman.x >= WIDTH)
    {
        pacman.direction ^= 2;
    }

    if (pacman.y < 0 || pacman.y >= HEIGHT)
    {
        pacman.direction ^= 3;
    }
}

int main(void)
{
    time_t t = time(NULL);

    pacman.x = WIDTH / 2;
    pacman.y = HEIGHT / 2;
    pacman.direction = 0;

    while (time(NULL) - t < 10)
    {
        move_pacman();
        draw_map();
        sleep(0.1);
    }

    return 0;
}