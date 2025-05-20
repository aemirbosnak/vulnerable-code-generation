//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car {
    int position;
    int direction;
    int speed;
} Car;

Car cars[MAX_CARS];

void initialize_cars() {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].position = rand() % ROAD_LENGTH;
        cars[i].direction = rand() % 2;
        cars[i].speed = rand() % 5 + 1;
    }
}

void simulate_traffic_flow() {
    time_t start_time = time(NULL);
    time_t end_time = start_time + 10;

    while (time(NULL) < end_time) {
        for (int i = 0; i < MAX_CARS; i++) {
            switch (cars[i].direction) {
                case 0:
                    cars[i].position++;
                    break;
                case 1:
                    cars[i].position--;
                    break;
            }

            if (cars[i].position >= ROAD_LENGTH) {
                cars[i].direction = 1;
            }

            if (cars[i].position <= 0) {
                cars[i].direction = 0;
            }
        }

        sleep(1);
    }
}

int main() {
    initialize_cars();
    simulate_traffic_flow();

    return 0;
}