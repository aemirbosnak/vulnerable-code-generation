//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, l, m, n, vehicles = 20, time_limit = 10;
    char road[5][10] = {
        { 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A' }
    };

    // Vehicle movement simulation
    for (k = 0; k < time_limit; k++)
    {
        for (i = 0; i < vehicles; i++)
        {
            // Randomly choose direction
            l = rand() % 4;
            switch (l)
            {
                case 0:
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'X';
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'V';
                    break;
                case 1:
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'X';
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'H';
                    break;
                case 2:
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'X';
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'D';
                    break;
                case 3:
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'X';
                    road[road[i][0] - 'A'][road[i][1] - 'A'] = 'R';
                    break;
            }
        }
    }

    // Display the road
    for (m = 0; m < 5; m++)
    {
        for (n = 0; n < 10; n++)
        {
            printf("%c ", road[m][n]);
        }
        printf("\n");
    }

    return 0;
}