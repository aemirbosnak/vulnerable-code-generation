//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROAD_LENGTH 10
#define MAX_CAR_SPEED 5

typedef struct {
    int position;
    int speed;
} Car;

int main() {
    srand(time(NULL));
    int road[MAX_ROAD_LENGTH] = {0}; // Road with no cars

    // Adding random cars to the road
    int num_cars = rand() % MAX_ROAD_LENGTH;
    Car cars[num_cars];
    for (int i = 0; i < num_cars; i++) {
        cars[i].position = i+1;
        cars[i].speed = rand() % MAX_CAR_SPEED + 1;
        road[cars[i].position-1] = 1; // Marking the car's position on the road
    }

    // Simulating the traffic flow
    int t = 0; // Time step
    while (1) {
        printf("t = %d: ", t+1);

        // Displaying the cars' positions
        for (int i = 0; i < MAX_ROAD_LENGTH; i++) {
            if (road[i] == 1) {
                int car_index = -1;
                for (int j = 0; j < num_cars; j++) {
                    if (cars[j].position == i+1) {
                        car_index = j;
                        break;
                    }
                }
                printf("X");
                if (cars[car_index].speed < MAX_ROAD_LENGTH - i) {
                    // Move the car forward
                    road[i] = 0;
                    road[i+cars[car_index].speed] = 1;
                    cars[car_index].position += cars[car_index].speed;
                } else {
                    // Car has reached the end of the road
                    road[i] = 0;
                    cars[car_index].position = -1;
                    num_cars--;
                }
            } else {
                printf("-");
            }
        }
        printf("\n");

        if (num_cars == 0) break; // No more cars on the road
        t++;
    }

    return 0;
}