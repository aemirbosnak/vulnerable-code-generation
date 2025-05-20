//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_DISKS 10
#define TOWER_SIZE 3

void draw_tower(int tower[TOWER_SIZE], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

int main()
{
    int n, steps = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if(n < 1 || n > MAX_DISKS)
    {
        printf("Invalid number of disks.\n");
        return 1;
    }

    int tower[TOWER_SIZE];
    memset(tower, -1, sizeof(tower));
    tower[0] = 0;

    int source = 0, target = 2, temp = -1;
    srand(time(NULL));
    int choice = rand() % 2;

    if(choice == 0)
    {
        source = 0;
        target = 1;
        temp = 2;
    }
    else
    {
        source = 2;
        target = 1;
        temp = 0;
    }

    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    printf("Initial state:\n");
    draw_tower(tower, n);

    while(steps < (int)pow(2, n) - 1)
    {
        if(source == target)
        {
            source = (source + 1) % TOWER_SIZE;
        }
        else if(source == temp)
        {
            source = target;
        }
        else
        {
            target = temp;
        }

        if(tower[source] > -1)
        {
            tower[target] = tower[source];
            tower[source] = -1;
            steps++;
        }
        else
        {
            printf("Invalid move.\n");
        }

        printf("Current state:\n");
        draw_tower(tower, n);
    }

    printf("Congratulations! You solved the Tower of Hanoi problem with %d steps.\n", steps);

    return 0;
}