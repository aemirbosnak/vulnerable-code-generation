//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10

typedef struct Car
{
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* CreateCar(int position, int direction, int speed)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->speed = speed;
    newCar->next = NULL;

    return newCar;
}

void SimulateTrafficFlow(Car* head)
{
    time_t start = time(NULL);

    while (time(NULL) - start < 10)
    {
        for (Car* currentCar = head; currentCar; currentCar = currentCar->next)
        {
            switch (currentCar->direction)
            {
                case 0:
                    currentCar->position++;
                    if (currentCar->position >= MAX_Cars - 1)
                        currentCar->direction = 1;
                    break;
                case 1:
                    currentCar->position--;
                    if (currentCar->position <= 0)
                        currentCar->direction = 0;
                    break;
            }

            currentCar->speed++;
            if (currentCar->speed >= 5)
                currentCar->speed = 5;
        }

        sleep(1);
    }

    printf("Traffic flow simulation complete.\n");
}

int main()
{
    Car* head = CreateCar(0, 0, 2);
    CreateCar(2, 1, 3);
    CreateCar(4, 0, 4);

    SimulateTrafficFlow(head);

    return 0;
}