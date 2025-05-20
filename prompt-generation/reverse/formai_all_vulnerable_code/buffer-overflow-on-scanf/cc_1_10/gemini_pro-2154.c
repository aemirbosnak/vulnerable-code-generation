//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Vehicle structure
typedef struct {
    double x;       // X-coordinate
    double y;       // Y-coordinate
    double theta;   // Angle of orientation
    double v;       // Velocity
} Vehicle;

// Remote control structure
typedef struct {
    int throttle;   // Throttle value (-100 to 100)
    int steering;  // Steering angle (-100 to 100)
} RemoteControl;

// Create a new vehicle
Vehicle* create_vehicle(double x, double y, double theta, double v) {
    Vehicle* vehicle = malloc(sizeof(Vehicle));
    vehicle->x = x;
    vehicle->y = y;
    vehicle->theta = theta;
    vehicle->v = v;
    return vehicle;
}

// Update the vehicle's position
void update_vehicle(Vehicle* vehicle, RemoteControl* remote, double dt) {
    // Convert throttle and steering to linear and angular velocities
    double v_lin = vehicle->v + remote->throttle * dt;
    double v_ang = remote->steering * dt;
    
    // Update the vehicle's position and orientation
    vehicle->x += v_lin * cos(vehicle->theta) * dt;
    vehicle->y += v_lin * sin(vehicle->theta) * dt;
    vehicle->theta += v_ang * dt;
    
    // Limit the vehicle's velocity
    if (v_lin > 100) {
        v_lin = 100;
    } else if (v_lin < -100) {
        v_lin = -100;
    }
    vehicle->v = v_lin;
}

// Draw the vehicle to the console
void draw_vehicle(Vehicle* vehicle) {
    // Calculate the vehicle's bounding box
    double x_min = vehicle->x - 2;
    double x_max = vehicle->x + 2;
    double y_min = vehicle->y - 2;
    double y_max = vehicle->y + 2;
    
    // Draw the vehicle's bounding box
    printf("Vehicle: [%.2f, %.2f, %.2f, %.2f]\n", x_min, x_max, y_min, y_max);
}

// Main function
int main() {
    // Create a new vehicle
    Vehicle* vehicle = create_vehicle(0, 0, 0, 0);
    
    // Create a new remote control
    RemoteControl* remote = malloc(sizeof(RemoteControl));
    remote->throttle = 0;
    remote->steering = 0;
    
    // Main loop
    int running = 1;
    while (running) {
        // Get user input
        printf("Enter throttle value (-100 to 100): ");
        scanf("%d", &remote->throttle);
        printf("Enter steering angle (-100 to 100): ");
        scanf("%d", &remote->steering);
        
        // Update the vehicle's position
        update_vehicle(vehicle, remote, 0.1);
        
        // Draw the vehicle to the console
        draw_vehicle(vehicle);
    }
    
    // Free the vehicle and remote control
    free(vehicle);
    free(remote);
    
    return 0;
}