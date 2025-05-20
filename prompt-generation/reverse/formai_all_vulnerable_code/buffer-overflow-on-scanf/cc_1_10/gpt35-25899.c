//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

// Define constants for the maximum speed, distance, and battery life of the vehicle
#define MAX_SPEED 100
#define MAX_DISTANCE 500
#define MAX_BATTERY_LIFE 50

// Define struct for vehicle configuration
typedef struct {
    int speed;
    int distance;
    int battery_life;
} VehicleConfig;

// Function to set the vehicle configuration based on user input
void set_vehicle_config(VehicleConfig *config) {
    printf("Enter vehicle speed (between 0 and 100): ");
    scanf("%d", &(config->speed));
    printf("Enter maximum distance (between 0 and 500): ");
    scanf("%d", &(config->distance));
    printf("Enter battery life (between 0 and 50): ");
    scanf("%d", &(config->battery_life));
}

// Function to simulate the vehicle movement based on user input
void simulate_vehicle_movement(VehicleConfig config) {
    int distance_travelled = 0;
    int battery_life_remaining = config.battery_life;
    bool is_vehicle_on = true;
    
    printf("\nVehicle simulation started!\n");
    printf("Initial configuration - Speed: %d, Distance: %d, Battery Life: %d\n\n", config.speed, config.distance, config.battery_life);
    
    while (is_vehicle_on) {
        char command;
        printf("Enter command (f for forward, b for backward, s for stop): ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'f':
                if (distance_travelled < config.distance && battery_life_remaining > 0) {
                    distance_travelled += config.speed;
                    battery_life_remaining--;
                    printf("Vehicle moved forward! Distance travelled: %d, Battery life remaining: %d\n\n", distance_travelled, battery_life_remaining);
                } else {
                    printf("Vehicle cannot move forward anymore! Distance travelled: %d, Battery life remaining: %d\n\n", distance_travelled, battery_life_remaining);
                }
                break;
            case 'b':
                if (distance_travelled > 0) {
                    distance_travelled -= config.speed;
                    printf("Vehicle moved backward! Distance travelled: %d\n\n", distance_travelled);
                } else {
                    printf("Vehicle cannot move backward anymore! Distance travelled: %d\n\n", distance_travelled);
                }
                break;
            case 's':
                is_vehicle_on = false;
                printf("Vehicle simulation stopped!");
                break;
            default: 
                printf("Invalid command! Enter f, b, or s.\n\n");
                break;
        }
        
        if (distance_travelled >= config.distance) {
            printf("\nVehicle has reached the maximum distance it can travel!");
            is_vehicle_on = false;
        }
        
        if (battery_life_remaining == 0) {
            printf("\nVehicle is out of battery life!");
            is_vehicle_on = false;
        }
    }
}

int main() {
    VehicleConfig vehicle_config;
    set_vehicle_config(&vehicle_config);
    simulate_vehicle_movement(vehicle_config);
    return 0;
}