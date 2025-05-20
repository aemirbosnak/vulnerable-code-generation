//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Remote control car struct
typedef struct {
    int speed;
    int direction;
    int battery;
} Car;

// Create a new remote control car
Car* create_car() {
    Car* car = malloc(sizeof(Car));
    car->speed = 0;
    car->direction = 0;
    car->battery = 100;
    return car;
}

// Destroy a remote control car
void destroy_car(Car* car) {
    free(car);
}

// Drive the remote control car
void drive_car(Car* car) {
    // Check if the car has enough battery
    if (car->battery <= 0) {
        printf("The car has no battery left!\n");
        return;
    }

    // Get the user's input
    printf("Enter a speed (1-10): ");
    scanf("%d", &car->speed);
    printf("Enter a direction (0-360): ");
    scanf("%d", &car->direction);

    // Update the car's position
    car->battery -= car->speed / 10;
    printf("The car is now driving at a speed of %d and a direction of %d.\n", car->speed, car->direction);
}

// Print the remote control car's status
void print_car_status(Car* car) {
    printf("The car's speed is %d.\n", car->speed);
    printf("The car's direction is %d.\n", car->direction);
    printf("The car's battery is %d%%\n", car->battery);
}

// Main function
int main() {
    // Create a new remote control car
    Car* car = create_car();

    // Drive the car
    while (1) {
        drive_car(car);
        print_car_status(car);
    }

    // Destroy the car
    destroy_car(car);

    return 0;
}