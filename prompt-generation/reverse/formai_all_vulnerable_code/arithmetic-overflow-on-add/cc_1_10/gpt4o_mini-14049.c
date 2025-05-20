//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define MAX_VEHICLES 5
#define ROAD_LENGTH 30
#define SIMULATION_TIME 30
#define VEHICLE_SPEED 1

typedef struct {
    char type; // 'C' for car, 'B' for bus
    int position;
    pthread_t thread_id;
} Vehicle;

pthread_mutex_t road_mutex;
Vehicle vehicles[MAX_VEHICLES];
bool running = true;

void *move_vehicle(void *arg) {
    Vehicle *vehicle = (Vehicle *)arg;
    while (running && vehicle->position < ROAD_LENGTH) {
        pthread_mutex_lock(&road_mutex);
        
        // Move vehicle
        if (vehicle->position < ROAD_LENGTH) {
            printf("%c is at position %d\n", vehicle->type, vehicle->position);
            vehicle->position += VEHICLE_SPEED;
        }
        
        pthread_mutex_unlock(&road_mutex);
        usleep(500000); // Sleep for 0.5 seconds
    }
    return NULL;
}

void initialize_vehicles() {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        vehicles[i].type = (i % 2 == 0) ? 'C' : 'B'; // Alternate between Car and Bus
        vehicles[i].position = 0;
        pthread_create(&vehicles[i].thread_id, NULL, move_vehicle, (void *)&vehicles[i]);
    }
}

void simulate_traffic() {
    time_t end_time = time(NULL) + SIMULATION_TIME;
    while (time(NULL) < end_time) {
        pthread_mutex_lock(&road_mutex);
        // Display current status of vehicles
        for (int i = 0; i < MAX_VEHICLES; i++) {
            if (vehicles[i].position < ROAD_LENGTH) {
                printf("%c is currently at position %d\n", vehicles[i].type, vehicles[i].position);
            }
        }
        pthread_mutex_unlock(&road_mutex);
        usleep(1000000); // Sleep for 1 second to update status
    }
    running = false;
}

void cleanup() {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        pthread_join(vehicles[i].thread_id, NULL);
    }
}

int main() {
    pthread_mutex_init(&road_mutex, NULL);
    initialize_vehicles();
    
    printf("Starting traffic simulation...\n");
    simulate_traffic();
    
    printf("Traffic simulation ended. Cleaning up...\n");
    cleanup();
    
    pthread_mutex_destroy(&road_mutex);
    
    return 0;
}