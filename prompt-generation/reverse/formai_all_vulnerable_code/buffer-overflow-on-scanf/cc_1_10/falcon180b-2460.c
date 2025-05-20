//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define the remote control vehicle dimensions
#define WHEEL_RADIUS 0.05
#define WHEEL_DISTANCE 0.3
#define VEHICLE_WIDTH 0.2
#define VEHICLE_LENGTH 0.5

//Define the remote control vehicle speed and direction
#define SPEED_MAX 0.1
#define SPEED_MIN -0.1
#define ANGLE_MAX 45
#define ANGLE_MIN -45

//Define the remote control vehicle position and orientation
#define X_ORIGIN 0
#define Y_ORIGIN 0
#define ANGLE_ORIGIN 0

//Define the remote control vehicle position and orientation
#define X_ORIGIN 0
#define Y_ORIGIN 0
#define ANGLE_ORIGIN 0

typedef struct {
    double x;
    double y;
    double angle;
} Vehicle;

Vehicle vehicle;

void initialize() {
    vehicle.x = X_ORIGIN;
    vehicle.y = Y_ORIGIN;
    vehicle.angle = ANGLE_ORIGIN;
}

void move(double speed, double angle) {
    double delta_x = speed * cos(angle);
    double delta_y = speed * sin(angle);
    vehicle.x += delta_x;
    vehicle.y += delta_y;
    vehicle.angle += angle;
}

void turn(double angle) {
    vehicle.angle += angle;
}

void display() {
    printf("Vehicle position: (%lf, %lf), angle: %lf\n", vehicle.x, vehicle.y, vehicle.angle);
}

//Main function
int main() {
    initialize();
    int choice;
    double speed, angle;
    while(1) {
        printf("Enter your choice:\n1. Move forward\n2. Turn right\n3. Turn left\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter speed: ");
                scanf("%lf", &speed);
                move(speed, ANGLE_ORIGIN);
                display();
                break;
            case 2:
                printf("Enter angle: ");
                scanf("%lf", &angle);
                turn(angle);
                display();
                break;
            case 3:
                printf("Enter angle: ");
                scanf("%lf", &angle);
                turn(-angle);
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}