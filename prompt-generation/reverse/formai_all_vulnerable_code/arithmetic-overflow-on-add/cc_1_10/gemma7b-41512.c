//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void traverse(int x, int y, int z);

void haunt(int x, int y, int z)
{
    srand(time(NULL));
    int r = rand() % 3;
    switch (r)
    {
        case 0:
            printf("You hear a disembodied scream echoing through the halls.\n");
            break;
        case 1:
            printf("A cold wind whips through you, carrying with it the scent of decaying roses.\n");
            break;
        case 2:
            printf("You sense a presence lurking behind you, a hairsbreadth away.\n");
            break;
    }
}

int main()
{
    int x, y, z;
    printf("Enter the coordinates of your current position: ");
    scanf("%d %d %d", &x, &y, &z);

    traverse(x, y, z);

    return 0;
}

void traverse(int x, int y, int z)
{
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int dz[] = {0, 0, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        int newz = z + dz[i];

        haunt(newx, newy, newz);
    }
}