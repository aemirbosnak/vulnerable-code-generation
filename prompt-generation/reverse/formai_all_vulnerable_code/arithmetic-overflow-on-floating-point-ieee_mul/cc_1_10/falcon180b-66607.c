//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the GPS coordinates of the current location
double current_latitude = 37.774929;
double current_longitude = -122.419416;

// Define the destination GPS coordinates
double destination_latitude = 40.712776;
double destination_longitude = -74.005974;

// Define the distance between the current location and the destination
double distance;

// Define the speed of the current location
double speed;

// Define the direction of the current location
double direction;

// Define the time interval for updating the GPS data
double time_interval = 0.1;

// Define the step size for updating the GPS data
double step_size = 0.01;

// Define the maximum speed
double max_speed = 100.0;

int main() {

    // Initialize the GPS data
    current_latitude = current_latitude;
    current_longitude = current_longitude;

    destination_latitude = destination_latitude;
    destination_longitude = destination_longitude;

    distance = 0.0;

    speed = 0.0;

    direction = 0.0;

    while (1) {

        // Calculate the distance between the current location and the destination
        distance = sqrt(pow(current_latitude - destination_latitude, 2) + pow(current_longitude - destination_longitude, 2));

        // Calculate the speed of the current location
        speed = distance / (distance + 1);

        // Calculate the direction of the current location
        direction = atan2(destination_latitude - current_latitude, destination_longitude - current_longitude);

        // Limit the speed to the maximum speed
        if (speed > max_speed) {
            speed = max_speed;
        }

        // Update the current location based on the speed and direction
        current_latitude += speed * cos(direction) * step_size;
        current_longitude += speed * sin(direction) * step_size;

        // Print the GPS data
        printf("Current location: %.6f, %.6f\n", current_latitude, current_longitude);
        printf("Destination location: %.6f, %.6f\n", destination_latitude, destination_longitude);
        printf("Distance: %.6f\n", distance);
        printf("Speed: %.6f\n", speed);
        printf("Direction: %.6f\n", direction);

        // Wait for the time interval before updating the GPS data again
        usleep(time_interval * 1000000);
    }

    return 0;
}