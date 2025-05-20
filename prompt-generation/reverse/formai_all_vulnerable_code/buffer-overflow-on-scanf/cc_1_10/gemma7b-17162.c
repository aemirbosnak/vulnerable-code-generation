//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, traffic_light, time_step;
    int cars_at_intersection[10] = {0};
    int road_status[10][10] = {{0}};

    printf("Enter the number of intersections:");
    scanf("%d", &n);

    printf("Enter the number of roads:");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            road_status[i][j] = 0;
        }
    }

    printf("Enter the time step:");
    scanf("%d", &time_step);

    traffic_light = 0;

    for (k = 0; k < time_step; k++)
    {
        for (l = 0; l < n; l++)
        {
            cars_at_intersection[l] = 0;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (road_status[i][j] == 1)
                {
                    cars_at_intersection[i]++;
                }
            }
        }

        traffic_light = (traffic_light + 1) % n;

        printf("Time step: %d\n", k);
        printf("Traffic light: %d\n", traffic_light);
        printf("Cars at intersection: ");

        for (l = 0; l < n; l++)
        {
            printf("%d ", cars_at_intersection[l]);
        }

        printf("\n");
    }

    return 0;
}