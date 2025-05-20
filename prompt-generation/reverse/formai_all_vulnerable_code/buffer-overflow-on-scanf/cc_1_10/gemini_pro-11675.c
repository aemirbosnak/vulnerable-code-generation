//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Constants
#define SCALE 10 // Scale of the simulation (1 unit = 10 cm)
#define MAX_SPEED 100 // Maximum speed of the vehicle (cm/s)
#define MAX_STEERING_ANGLE 30 // Maximum steering angle of the vehicle (degrees)

// Vehicle state
struct vehicle_state {
    double x; // X-coordinate of the vehicle (cm)
    double y; // Y-coordinate of the vehicle (cm)
    double theta; // Orientation of the vehicle (radians)
    double v; // Speed of the vehicle (cm/s)
    double steering_angle; // Steering angle of the vehicle (radians)
};

// Remote control commands
struct remote_control_commands {
    int forward; // Forward/backward control (1/0)
    int left; // Left/right control (1/0)
    int speed; // Speed control (0-100)
    int steering_angle; // Steering angle control (-30-30)
};

// Update the vehicle state based on the remote control commands
void update_vehicle_state(struct vehicle_state *vehicle, struct remote_control_commands *commands) {
    // Update the speed
    if (commands->forward == 1) {
        vehicle->v += commands->speed / 100.0 * MAX_SPEED;
    } else if (commands->forward == 0) {
        vehicle->v -= commands->speed / 100.0 * MAX_SPEED;
    }
    
    // Update the steering angle
    vehicle->steering_angle += commands->steering_angle / 180.0 * M_PI * MAX_STEERING_ANGLE;
    
    // Update the position
    double dx = vehicle->v * cos(vehicle->theta) * SCALE;
    double dy = vehicle->v * sin(vehicle->theta) * SCALE;
    vehicle->x += dx;
    vehicle->y += dy;
    
    // Keep the vehicle within the bounds of the simulation area
    if (vehicle->x < 0) {
        vehicle->x = 0;
    } else if (vehicle->x > 1000 * SCALE) {
        vehicle->x = 1000 * SCALE;
    }
    if (vehicle->y < 0) {
        vehicle->y = 0;
    } else if (vehicle->y > 1000 * SCALE) {
        vehicle->y = 1000 * SCALE;
    }
}

// Draw the vehicle on the screen
void draw_vehicle(struct vehicle_state *vehicle) {
    // Clear the screen
    printf("\033[2J");
    
    // Draw the vehicle
    int x = vehicle->x / SCALE;
    int y = vehicle->y / SCALE;
    printf("X");
    for (int i = 0; i < vehicle->steering_angle / (M_PI * MAX_STEERING_ANGLE) * 10; i++) {
        printf(" ");
    }
    printf("^");
    for (int i = 0; i < (1 - vehicle->steering_angle / (M_PI * MAX_STEERING_ANGLE)) * 10; i++) {
        printf(" ");
    }
    printf("X");
    
    // Draw the boundary of the simulation area
    printf("\n+");
    for (int i = 0; i < 1000; i++) {
        printf("-");
    }
    printf("+\n");
    for (int i = 0; i < 1000; i++) {
        printf("|");
        for (int j = 0; j < 1000; j++) {
            if (i == y && j == x) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 0; i < 1000; i++) {
        printf("-");
    }
    printf("+\n");
    
    // Flush the output buffer
    fflush(stdout);
}

// Main loop
int main() {
    // Initialize the vehicle state
    struct vehicle_state vehicle = {
        .x = 500 * SCALE,
        .y = 500 * SCALE,
        .theta = 0,
        .v = 0,
        .steering_angle = 0
    };
    
    // Initialize the remote control commands
    struct remote_control_commands commands = {
        .forward = 0,
        .left = 0,
        .speed = 0,
        .steering_angle = 0
    };
    
    // Main loop
    while (1) {
        // Read the remote control commands
        scanf("%d %d %d %d", &commands.forward, &commands.left, &commands.speed, &commands.steering_angle);
        
        // Update the vehicle state
        update_vehicle_state(&vehicle, &commands);
        
        // Draw the vehicle
        draw_vehicle(&vehicle);
        
        // Sleep for 100 milliseconds
        usleep(100000);
    }
    
    return 0;
}