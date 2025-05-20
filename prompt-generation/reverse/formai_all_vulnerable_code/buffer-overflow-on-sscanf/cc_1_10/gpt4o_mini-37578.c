//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define MAX_SPEED 10.0
#define MIN_SPEED 0.0

typedef struct {
    double x;
    double y;
    double direction; // Angle in degrees
    double speed;
} Vehicle;

void initializeVehicle(Vehicle* vehicle) {
    vehicle->x = 0.0;
    vehicle->y = 0.0;
    vehicle->direction = 0.0; // Facing right
    vehicle->speed = 0.0;
}

void displayStatus(Vehicle* vehicle) {
    printf("Vehicle Status:\n");
    printf("Position: (%.2f, %.2f)\n", vehicle->x, vehicle->y);
    printf("Direction: %.2f degrees\n", vehicle->direction);
    printf("Speed: %.2f\n", vehicle->speed);
}

void moveForward(Vehicle* vehicle, double time) {
    vehicle->x += vehicle->speed * cos(vehicle->direction * PI / 180.0) * time;
    vehicle->y += vehicle->speed * sin(vehicle->direction * PI / 180.0) * time;
}

void moveBackward(Vehicle* vehicle, double time) {
    vehicle->x -= vehicle->speed * cos(vehicle->direction * PI / 180.0) * time;
    vehicle->y -= vehicle->speed * sin(vehicle->direction * PI / 180.0) * time;
}

void turnLeft(Vehicle* vehicle, double angle) {
    vehicle->direction += angle;
    if (vehicle->direction >= 360.0) {
        vehicle->direction -= 360.0;
    }
}

void turnRight(Vehicle* vehicle, double angle) {
    vehicle->direction -= angle;
    if (vehicle->direction < 0.0) {
        vehicle->direction += 360.0;
    }
}

void changeSpeed(Vehicle* vehicle, double newSpeed) {
    if (newSpeed >= MIN_SPEED && newSpeed <= MAX_SPEED) {
        vehicle->speed = newSpeed;
    } else {
        printf("Speed must be between %.2f and %.2f.\n", MIN_SPEED, MAX_SPEED);
    }
}

int main() {
    Vehicle vehicle;
    initializeVehicle(&vehicle);
    
    char command[100];
    double timeInterval = 1.0; // in seconds

    printf("Remote Control Vehicle Simulation\n");
    printf("Commands: forward <time>, backward <time>, turn left <angle>, turn right <angle>, speed <value>, status, quit\n");
    
    while (1) {
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);

        if (sscanf(command, "forward %lf", &timeInterval) == 1) {
            moveForward(&vehicle, timeInterval);
        } else if (sscanf(command, "backward %lf", &timeInterval) == 1) {
            moveBackward(&vehicle, timeInterval);
        } else if (sscanf(command, "turn left %lf", &timeInterval) == 1) {
            turnLeft(&vehicle, timeInterval);
        } else if (sscanf(command, "turn right %lf", &timeInterval) == 1) {
            turnRight(&vehicle, timeInterval);
        } else if (sscanf(command, "speed %lf", &timeInterval) == 1) {
            changeSpeed(&vehicle, timeInterval);
        } else if (strcmp(command, "status\n") == 0) {
            displayStatus(&vehicle);
        } else if (strcmp(command, "quit\n") == 0) {
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
    
    printf("Simulation ended. Final Status:\n");
    displayStatus(&vehicle);
    return 0;
}