//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ROADS 10
#define BASE_SPEED 30
#define STOPLIGHT_DURATION 5

typedef struct {
    int speed;
    int distance;
} vehicle;

typedef struct {
    int length;
    int speed_limit;
    int num_vehicles;
    vehicle* vehicles;
} road;

typedef struct {
    int duration;
    int time_since_last_change;
    int is_green;
} stoplight;

int main() {
    srand(time(NULL)); // seed random number generator
    
    // initialize roads
    road roads[MAX_ROADS];
    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i].length = rand() % 100 + 100; // length between 100 and 199 units
        roads[i].speed_limit = BASE_SPEED + rand() % 10; // speed limit between 30 and 39 units
        roads[i].num_vehicles = rand() % 5 + 1; // between 1 and 5 vehicles
        roads[i].vehicles = calloc(roads[i].num_vehicles, sizeof(vehicle));
        for (int j = 0; j < roads[i].num_vehicles; j++) {
            roads[i].vehicles[j].speed = BASE_SPEED + rand() % 10; // vehicle speed between 30 and 39 units
            roads[i].vehicles[j].distance = rand() % (roads[i].length - 50)  + 50; // initial position between 50 and (length - 50) units
        }
    }
    
    // initialize stoplights
    stoplight s1 = {STOPLIGHT_DURATION, 0, 0};
    stoplight s2 = {STOPLIGHT_DURATION, 0, 1};
    
    // keep track of simulation time
    int time = 0;
    
    // run simulation
    while (time < 100) { // run for 100 units of time
        // update vehicles on roads
        for (int i = 0; i < MAX_ROADS; i++) {
            for (int j = 0; j < roads[i].num_vehicles; j++) {
                if (roads[i].vehicles[j].distance > 0) { // vehicle is on road
                    if (i == 0 && s1.is_green && s1.time_since_last_change > s1.duration) { // stoplight is green
                        roads[i].vehicles[j].distance -= roads[i].speed_limit; // accelerate to speed limit
                    } else {
                        roads[i].vehicles[j].distance -= roads[i].vehicles[j].speed; // vehicle maintains speed
                    }
                } else { // vehicle reaches end of road
                    if (i < MAX_ROADS - 1) { // vehicle can move to next road
                        int k = 0;
                        while (k < roads[i+1].num_vehicles && roads[i+1].vehicles[k].distance < 50) { // avoid collision with other vehicles at start of road
                            k++;
                        }
                        if (k == roads[i+1].num_vehicles) { // no obstacle ahead, vehicle can move to next road
                            roads[i+1].num_vehicles++;
                            roads[i+1].vehicles = realloc(roads[i+1].vehicles, roads[i+1].num_vehicles * sizeof(vehicle));
                            roads[i+1].vehicles[roads[i+1].num_vehicles-1].speed = roads[i].vehicles[j].speed;
                            roads[i+1].vehicles[roads[i+1].num_vehicles-1].distance = 50;
                        }
                    }
                    roads[i].num_vehicles--;
                    for (int k = j; k < roads[i].num_vehicles; k++) {
                        roads[i].vehicles[k] = roads[i].vehicles[k+1];
                    }
                    j--; // process the same index again since the array shifted left
                }
            }
        }
        
        // update stoplights
        s1.time_since_last_change++;
        if (s1.time_since_last_change > s1.duration) {
            s1.time_since_last_change = 0;
            s1.is_green = !s1.is_green;
        }
        s2.time_since_last_change++;
        if (s2.time_since_last_change > s2.duration) {
            s2.time_since_last_change = 0;
            s2.is_green = !s2.is_green;
        }
        
        // print simulation state
        printf("Time: %d\n", time);
        for (int i = 0; i < MAX_ROADS; i++) {
            printf("Road %d (Speed Limit: %d, Length: %d)\n", i, roads[i].speed_limit, roads[i].length);
            for (int j = 0; j < roads[i].num_vehicles; j++) {
                printf("Vehicle %d (Speed: %d, Distance: %d)\n", j, roads[i].vehicles[j].speed, roads[i].vehicles[j].distance);
            }
        }
        printf("Stoplight 1 (Duration: %d, Is Green: %d)\n", s1.duration, s1.is_green);
        printf("Stoplight 2 (Duration: %d, Is Green: %d)\n", s2.duration, s2.is_green);
        
        time++;
    }
    
    // free allocated memory
    for (int i = 0; i < MAX_ROADS; i++) {
        free(roads[i].vehicles);
    }
    
    return 0;
}