//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLES 5

typedef struct {
    char name[20];
    float length;
    float width;
    float speed;
    void (*move)(struct vehicle*, int);
} vehicle_t;

struct vehicle {
    vehicle_t* vehicle_config;
};

void vehicle_move_forward(vehicle_t* config, int power) {
    config->speed += power * config->speed;
}

void vehicle_move_backward(vehicle_t* config, int power) {
    config->speed -= power * config->speed;
}

void vehicle_move_left(vehicle_t* config, int power) {
    // Implement turning left functionality
}

void vehicle_move_right(vehicle_t* config, int power) {
    // Implement turning right functionality
}

void create_vehicle(vehicle_t vehicles[], const char* name, float length, float width, float speed, void (*move_fn)(vehicle_t*, int)) {
    vehicle_t new_vehicle = {0};
    strcpy(new_vehicle.name, name);
    new_vehicle.length = length;
    new_vehicle.width = width;
    new_vehicle.speed = speed;
    new_vehicle.move = move_fn;

    vehicles[0] = new_vehicle;
}

int main() {
    vehicle_t vehicles[MAX_VEHICLES] = {0};

    create_vehicle(vehicles, "Car", 5.0f, 2.0f, 15.0f, vehicle_move_forward);
    create_vehicle(vehicles, "Truck", 10.0f, 4.0f, 20.0f, vehicle_move_forward);

    struct vehicle remote_control = {0};
    remote_control.vehicle_config = &vehicles[0];

    while (1) {
        int power = 0;
        printf("Enter power level (0-100): ");
        scanf("%d", &power);

        remote_control.vehicle_config->move(remote_control.vehicle_config, power);
    }

    return 0;
}