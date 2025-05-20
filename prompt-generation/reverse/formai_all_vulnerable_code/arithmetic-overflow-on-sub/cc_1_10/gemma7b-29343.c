//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car
{
    int lane;
    int speed;
    int position;
    struct Car* next;
} Car;

Car* createCar(int lane, int speed, int position)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->lane = lane;
    newCar->speed = speed;
    newCar->position = position;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow(Car* head)
{
    time_t start = time(NULL);
    int i = 0;
    while (time(NULL) - start < 10)
    {
        for (Car* car = head; car; car = car->next)
        {
            // Update car position
            car->position++;

            // Change lane if necessary
            if (car->speed > 0 && car->position % 5 == 0)
            {
                int newLane = rand() % NUM_LANE;
                if (newLane != car->lane)
                {
                    car->lane = newLane;
                }
            }

            // Simulate braking
            if (car->position >= MAX_CARS)
            {
                car->speed = 0;
            }
        }

        i++;
    }
}

int main()
{
    Car* head = createCar(0, 5, 0);
    head = createCar(1, 3, 1);
    head = createCar(2, 2, 2);

    simulateTrafficFlow(head);

    return 0;
}