//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int speed;
    int direction;
    int position;
    int waitingTime;
} Car;

int main() {
    int numCars, roadCapacity, i;
    Car cars[100];
    int road[100];

    printf("Enter the number of cars: ");
    scanf("%d", &numCars);

    printf("Enter the road capacity: ");
    scanf("%d", &roadCapacity);

    srand(time(NULL));
    for (i = 0; i < numCars; i++) {
        cars[i].id = i + 1;
        cars[i].speed = rand() % 6 + 1;
        cars[i].direction = rand() % 2;
        cars[i].position = -1;
        cars[i].waitingTime = 0;
    }

    for (i = 0; i < roadCapacity; i++) {
        road[i] = 0;
    }

    int currentTime = 0;
    while (currentTime < 100) {
        currentTime++;

        for (i = 0; i < numCars; i++) {
            if (cars[i].position == -1) {
                int j;
                for (j = 0; j < roadCapacity; j++) {
                    if (road[j] == 0) {
                        cars[i].position = j;
                        road[j] = 1;
                        break;
                    }
                }
            } else {
                if (cars[i].direction == 1) {
                    cars[i].position++;
                } else {
                    cars[i].position--;
                }

                if (cars[i].position < 0 || cars[i].position >= roadCapacity) {
                    cars[i].position = -1;
                }
            }
        }

        for (i = 0; i < roadCapacity; i++) {
            if (road[i] == 1) {
                int carId = cars[road[i]].id;
                printf("%d is on the road at position %d\n", carId, i);
            }
        }

        for (i = 0; i < numCars; i++) {
            if (cars[i].position!= -1) {
                cars[i].waitingTime++;
            }
        }
    }

    return 0;
}