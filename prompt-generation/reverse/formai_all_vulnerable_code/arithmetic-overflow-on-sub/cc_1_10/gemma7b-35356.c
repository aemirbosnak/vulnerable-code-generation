//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int speed;
    int position;
} Car;

Car cars[MAX_CARS];

void simulateTrafficFlow()
{
    int i, j;
    time_t t;

    for (i = 0; i < MAX_CARS; i++)
    {
        cars[i].position = 0;
        cars[i].speed = rand() % 5 + 1;
        cars[i].lane = rand() % MAX_LANE;
    }

    t = time(NULL);
    while (time(NULL) - t < 10)
    {
        for (i = 0; i < MAX_CARS; i++)
        {
            cars[i].position += cars[i].speed;

            if (cars[i].position >= MAX_LANE)
            {
                cars[i].position = MAX_LANE - 1;
                cars[i].speed = -cars[i].speed;
            }

            if (cars[i].position <= 0)
            {
                cars[i].position = 0;
                cars[i].speed = -cars[i].speed;
            }
        }

        printf("\n");
        for (j = 0; j < MAX_LANE; j++)
        {
            for (i = 0; i < MAX_CARS; i++)
            {
                if (cars[i].lane == j)
                {
                    printf("%c ", cars[i].position + 1);
                }
                else
                {
                    printf(". ");
                }
            }

            printf("\n");
        }

        sleep(1);
    }
}

int main()
{
    simulateTrafficFlow();

    return 0;
}