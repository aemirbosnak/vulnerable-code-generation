//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Car struct
typedef struct car {
    int speed;
    int direction;
} car;

// Remote control struct
typedef struct remote_control {
    int throttle;
    int steering_wheel;
} remote_control;

// Function to initialize the car
void initialize_car(car *c) {
    c->speed = 0;
    c->direction = 0;
}

// Function to initialize the remote control
void initialize_remote_control(remote_control *rc) {
    rc->throttle = 0;
    rc->steering_wheel = 0;
}

// Function to update the car's state based on the remote control input
void update_car(car *c, remote_control *rc) {
    // Update the car's speed
    c->speed += rc->throttle;
    
    // Update the car's direction
    c->direction += rc->steering_wheel;
}

// Function to print the car's state
void print_car(car *c) {
    printf("Speed: %d\n", c->speed);
    printf("Direction: %d\n", c->direction);
}

int main() {
    // Initialize the car and the remote control
    car c;
    remote_control rc;
    initialize_car(&c);
    initialize_remote_control(&rc);
    
    // Get the user input
    while (1) {
        printf("Enter the throttle value (-1 to 1): ");
        scanf("%d", &rc.throttle);
        
        printf("Enter the steering wheel value (-1 to 1): ");
        scanf("%d", &rc.steering_wheel);
        
        // Update the car's state
        update_car(&c, &rc);
        
        // Print the car's state
        print_car(&c);
    }
    
    return 0;
}