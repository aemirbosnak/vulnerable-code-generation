//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_VEHICLES 5
#define GRID_SIZE 10

typedef struct {
    int id;
    char name[20];
    int x; // x position on grid
    int y; // y position on grid
} Vehicle;

void initialize_vehicles(Vehicle vehicles[], int count) {
    for (int i = 0; i < count; i++) {
        vehicles[i].id = i + 1;
        snprintf(vehicles[i].name, sizeof(vehicles[i].name), "Vehicle_%d", vehicles[i].id);
        vehicles[i].x = rand() % GRID_SIZE;
        vehicles[i].y = rand() % GRID_SIZE;
    }
}

void display_grid(Vehicle vehicles[], int count) {
    printf("\nCurrent Positions of Vehicles:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int found = 0;
            for (int k = 0; k < count; k++) {
                if (vehicles[k].x == j && vehicles[k].y == i) {
                    printf("[%s]", vehicles[k].name);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("[   ]");
            }
        }
        printf("\n");
    }
}

void move_vehicle(Vehicle *vehicle, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (vehicle->y > 0) vehicle->y--;
            break;
        case 's': // Move down
            if (vehicle->y < GRID_SIZE - 1) vehicle->y++;
            break;
        case 'a': // Move left
            if (vehicle->x > 0) vehicle->x--;
            break;
        case 'd': // Move right
            if (vehicle->x < GRID_SIZE - 1) vehicle->x++;
            break;
        default:
            printf("Invalid direction! Use 'w', 'a', 's', 'd'.\n");
            break;
    }
}

void control_vehicle(Vehicle vehicles[], int count) {
    int vehicle_id;
    char direction;

    printf("Select vehicle by ID (1 - %d): ", count);
    scanf("%d", &vehicle_id);
    if (vehicle_id < 1 || vehicle_id > count) {
        printf("Invalid vehicle ID!\n");
        return;
    }

    printf("Enter direction to move (w: up, s: down, a: left, d: right): ");
    scanf(" %c", &direction);

    move_vehicle(&vehicles[vehicle_id - 1], direction);
}

void run_simulation(int vehicle_count) {
    Vehicle vehicles[MAX_VEHICLES];
    initialize_vehicles(vehicles, vehicle_count);

    while (1) {
        display_grid(vehicles, vehicle_count);
        control_vehicle(vehicles, vehicle_count);
        sleep(1); // Sleep for a short time to allow user to see grid updates
    }
}

int main() {
    srand(time(NULL));
    
    int vehicle_count;
    printf("Enter number of vehicles (1 - %d): ", MAX_VEHICLES);
    scanf("%d", &vehicle_count);
    
    if (vehicle_count < 1 || vehicle_count > MAX_VEHICLES) {
        printf("Invalid number of vehicles!\n");
        return -1;
    }

    run_simulation(vehicle_count);
    
    return 0;
}