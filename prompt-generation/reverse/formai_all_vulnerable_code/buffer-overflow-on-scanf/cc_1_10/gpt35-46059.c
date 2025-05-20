//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

struct RCVehicle {
    int current_speed;
    bool is_engine_on;
    bool is_connected;
};

void connect_to_vehicle(struct RCVehicle *vehicle) {
    vehicle->is_connected = true;
    printf("Connected to vehicle.\n");
}

void disconnect_from_vehicle(struct RCVehicle *vehicle) {
    vehicle->is_connected = false;
    printf("Disconnected from vehicle.\n");
}

void turn_on_engine(struct RCVehicle *vehicle) {
    if (vehicle->is_connected) {
        vehicle->is_engine_on = true;
        printf("Engine is on.\n");
    } else {
        printf("Cannot turn on engine, not connected to vehicle.\n");
    }
}

void turn_off_engine(struct RCVehicle *vehicle) {
    if (vehicle->is_connected) {
        vehicle->is_engine_on = false;
        printf("Engine is off.\n");
    } else {
        printf("Cannot turn off engine, not connected to vehicle.\n");
    }
}

void increase_speed(struct RCVehicle *vehicle, int amount) {
    if (vehicle->is_connected && vehicle->is_engine_on) {
        int new_speed = vehicle->current_speed + amount;
        if (new_speed > MAX_SPEED) {
            vehicle->current_speed = MAX_SPEED;
            printf("Speed increased to maximum.\n");
        } else {
            vehicle->current_speed = new_speed;
            printf("Speed increased by %d.\n", amount);
        }
    } else {
        printf("Cannot increase speed, engine is off or not connected to vehicle.\n");
    }
}

void decrease_speed(struct RCVehicle *vehicle, int amount) {
    if (vehicle->is_connected && vehicle->is_engine_on) {
        int new_speed = vehicle->current_speed - amount;
        if (new_speed < MIN_SPEED) {
            vehicle->current_speed = MIN_SPEED;
            printf("Speed decreased to minimum.\n");
        } else {
            vehicle->current_speed = new_speed;
            printf("Speed decreased by %d.\n", amount);
        }
    } else {
        printf("Cannot decrease speed, engine is off or not connected to vehicle.\n");
    }
}

int main() {
    struct RCVehicle vehicle;
    vehicle.current_speed = 0;
    vehicle.is_engine_on = false;
    vehicle.is_connected = false;

    char input;
    while (true) {
        printf("\nPress 'c' to connect to vehicle, 'd' to disconnect.\n");
        printf("Press 'o' to turn on engine, 'f' to turn off engine.\n");
        printf("Press 'i' to increase speed, 'decrease' to decrease speed.\n");
        printf("Press 'q' to quit.\n");
        scanf(" %c", &input);

        switch (input) {
            case 'c':
                connect_to_vehicle(&vehicle);
                break;
            case 'd':
                disconnect_from_vehicle(&vehicle);
                break;
            case 'o':
                turn_on_engine(&vehicle);
                break;
            case 'f':
                turn_off_engine(&vehicle);
                break;
            case 'i':
                printf("Enter amount to increase speed by: ");
                int amount;
                scanf("%d", &amount);
                increase_speed(&vehicle, amount);
                break;
            case 'decrease':
                printf("Enter amount to decrease speed by: ");
                scanf("%d", &amount);
                decrease_speed(&vehicle, amount);
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}