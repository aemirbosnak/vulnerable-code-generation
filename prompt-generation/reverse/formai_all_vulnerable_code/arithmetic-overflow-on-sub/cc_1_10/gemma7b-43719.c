//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int position, int direction, int speed)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->speed = speed;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow(Car* head)
{
    time_t t = time(NULL);
    while (time(NULL) - t < 10)
    {
        for (Car* currentCar = head; currentCar; currentCar = currentCar->next)
        {
            switch (currentCar->direction)
            {
                case 0:
                    currentCar->position++;
                    break;
                case 1:
                    currentCar->position--;
                    break;
                case 2:
                    currentCar->position++;
                    currentCar->direction = 0;
                    break;
                case 3:
                    currentCar->position--;
                    currentCar->direction = 1;
                    break;
            }

            if (currentCar->position > MAX_CARS - 1)
            {
                currentCar->position = MAX_CARS - 1;
            }
            if (currentCar->position < 0)
            {
                currentCar->position = 0;
            }
        }

        sleep(1);
    }
}

int main()
{
    Car* head = createCar(0, 0, 5);
    head = createCar(2, 1, 3);
    head = createCar(4, 2, 4);
    head = createCar(6, 3, 2);

    simulateTrafficFlow(head);

    return 0;
}