//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int direction;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % MAX_LANE;
    car->direction = rand() % 2;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* head)
{
    time_t t = time(NULL);
    while (time(NULL) - t < 10)
    {
        Car* currentCar = head;
        while (currentCar)
        {
            switch (currentCar->direction)
            {
                case 0:
                    currentCar->position++;
                    if (currentCar->position == MAX_LANE)
                        currentCar->direction = 1;
                    break;
                case 1:
                    currentCar->position--;
                    if (currentCar->position == 0)
                        currentCar->direction = 0;
                    break;
            }
            currentCar = currentCar->next;
        }
        sleep(1);
    }
}

int main()
{
    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();

    simulateTrafficFlow(head);

    return 0;
}