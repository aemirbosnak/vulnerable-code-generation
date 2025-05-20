//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN_ANGLE 90
#define MIN_TURN_ANGLE 0
#define MAX_DISTANCE 100

// Remote control vehicle structure
typedef struct {
    char name[20];
    int speed;
    int turn_angle;
    int distance;
} RemoteControlVehicle;

// Function to initialize remote control vehicle
void init_vehicle(RemoteControlVehicle *vehicle, char *name) {
    strcpy(vehicle->name, name);
    vehicle->speed = MIN_SPEED;
    vehicle->turn_angle = MIN_TURN_ANGLE;
    vehicle->distance = 0;
}

// Function to move remote control vehicle
void move_vehicle(RemoteControlVehicle *vehicle, int speed, int turn_angle) {
    vehicle->speed = speed;
    vehicle->turn_angle = turn_angle;
    printf("Vehicle %s is moving with speed %d and turn angle %d\n", vehicle->name, speed, turn_angle);
}

// Function to stop remote control vehicle
void stop_vehicle(RemoteControlVehicle *vehicle) {
    printf("Vehicle %s has stopped\n", vehicle->name);
}

// Function to get remote control vehicle status
void get_vehicle_status(RemoteControlVehicle *vehicle) {
    printf("Vehicle %s status: speed %d, turn angle %d, distance %d\n", vehicle->name, vehicle->speed, vehicle->turn_angle, vehicle->distance);
}

// Function to control remote control vehicle
void control_vehicle(RemoteControlVehicle *vehicle) {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Stop\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            move_vehicle(vehicle, vehicle->speed + 10, vehicle->turn_angle);
            break;
        case 2:
            move_vehicle(vehicle, vehicle->speed, vehicle->turn_angle - 10);
            break;
        case 3:
            move_vehicle(vehicle, vehicle->speed, vehicle->turn_angle + 10);
            break;
        case 4:
            stop_vehicle(vehicle);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

// Main function
int main() {
    RemoteControlVehicle vehicle1;
    init_vehicle(&vehicle1, "Red Car");

    while(1) {
        control_vehicle(&vehicle1);
        get_vehicle_status(&vehicle1);
    }

    return 0;
}