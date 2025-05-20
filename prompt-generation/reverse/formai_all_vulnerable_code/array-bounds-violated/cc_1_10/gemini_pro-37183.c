//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numRings;
    int from;
    int to;
    int via;
} move;

void towerOfHanoi(int numRings, int from, int to, int via)
{
    if (numRings == 1)
    {
        printf("Move ring 1 from rod %d to rod %d\n", from, to);
    }
    else
    {
        towerOfHanoi(numRings - 1, from, via, to);
        printf("Move ring %d from rod %d to rod %d\n", numRings, from, to);
        towerOfHanoi(numRings - 1, via, to, from);
    }
}

int main()
{
    int totalRings;
    printf("Enter the number of rings: ");
    scanf("%d", &totalRings);

    move moves[totalRings];
    int currentRing = totalRings;
    int currentFrom = 1;
    int currentTo = 2;
    int currentVia = 3;
    for (int i = 0; i < totalRings; i++)
    {
        moves[i].numRings = currentRing;
        moves[i].from = currentFrom;
        moves[i].to = currentTo;
        moves[i].via = currentVia;

        currentRing--;
        if (currentFrom == 1)
        {
            currentFrom = 2;
            currentTo = 1;
            currentVia = 3;
        }
        else if (currentFrom == 2)
        {
            currentFrom = 3;
            currentTo = 2;
            currentVia = 1;
        }
        else
        {
            currentFrom = 1;
            currentTo = 3;
            currentVia = 2;
        }
    }

    for (int i = totalRings - 1; i >= 0; i--)
    {
        towerOfHanoi(moves[i].numRings, moves[i].from, moves[i].to, moves[i].via);
    }

    return 0;
}