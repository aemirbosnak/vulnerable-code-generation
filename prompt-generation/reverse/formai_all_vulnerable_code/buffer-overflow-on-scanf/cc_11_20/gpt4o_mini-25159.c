//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define GRID_SIZE 10
#define INITIAL_X 0
#define INITIAL_Y 0

typedef struct {
    int x;
    int y;
    char direction;
    int running;
    pthread_mutex_t lock;
} RC_Vehicle;

RC_Vehicle vehicle;

void* control_vehicle(void* arg) {
    char command[10];

    while (vehicle.running) {
        printf("Enter command (F/B/L/R/Q): ");
        scanf("%s", command);

        pthread_mutex_lock(&vehicle.lock);
        if (strcmp(command, "F") == 0) {
            if (vehicle.direction == 'N' && vehicle.x > 0) vehicle.x--;
            else if (vehicle.direction == 'S' && vehicle.x < GRID_SIZE - 1) vehicle.x++;
            else if (vehicle.direction == 'E' && vehicle.y < GRID_SIZE - 1) vehicle.y++;
            else if (vehicle.direction == 'W' && vehicle.y > 0) vehicle.y--;
        } else if (strcmp(command, "B") == 0) {
            if (vehicle.direction == 'N' && vehicle.x < GRID_SIZE - 1) vehicle.x++;
            else if (vehicle.direction == 'S' && vehicle.x > 0) vehicle.x--;
            else if (vehicle.direction == 'E' && vehicle.y > 0) vehicle.y--;
            else if (vehicle.direction == 'W' && vehicle.y < GRID_SIZE - 1) vehicle.y++;
        } else if (strcmp(command, "L") == 0) {
            if (vehicle.direction == 'N') vehicle.direction = 'W';
            else if (vehicle.direction == 'E') vehicle.direction = 'N';
            else if (vehicle.direction == 'S') vehicle.direction = 'E';
            else if (vehicle.direction == 'W') vehicle.direction = 'S';
        } else if (strcmp(command, "R") == 0) {
            if (vehicle.direction == 'N') vehicle.direction = 'E';
            else if (vehicle.direction == 'E') vehicle.direction = 'S';
            else if (vehicle.direction == 'S') vehicle.direction = 'W';
            else if (vehicle.direction == 'W') vehicle.direction = 'N';
        } else if (strcmp(command, "Q") == 0) {
            vehicle.running = 0;
            pthread_mutex_unlock(&vehicle.lock);
            break;
        } else {
            printf("Invalid command!\n");
        }
        pthread_mutex_unlock(&vehicle.lock);

        // Display current position and direction
        pthread_mutex_lock(&vehicle.lock);
        printf("Vehicle Position: (%d, %d) Direction: %c\n", vehicle.x, vehicle.y, vehicle.direction);
        pthread_mutex_unlock(&vehicle.lock);
    }
    return NULL;
}

void* simulate_vehicle(void* arg) {
    while (vehicle.running) {
        // Simulate vehicle logic or movement
        sleep(1); // Simulate some processing delay
    }
    return NULL;
}

int main() {
    pthread_t control_thread;
    pthread_t simulation_thread;

    // Initialize vehicle
    vehicle.x = INITIAL_X;
    vehicle.y = INITIAL_Y;
    vehicle.direction = 'N';
    vehicle.running = 1;
    pthread_mutex_init(&vehicle.lock, NULL);

    // Create threads for control and simulation
    pthread_create(&control_thread, NULL, control_vehicle, NULL);
    pthread_create(&simulation_thread, NULL, simulate_vehicle, NULL);

    // Run until vehicle is no longer running
    pthread_join(control_thread, NULL);
    pthread_join(simulation_thread, NULL);

    pthread_mutex_destroy(&vehicle.lock);

    printf("Simulation ended. Vehicle final position: (%d, %d) Direction: %c\n", vehicle.x, vehicle.y, vehicle.direction);
    return 0;
}