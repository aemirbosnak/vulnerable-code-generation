//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_CARS 10
#define INTERSECTION_WIDTH 5
#define NUM_LANES 2
#define GREEN_LIGHT_DURATION 5
#define RED_LIGHT_DURATION 3

typedef struct {
    int id;
    char direction; // 'N', 'S', 'E', 'W'
} Car;

typedef struct {
    char signal; // 'G' for green, 'R' for red
    int exit_time; // time when the green signal will change
} TrafficLight;

TrafficLight traffic_light;
Car cars[MAX_CARS];
pthread_mutex_t light_mutex = PTHREAD_MUTEX_INITIALIZER;

void *car_movement(void *arg) {
    Car *car = (Car *)arg;
    int travel_time = rand() % 3 + 1; // Random travel time between 1 and 3 seconds

    printf("Car %d [%c] is waiting to enter the intersection.\n", car->id, car->direction);
    sleep(travel_time);

    pthread_mutex_lock(&light_mutex);
    if (traffic_light.signal == 'G') {
        printf("Car %d [%c] is passing through the intersection.\n", car->id, car->direction);
        sleep(1); // Simulate time taken to pass the intersection
    } else {
        printf("Car %d [%c] is waiting at a red light.\n", car->id, car->direction);
    }
    pthread_mutex_unlock(&light_mutex);
    
    return NULL;
}

void *traffic_light_control(void *arg) {
    while (1) {
        pthread_mutex_lock(&light_mutex);
        traffic_light.signal = 'G'; // Green light
        printf("Traffic light is GREEN for %d seconds.\n", GREEN_LIGHT_DURATION);
        traffic_light.exit_time = time(NULL) + GREEN_LIGHT_DURATION;
        pthread_mutex_unlock(&light_mutex);
        sleep(GREEN_LIGHT_DURATION);

        pthread_mutex_lock(&light_mutex);
        traffic_light.signal = 'R'; // Red light
        printf("Traffic light is RED for %d seconds.\n", RED_LIGHT_DURATION);
        traffic_light.exit_time = time(NULL) + RED_LIGHT_DURATION;
        pthread_mutex_unlock(&light_mutex);
        sleep(RED_LIGHT_DURATION);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    pthread_t traffic_light_thread;
    pthread_t car_threads[MAX_CARS];

    // Initialize traffic light state
    traffic_light.signal = 'G'; // Start with green light

    // Start the traffic light control thread
    pthread_create(&traffic_light_thread, NULL, traffic_light_control, NULL);
    
    // Create and start car threads
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = (Car){i, (i % 4 == 0) ? 'N' : (i % 4 == 1) ? 'E' : (i % 4 == 2) ? 'S' : 'W'};
        pthread_create(&car_threads[i], NULL, car_movement, (void *)&cars[i]);
    }

    // Wait for all car threads to finish
    for (int i = 0; i < MAX_CARS; i++) {
        pthread_join(car_threads[i], NULL);
    }
    
    // Join the traffic light thread (this will run indefinitely in this example)
    // pthread_join(traffic_light_thread, NULL); // Uncomment if needed

    return 0;
}