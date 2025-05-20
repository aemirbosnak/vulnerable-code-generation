//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100.0 // maximum speed of the vehicle
#define MIN_SPEED 0.0   // minimum speed of the vehicle
#define STEERING_ANGLE 30.0 // maximum steering angle of the vehicle

struct Vehicle {
    float speed; // current speed of the vehicle
    float steering_angle; // current steering angle of the vehicle
};

void display_status(struct Vehicle* vehicle) {
    printf("Current Speed: %.2f\n", vehicle->speed);
    printf("Current Steering Angle: %.2f\n", vehicle->steering_angle);
}

void set_speed(struct Vehicle* vehicle, float speed) {
    if (speed > MAX_SPEED) {
        printf("Error: Speed cannot be above %.2f\n", MAX_SPEED);
    }
    else if (speed < MIN_SPEED) {
        printf("Error: Speed cannot be below %.2f\n", MIN_SPEED);
    }
    else {
        vehicle->speed = speed;
        display_status(vehicle);
    }
}

void set_steering_angle(struct Vehicle* vehicle, float steering_angle) {
    if (steering_angle > STEERING_ANGLE) {
        printf("Error: Steering angle cannot be above %.2f\n", STEERING_ANGLE);
    }
    else if (steering_angle < -STEERING_ANGLE) {
        printf("Error: Steering angle cannot be below %.2f\n", -STEERING_ANGLE);
    }
    else {
        vehicle->steering_angle = steering_angle;
        display_status(vehicle);
    }
}

void simulate_remote_control_vehicle(struct Vehicle* vehicle) {
    printf("Starting Remote Control Vehicle Simulation...\n");
    printf("Enter 's' to set speed, 'a' to set steering angle, or 'q' to quit:\n");
    char input;
    while (1) {
        scanf(" %c", &input);
        if (input == 'q') {
            printf("Exiting Remote Control Vehicle Simulation...\n");
            break;
        }
        else if (input == 's') {
            float speed;
            printf("Enter speed (0.00-%.2f): ", MAX_SPEED);
            scanf("%f", &speed);
            set_speed(vehicle, speed);
        }
        else if (input == 'a') {
            float steering_angle;
            printf("Enter steering angle (-%.2f-%.2f): ", STEERING_ANGLE, STEERING_ANGLE);
            scanf("%f", &steering_angle);
            set_steering_angle(vehicle, steering_angle);
        }
        else {
            printf("Invalid input, please try again.\n");
        }
    }
}

int main() {
    struct Vehicle vehicle = {0.0, 0.0};
    simulate_remote_control_vehicle(&vehicle);
    return 0;
}