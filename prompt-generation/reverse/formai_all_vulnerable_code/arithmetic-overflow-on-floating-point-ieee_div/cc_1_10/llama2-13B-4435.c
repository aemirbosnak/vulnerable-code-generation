//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants and variables
const double PI = 3.14159;
const double EARTH_RADIUS = 6371;
const double SPEED_OF_LIGHT = 299792458;
double distance = 0;
double time = 0;
double velocity = 0;

// Function to calculate distance traveled by light
double lightDistance(double time) {
    return distance = SPEED_OF_LIGHT * time;
}

// Function to calculate time traveled by light
double lightTime(double distance) {
    return time = distance / SPEED_OF_LIGHT;
}

int main() {
    // Initialize variables
    distance = 0;
    time = 0;
    velocity = 0;

    // Calculate distance traveled by light
    distance = lightDistance(time);

    // Calculate time traveled by light
    time = lightTime(distance);

    // Print results
    printf("Distance traveled by light: %f km\n", distance);
    printf("Time traveled by light: %f s\n", time);

    // Calculate distance traveled by a spaceship
    distance = (EARTH_RADIUS * 2) * cos(PI / 180 * 180);
    velocity = (distance / time) * 1000;

    // Calculate time traveled by a spaceship
    time = distance / velocity;

    // Print results
    printf("Distance traveled by spaceship: %f km\n", distance);
    printf("Time traveled by spaceship: %f s\n", time);

    return 0;
}