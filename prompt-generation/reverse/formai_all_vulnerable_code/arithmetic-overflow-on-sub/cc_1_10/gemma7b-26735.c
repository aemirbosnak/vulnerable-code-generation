//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
    time_t start = time(NULL);
    while (time(NULL) - start < 60) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->x--;
                    break;
                case 2:
                    car->y++;
                    break;
                case 3:
                    car->y--;
                    break;
            }

            if (car->x == MAX_LANE - 1 && car->direction == 0) {
                car->direction = 1;
            } else if (car->x == 0 && car->direction == 1) {
                car->direction = 0;
            } else if (car->y == MAX_CARS - 1 && car->direction == 2) {
                car->direction = 3;
            } else if (car->y == 0 && car->direction == 3) {
                car->direction = 2;
            }

            sleep(1);
        }
    }
}

int main() {
    Car* head = malloc(sizeof(Car));
    head->x = 0;
    head->y = 0;
    head->direction = 0;
    head->speed = 1;
    head->next = NULL;

    simulateTrafficFlow(head);

    return 0;
}