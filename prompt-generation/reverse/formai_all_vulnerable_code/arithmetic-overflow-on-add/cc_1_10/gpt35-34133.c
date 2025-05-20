//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { straight, left, right } Direction;
typedef enum { red, yellow, green } LightColor;

typedef struct {
    LightColor color;
    int timer;
} TrafficLight;

typedef struct {
    Direction direction;
    int speed;
    int distance;
} Car;

void wait(int seconds) {
    clock_t end_wait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_wait) {
        // Wait
    }
}

int main(void) {
    // Initialize traffic light at intersection
    TrafficLight light = {red, 30};
    
    // Initialize cars approaching intersection
    Car car1 = {straight, 40, 150};
    Car car2 = {left, 20, 100};
    Car car3 = {right, 30, 200};
    
    // Simulate traffic flow for 5 minutes
    int simTime = 5 * 60; // seconds
    for (int t = 0; t < simTime; t++) {
        printf("Time: %ds\n", t);
        
        // Check traffic light
        if (light.color == red) {
            printf("Traffic light is red\n");
            wait(light.timer);
            light.color = green;
            light.timer = 60;
        } else if (light.color == yellow) {
            printf("Traffic light is yellow\n");
            wait(light.timer);
            light.color = red;
            light.timer = 30;
        } else {
            printf("Traffic light is green\n");
            wait(light.timer);
            light.color = yellow;
            light.timer = 5;
        }
        
        // Move cars
        car1.distance -= car1.speed;
        car2.distance -= car2.speed;
        car3.distance -= car3.speed;
        
        // Check for collisions
        if (car1.distance <= 0) {
            printf("Car 1 collides with intersection!\n");
            break;
        } else if (car2.distance <= 0) {
            printf("Car 2 collides with intersection!\n");
            break;
        } else if (car3.distance <= 0) {
            printf("Car 3 collides with intersection!\n");
            break;
        }
    }
    
    printf("Simulation over.\n");
    
    return 0;
}