//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct car
{
    int lane;
    int position;
    int direction;
    int speed;
    struct car* next;
} car;

car* createCar()
{
    car* newCar = (car*)malloc(sizeof(car));
    newCar->lane = rand() % MAX_LANE;
    newCar->position = rand() % 100;
    newCar->direction = rand() % 2;
    newCar->speed = rand() % 5;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow()
{
    car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();

    time_t start = time(NULL);
    while (time(NULL) - start < 10)
    {
        for (car* currentCar = head; currentCar; currentCar = currentCar->next)
        {
            currentCar->position += currentCar->speed * (currentCar->direction ? 1 : -1);

            if (currentCar->position >= 100)
            {
                currentCar->direction *= -1;
                currentCar->position = 0;
            }

            if (currentCar->position <= 0)
            {
                currentCar->direction *= -1;
                currentCar->position = 100;
            }
        }

        sleep(1);
    }

    free(head);
}

int main()
{
    simulateTrafficFlow();

    return 0;
}