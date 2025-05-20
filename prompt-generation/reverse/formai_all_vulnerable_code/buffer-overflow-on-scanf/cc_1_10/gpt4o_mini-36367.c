//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_BT_CONNECTIONS 5

typedef struct {
    char name[50];
    int speed;
    int battery;
    int position_x;
    int position_y;
} RC_Vehicle;

void initialize_vehicle(RC_Vehicle *vehicle, const char *name) {
    strcpy(vehicle->name, name);
    vehicle->speed = MIN_SPEED;
    vehicle->battery = 100;
    vehicle->position_x = 0;
    vehicle->position_y = 0;
}

void display_vehicle_status(const RC_Vehicle *vehicle) {
    printf("Vehicle: %s\n", vehicle->name);
    printf("Speed: %d%%\n", vehicle->speed);
    printf("Battery: %d%%\n", vehicle->battery);
    printf("Position: (%d, %d)\n", vehicle->position_x, vehicle->position_y);
}

void change_speed(RC_Vehicle *vehicle, int speed) {
    if (speed >= MIN_SPEED && speed <= MAX_SPEED) {
        vehicle->speed = speed;
        printf("%s speed set to %d%%\n", vehicle->name, vehicle->speed);
    } else {
        printf("Speed should be between %d and %d.\n", MIN_SPEED, MAX_SPEED);
    }
}

void move_vehicle(RC_Vehicle *vehicle, int dx, int dy) {
    vehicle->position_x += dx;
    vehicle->position_y += dy;
    printf("%s moved to position (%d, %d)\n", vehicle->name, vehicle->position_x, vehicle->position_y);
}

void apply_battery_usage(RC_Vehicle *vehicle) {
    int usage = vehicle->speed / 10;

    if (vehicle->battery - usage >= 0) {
        vehicle->battery -= usage;
    } else {
        vehicle->battery = 0;
    }
    printf("%s battery now at %d%%\n", vehicle->name, vehicle->battery);
}

void remote_control(RC_Vehicle *vehicle) {
    char command[50];
    
    printf("Enter commands to control the vehicle (speed/move/status/exit):\n");
    while (1) {
        printf("Command: ");
        scanf("%s", command);

        if (strcmp(command, "speed") == 0) {
            int speed;
            printf("Enter speed (0-100): ");
            scanf("%d", &speed);
            change_speed(vehicle, speed);
        } else if (strcmp(command, "move") == 0) {
            int dx, dy;
            printf("Enter movement (dx dy): ");
            scanf("%d %d", &dx, &dy);
            move_vehicle(vehicle, dx, dy);
        } else if (strcmp(command, "status") == 0) {
            display_vehicle_status(vehicle);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting remote control.\n");
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }

        apply_battery_usage(vehicle);
        if (vehicle->battery == 0) {
            printf("Battery depleted. Please recharge the vehicle.\n");
            break;
        }
    }
}

int main() {
    RC_Vehicle myVehicle;
    initialize_vehicle(&myVehicle, "RaceCar");

    remote_control(&myVehicle);

    return 0;
}