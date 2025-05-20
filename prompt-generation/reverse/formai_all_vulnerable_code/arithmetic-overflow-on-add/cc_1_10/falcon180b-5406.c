//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 100
#define MAX_CARS 1000
#define MAX_TIME 86400 // 24 hours

typedef struct {
    int id;
    int speed;
    int lane;
    int start_time;
    int end_time;
} Car;

typedef struct {
    int length;
    int capacity;
    int cars_passed;
} Road;

int main() {
    srand(time(NULL));

    int num_roads = rand() % MAX_ROADS + 1;
    int num_cars = rand() % MAX_CARS + 1;

    Road roads[num_roads];
    Car cars[num_cars];

    for (int i = 0; i < num_roads; i++) {
        roads[i].length = rand() % 100 + 1;
        roads[i].capacity = rand() % 100 + 1;
        roads[i].cars_passed = 0;
    }

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % 100 + 1;
        cars[i].lane = rand() % 4;
        cars[i].start_time = rand() % MAX_TIME;
        cars[i].end_time = cars[i].start_time + rand() % (MAX_TIME - cars[i].start_time) + 1;
    }

    int current_time = 0;
    while (current_time < MAX_TIME) {
        for (int i = 0; i < num_cars; i++) {
            if (current_time >= cars[i].start_time && current_time <= cars[i].end_time) {
                int road_id = cars[i].lane - 1;
                int distance_traveled = (current_time - cars[i].start_time) * cars[i].speed / MAX_TIME;

                if (distance_traveled > roads[road_id].length) {
                    roads[road_id].cars_passed++;
                    cars[i].end_time = current_time;
                } else {
                    int position = distance_traveled / roads[road_id].length;
                    if (position < roads[road_id].capacity) {
                        roads[road_id].cars_passed++;
                    }
                }
            }
        }

        current_time++;
    }

    for (int i = 0; i < num_roads; i++) {
        printf("Road %d: %d cars passed, capacity %d\n", i, roads[i].cars_passed, roads[i].capacity);
    }

    return 0;
}