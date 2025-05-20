//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 5
#define MAX_SPEED 100
#define MAX_CARS 10
#define MAX_TIME 20

struct Car {
    int id;
    int speed;
    int pos;
};

struct Road {
    int id;
    int length;
    struct Car cars[MAX_CARS];
};

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    struct Road roads[MAX_ROADS]; // Create an array of roads
    int time = 0; // Initialize time to 0

    // Initialize each road with random id and length
    for(int i = 0; i < MAX_ROADS; i++) {
        roads[i].id = i;
        roads[i].length = rand() % MAX_SPEED + 1;
    }

    // Start the simulation loop
    while(time < MAX_TIME) {
        printf("Time %d:\n", time); // Print current time

        // Move cars on each road
        for(int i = 0; i < MAX_ROADS; i++) {
            struct Road road = roads[i];
            printf("Road %d\n", road.id);

            // Move each car on the road
            for(int j = 0; j < MAX_CARS; j++) {
                struct Car car = road.cars[j];

                // If the car is not at the end of the road
                if(car.pos < road.length) {
                    // Determine if the car can move
                    int can_move = 1;
                    for(int k = car.pos + 1; k <= car.pos + car.speed; k++) {
                        if(k < road.length) {
                            // Check if the next spot is occupied by another car
                            if(road.cars[k].id != -1) {
                                can_move = 0;
                                break;
                            }
                        } else {
                            // The car has reached the end of the road
                            break;
                        }
                    }

                    // Move the car
                    if(can_move) {
                        // Update car position
                        road.cars[j].pos += car.speed;

                        // Clear old position
                        road.cars[car.pos].id = -1;

                        // Update new position
                        road.cars[car.pos + car.speed].id = car.id;
                        road.cars[car.pos + car.speed].speed = car.speed;
                        road.cars[car.pos + car.speed].pos = car.pos + car.speed;

                        printf("Car %d moved from position %d to position %d with speed %d\n", car.id, car.pos, car.pos + car.speed, car.speed);
                    } else {
                        printf("Car %d at position %d is unable to move\n", car.id, car.pos);
                    }
                }
            }

            printf("\n");
        }

        time++; // Increment time
    }

    return 0;
}