//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Vehicle struct
typedef struct {
    int x;
    int y;
    int speed;
    int direction;
} Vehicle;

// Remote control struct
typedef struct {
    int throttle;
    int steering;
} RemoteControl;

// Function to initialize a vehicle
void initVehicle(Vehicle *v) {
    v->x = 0;
    v->y = 0;
    v->speed = 0;
    v->direction = 0;
}

// Function to update the vehicle's position based on the remote control input
void updateVehicle(Vehicle *v, RemoteControl *r) {
    // Update the vehicle's speed based on the throttle input
    v->speed += r->throttle;

    // Update the vehicle's direction based on the steering input
    v->direction += r->steering;

    // Update the vehicle's position based on its speed and direction
    v->x += v->speed * cos(v->direction);
    v->y += v->speed * sin(v->direction);
}

// Function to print the vehicle's current position and speed
void printVehicle(Vehicle *v) {
    printf("Vehicle position: (%d, %d)\n", v->x, v->y);
    printf("Vehicle speed: %d\n", v->speed);
}

// Main function
int main() {
    // Initialize the vehicle and remote control
    Vehicle v;
    RemoteControl r;
    initVehicle(&v);
    r.throttle = 0;
    r.steering = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Main simulation loop
    while (1) {
        // Get the user input
        printf("Enter throttle (-1 to 1): ");
        scanf("%d", &r.throttle);
        printf("Enter steering (-1 to 1): ");
        scanf("%d", &r.steering);

        // Update the vehicle's position and speed
        updateVehicle(&v, &r);

        // Print the vehicle's current position and speed
        printVehicle(&v);

        // Check if the vehicle has crashed
        if (v.x < 0 || v.x > 100 || v.y < 0 || v.y > 100) {
            printf("Vehicle has crashed!\n");
            break;
        }

        // Sleep for a short period of time to simulate real-time
        usleep(100000);
    }

    return 0;
}