//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_VEHICLES 100
#define NAME_LENGTH 30
#define SIMULATION_TIME 30

typedef struct {
    char name[NAME_LENGTH];
    int position;
    int speed;
} Vehicle;

void initialize_vehicle(Vehicle *v, const char *name, int speed) {
    strncpy(v->name, name, NAME_LENGTH);
    v->position = 0;
    v->speed = speed;
}

void update_position(Vehicle *v) {
    v->position += v->speed;
}

void display_status(Vehicle *v) {
    printf("Vehicle: %s, Position: %d, Speed: %d\n", v->name, v->position, v->speed);
}

void simulate_vehicles(Vehicle vehicles[], int count) {
    for (int t = 0; t < SIMULATION_TIME; t++) {
        printf("Time: %d seconds\n", t);
        for (int i = 0; i < count; i++) {
            update_position(&vehicles[i]);
            display_status(&vehicles[i]);
        }
        printf("\n");
        // Sleep for 1 second to simulate time passing
        sleep(1);
    }
}

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    int vehicle_count = 0;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Enter the number of vehicles (Max %d): ", MAX_VEHICLES);
    scanf("%d", &vehicle_count);
    
    if(vehicle_count <= 0 || vehicle_count > MAX_VEHICLES) {
        printf("Invalid number of vehicles. Exiting simulation.\n");
        return 1;
    }
    
    // Read details for each vehicle
    for (int i = 0; i < vehicle_count; i++) {
        char name[NAME_LENGTH];
        int speed;

        printf("Enter name for vehicle %d: ", i + 1);
        scanf("%s", name);
        
        printf("Enter speed for vehicle %d (1-10): ", i + 1);
        scanf("%d", &speed);
        
        if (speed < 1 || speed > 10) {
            printf("Invalid speed. Setting speed to 1.\n");
            speed = 1;
        }
        
        initialize_vehicle(&vehicles[i], name, speed);
    }

    // Start the simulation
    printf("\nStarting Simulation...\n");
    simulate_vehicles(vehicles, vehicle_count);

    printf("Simulation Ended. Thank you for playing!\n");
    return 0;
}