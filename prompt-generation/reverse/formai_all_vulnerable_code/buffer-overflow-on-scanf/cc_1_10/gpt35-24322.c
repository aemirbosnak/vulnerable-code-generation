//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SPEED 200
#define MAX_DISTANCE 500
#define MAX_BATTERY 50

typedef struct {
    int speed;
    int distance;
    int battery;
} RCVehicle;

void drive(RCVehicle *vehicle) {
    srand(time(0));
    int distance = rand() % (MAX_DISTANCE + 1);
    int speed = rand() % (MAX_SPEED + 1);
    int battery = rand() % (MAX_BATTERY + 1);
    printf("Driving...\n");
    printf("Distance traveled: %d meters\n", distance);
    printf("Speed reached: %d km/h\n", speed);
    vehicle->distance += distance;
    vehicle->speed = speed;
    vehicle->battery -= battery;
    printf("Battery remaining: %d%%\n", vehicle->battery);
}

void recharge(RCVehicle *vehicle) {
    printf("Recharging...\n");
    vehicle->battery = MAX_BATTERY;
    printf("Battery fully recharged!\n");
}

int main() {
    RCVehicle vehicle;
    vehicle.speed = 0;
    vehicle.distance = 0;
    vehicle.battery = MAX_BATTERY;
    printf("Welcome to the RC Vehicle Simulator!\n");
    printf("Controls: \n");
    printf("1. Drive\n");
    printf("2. Recharge\n");
    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (vehicle.battery < 10) {
                    printf("Low battery, please recharge!\n");
                    break;
                }
                drive(&vehicle);
                break;
            case 2:
                recharge(&vehicle);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(vehicle.distance < MAX_DISTANCE && vehicle.battery > 0);
    printf("Simulation over!\n");
    printf("Distance traveled: %d meters\n", vehicle.distance);
    printf("Top speed reached: %d km/h\n", vehicle.speed);
    if (vehicle.battery <= 0) {
        printf("Battery fully depleted, please recharge!\n");
    }
    return 0;
}