//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    int direction;
} Car;

Car cars[MAX_CARS];

void initialize_cars()
{
    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i].lane = rand() % MAX_LANE;
        cars[i].position = rand() % 100;
        cars[i].speed = rand() % 5 + 1;
        cars[i].direction = rand() % 2;
    }
}

void simulate_traffic()
{
    time_t start_time = time(NULL);
    time_t current_time = time(NULL);

    while (current_time - start_time < 10)
    {
        for (int i = 0; i < MAX_CARS; i++)
        {
            switch (cars[i].direction)
            {
                case 0:
                    cars[i].position++;
                    break;
                case 1:
                    cars[i].position--;
                    break;
            }

            if (cars[i].position >= 100)
            {
                cars[i].direction = 1;
            }
            if (cars[i].position <= 0)
            {
                cars[i].direction = 0;
            }
        }

        current_time = time(NULL);
    }
}

int main()
{
    initialize_cars();
    simulate_traffic();

    return 0;
}