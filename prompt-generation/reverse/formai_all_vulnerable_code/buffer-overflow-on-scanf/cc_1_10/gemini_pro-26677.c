//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Car struct
typedef struct {
    int speed;
    int direction;
} Car;

// Remote control struct
typedef struct {
    int throttle;
    int steering;
} RemoteControl;

// Create a new car
Car *new_car(int speed, int direction) {
    Car *car = malloc(sizeof(Car));
    car->speed = speed;
    car->direction = direction;
    return car;
}

// Create a new remote control
RemoteControl *new_remote_control(int throttle, int steering) {
    RemoteControl *remote_control = malloc(sizeof(RemoteControl));
    remote_control->throttle = throttle;
    remote_control->steering = steering;
    return remote_control;
}

// Update the car's speed and direction based on the remote control
void update_car(Car *car, RemoteControl *remote_control) {
    car->speed += remote_control->throttle;
    car->direction += remote_control->steering;
}

// Print the car's current speed and direction
void print_car(Car *car) {
    printf("Speed: %d\n", car->speed);
    printf("Direction: %d\n", car->direction);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new car and remote control
    Car *car = new_car(0, 0);
    RemoteControl *remote_control = new_remote_control(0, 0);

    // Get the user's input
    while (1) {
        printf("Enter throttle (-100 to 100): ");
        scanf("%d", &remote_control->throttle);
        printf("Enter steering (-100 to 100): ");
        scanf("%d", &remote_control->steering);

        // Update the car's speed and direction
        update_car(car, remote_control);

        // Print the car's current speed and direction
        print_car(car);
    }

    // Free the car and remote control
    free(car);
    free(remote_control);

    return 0;
}