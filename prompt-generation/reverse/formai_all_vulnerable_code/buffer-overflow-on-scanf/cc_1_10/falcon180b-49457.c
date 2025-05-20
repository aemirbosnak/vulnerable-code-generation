//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

// Structure for vehicle
typedef struct {
    int speed;
    int direction;
} Vehicle;

// Function to initialize vehicle
void initVehicle(Vehicle* v) {
    v->speed = 0;
    v->direction = 0;
}

// Function to move vehicle
void moveVehicle(Vehicle* v, int speed, int direction) {
    v->speed = speed;
    v->direction = direction;
}

// Function to update vehicle position
void updateVehicle(Vehicle* v) {
    if (v->speed > 0) {
        if (v->direction == 0) {
            printf("Vehicle moving forward...\n");
        } else if (v->direction == 1) {
            printf("Vehicle turning left...\n");
        } else if (v->direction == 2) {
            printf("Vehicle turning right...\n");
        }
    } else if (v->speed < 0) {
        if (v->direction == 0) {
            printf("Vehicle moving backward...\n");
        } else if (v->direction == 1) {
            printf("Vehicle turning left...\n");
        } else if (v->direction == 2) {
            printf("Vehicle turning right...\n");
        }
    } else {
        printf("Vehicle stopped...\n");
    }
}

// Function to simulate remote control
void remoteControl(Vehicle* v) {
    int choice;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Forward\n2. Backward\n3. Left\n4. Right\n5. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveVehicle(v, MAX_SPEED, 0);
                break;
            case 2:
                moveVehicle(v, MIN_SPEED, 0);
                break;
            case 3:
                moveVehicle(v, 0, 1);
                break;
            case 4:
                moveVehicle(v, 0, 2);
                break;
            case 5:
                moveVehicle(v, 0, 0);
                break;
            default:
                printf("Invalid choice...\n");
        }

        updateVehicle(v);
        sleep(1);
    }
}

int main() {
    Vehicle v;
    initVehicle(&v);

    remoteControl(&v);

    return 0;
}