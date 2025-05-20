//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 1
#define MAX_TURN_RATE 100
#define MIN_TURN_RATE 1
#define TURN_INCREMENT 10

// Define the remote control vehicle
typedef struct {
    int speed;
    int turnRate;
} Vehicle;

// Initialize the remote control vehicle
void initVehicle(Vehicle* vehicle) {
    vehicle->speed = MAX_SPEED;
    vehicle->turnRate = MAX_TURN_RATE;
}

// Update the remote control vehicle based on user input
void updateVehicle(Vehicle* vehicle, int forward, int turn) {
    if (forward == 1) {
        vehicle->speed += 10;
    } else if (forward == 0) {
        vehicle->speed -= 10;
    }

    if (vehicle->speed < MIN_SPEED) {
        vehicle->speed = MIN_SPEED;
    } else if (vehicle->speed > MAX_SPEED) {
        vehicle->speed = MAX_SPEED;
    }

    if (turn == 1) {
        vehicle->turnRate += TURN_INCREMENT;
    } else if (turn == 0) {
        vehicle->turnRate -= TURN_INCREMENT;
    }

    if (vehicle->turnRate < MIN_TURN_RATE) {
        vehicle->turnRate = MIN_TURN_RATE;
    } else if (vehicle->turnRate > MAX_TURN_RATE) {
        vehicle->turnRate = MAX_TURN_RATE;
    }
}

// Simulate the remote control vehicle
void simulateVehicle(Vehicle* vehicle, int* x, int* y) {
    int dx = 0;
    int dy = 0;

    if (vehicle->speed > 0) {
        dx = 1;
    } else if (vehicle->speed < 0) {
        dx = -1;
    }

    if (vehicle->turnRate > 0) {
        dy = 1;
    } else if (vehicle->turnRate < 0) {
        dy = -1;
    }

    *x += dx;
    *y += dy;
}

int main() {
    srand(time(NULL));

    Vehicle vehicle;
    initVehicle(&vehicle);

    int x = 0;
    int y = 0;

    while (1) {
        system("clear");
        printf("Remote Control Vehicle Simulator\n");
        printf("Speed: %d\n", vehicle.speed);
        printf("Turn Rate: %d\n", vehicle.turnRate);
        printf("Position: (%d, %d)\n", x, y);

        int choice;
        printf("Enter your choice:\n");
        printf("1. Forward\n");
        printf("2. Backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            updateVehicle(&vehicle, 1, 0);
            break;
        case 2:
            updateVehicle(&vehicle, 0, 0);
            break;
        case 3:
            updateVehicle(&vehicle, 0, 1);
            break;
        case 4:
            updateVehicle(&vehicle, 0, -1);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }

        simulateVehicle(&vehicle, &x, &y);
        usleep(100000);
    }

    return 0;
}