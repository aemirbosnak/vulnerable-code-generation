//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct {
    Vector3D position;
    Vector3D velocity;
    Vector3D acceleration;
    double yaw;
    double pitch;
    double roll;
} DroneState;

DroneState drone;

void update_drone_state(double dt) {
    // Update position
    drone.position.x += drone.velocity.x * dt;
    drone.position.y += drone.velocity.y * dt;
    drone.position.z += drone.velocity.z * dt;

    // Update velocity
    drone.velocity.x += drone.acceleration.x * dt;
    drone.velocity.y += drone.acceleration.y * dt;
    drone.velocity.z += drone.acceleration.z * dt;

    // Update acceleration
    drone.acceleration.x = 0;
    drone.acceleration.y = -9.81;
    drone.acceleration.z = 0;

    // Update yaw, pitch, and roll
    drone.yaw += drone.roll * dt;
    drone.pitch += drone.pitch * dt;
    drone.roll += drone.roll * dt;
}

void send_drone_command(double throttle, double yaw, double pitch, double roll) {
    // Convert throttle to acceleration
    drone.acceleration.z = throttle * 9.81;

    // Convert yaw, pitch, and roll to angular velocities
    drone.yaw = yaw * PI / 180;
    drone.pitch = pitch * PI / 180;
    drone.roll = roll * PI / 180;
}

int main() {
    // Initialize drone state
    drone.position.x = 0;
    drone.position.y = 0;
    drone.position.z = 0;
    drone.velocity.x = 0;
    drone.velocity.y = 0;
    drone.velocity.z = 0;
    drone.acceleration.x = 0;
    drone.acceleration.y = -9.81;
    drone.acceleration.z = 0;
    drone.yaw = 0;
    drone.pitch = 0;
    drone.roll = 0;

    // Main control loop
    while (1) {
        // Read input from remote control
        double throttle;
        double yaw;
        double pitch;
        double roll;
        scanf("%lf %lf %lf %lf", &throttle, &yaw, &pitch, &roll);

        // Send command to drone
        send_drone_command(throttle, yaw, pitch, roll);

        // Update drone state
        update_drone_state(0.01);

        // Print drone state
        printf("%lf %lf %lf %lf %lf %lf %lf\n", drone.position.x, drone.position.y, drone.position.z, drone.velocity.x, drone.velocity.y, drone.velocity.z, drone.yaw);
    }

    return 0;
}