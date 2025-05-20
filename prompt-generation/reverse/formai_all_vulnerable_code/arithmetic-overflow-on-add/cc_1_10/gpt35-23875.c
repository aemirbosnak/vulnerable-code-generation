//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MAX_INTERVAL 60
#define MAX_CARS 10

void delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int random_range(int min_num, int max_num)
{
    return (rand() % (max_num - min_num + 1)) + min_num;
}

typedef struct
{
    int speed;
    int distance;
} Car;

int main()
{
    srand(time(NULL));
    Car cars[MAX_CARS];
    int interval = random_range(1, MAX_INTERVAL);

    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i].speed = random_range(1, MAX_SPEED);
        cars[i].distance = interval * cars[i].speed;
    }

    printf("Starting traffic simulation...\n");

    for (int i = 1; i <= 60; i++)
    {
        printf("Time: %d second\n", i);

        for (int j = 0; j < MAX_CARS; j++)
        {
            cars[j].distance -= cars[j].speed;

            if (cars[j].distance <= 0)
            {
                printf("Car %d: Arrived at destination.\n", j + 1);

                if (i % 10 == 0)
                {
                    printf("Happy %dth second!\n", i);
                }

                cars[j].speed = 0;
                cars[j].distance = 0;
            }
            else
            {
                printf("Car %d: Distance to destination: %d meters\n", j + 1, cars[j].distance);
            }

            delay(500);
        }
    }

    printf("Traffic simulation finished!\n");

    return 0;
}