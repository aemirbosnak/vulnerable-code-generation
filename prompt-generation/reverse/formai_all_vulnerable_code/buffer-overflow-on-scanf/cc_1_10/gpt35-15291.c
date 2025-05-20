//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000 //maximum number of cars
#define MAX_SPEED 100 //maximum speed of cars (in km/h)
#define MAX_DISTANCE 10000 //maximum distance between two cars (in meters)
#define MAX_TIME 300 //maximum simulation time (in seconds)

int main() {

    int num_cars, simulation_time;
    float distance[MAX_CARS], speed[MAX_CARS], time_passed, time_step, speed_limit;

    //get user input
    printf("Enter the number of cars in the simulation: ");
    scanf("%d", &num_cars);

    printf("Enter the simulation time (in seconds): ");
    scanf("%d", &simulation_time);

    printf("Enter the speed limit (in km/h): ");
    scanf("%f", &speed_limit);

    //initialize random seed
    srand(time(NULL));

    //initialize car distances and speeds
    for (int i = 0; i < num_cars; i++) {
        distance[i] = rand() % MAX_DISTANCE;
        speed[i] = rand() % MAX_SPEED + 1;
    }

    //set time step
    time_step = 0.1;

    //simulate traffic flow
    for (time_passed = 0; time_passed <= simulation_time; time_passed += time_step) {
        printf("Time: %.2f seconds\n", time_passed);

        //update car distances
        for (int i = 0; i < num_cars; i++) {
            distance[i] += speed[i] * (time_step / 3600); //convert speed from km/h to m/s
        }

        //check for collisions
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (distance[i] >= distance[j] && distance[i] - distance[j] <= 10) { //10 meters safety distance
                    printf("Collision between car %d and car %d!\n", i+1, j+1);
                    exit(0);
                }
            }
        }

        //check for cars exceeding speed limit
        for (int i = 0; i < num_cars; i++) {
            if (speed[i] > speed_limit) {
                printf("Car %d is exceeding the speed limit! (%.2f km/h)\n", i+1, speed[i]);
            }
        }
    }

    printf("Simulation complete.\n");
    return 0;
}