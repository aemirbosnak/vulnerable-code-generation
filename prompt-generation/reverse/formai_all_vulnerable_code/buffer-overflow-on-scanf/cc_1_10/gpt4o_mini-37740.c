//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_VEHICLES 10
#define MAX_SPEED 100
#define MIN_SPEED 0
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20

typedef struct {
    int id;
    int positionX;
    int positionY;
    int speed;
    char name[20];
} Vehicle;

void initVehicle(Vehicle *v, int id, const char *name) {
    v->id = id;
    v->positionX = rand() % SCREEN_WIDTH;
    v->positionY = rand() % SCREEN_HEIGHT;
    v->speed = 0; // Start stationary
    snprintf(v->name, sizeof(v->name), "%s", name);
}

void updatePosition(Vehicle *v) {
    v->positionX += v->speed;  // Move horizontally
    if (v->positionX >= SCREEN_WIDTH) v->positionX = SCREEN_WIDTH - 1; // bounds check
    if (v->positionX < 0) v->positionX = 0;
}

void displayVehicle(const Vehicle *v) {
    printf("Vehicle %d (%s) - Position: (%d, %d) Speed: %d\n",
           v->id, v->name, v->positionX, v->positionY, v->speed);
}

void clearScreen() {
    printf("\033[H\033[J");  // ANSI escape code to clear the screen
}

void displayAllVehicles(Vehicle vehicles[], int count) {
    clearScreen();
    for (int i = 0; i < count; i++) {
        displayVehicle(&vehicles[i]);
    }
}

void controlVehicle(Vehicle *v) {
    char command;
    printf("Control vehicle %d (%s) - (a: accelerate, d: decelerate, q: stop): ", 
           v->id, v->name);
    scanf(" %c", &command);
    switch(command) {
        case 'a':
            if (v->speed < MAX_SPEED) {
                v->speed += 10;
            }
            break;
        case 'd':
            if (v->speed > MIN_SPEED) {
                v->speed -= 10;
            }
            break;
        case 'q':
            v->speed = 0; // Stop the vehicle
            break;
        default:
            printf("Unknown command\n");
            break;
    }
}

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 5; // Number of vehicles
    char exitCommand;

    // Initialize vehicles
    for (int i = 0; i < vehicleCount; i++) {
        initVehicle(&vehicles[i], i + 1, "RCCar");
    }

    // Simulation loop
    do {
        displayAllVehicles(vehicles, vehicleCount);

        for (int i = 0; i < vehicleCount; i++) {
            controlVehicle(&vehicles[i]);
            updatePosition(&vehicles[i]);
        }

        printf("Continue simulation? (y/n): ");
        scanf(" %c", &exitCommand);

    } while (exitCommand == 'y');

    printf("Simulation ended.\n");
    return 0;
}