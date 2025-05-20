//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate distance between two points in a 3D space
double calculate_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    return distance;
}

// Function to calculate time dilation factor based on relative velocity and distance
double calculate_time_dilation(double velocity, double distance) {
    double time_dilation = 1 / sqrt(1 - velocity * velocity);
    return time_dilation;
}

// Function to calculate new time based on time dilation factor and original time
double calculate_new_time(double original_time, double time_dilation) {
    double new_time = original_time * time_dilation;
    return new_time;
}

// Function to calculate new coordinates based on relative velocity and original coordinates
void calculate_new_coordinates(double velocity, double x, double y, double z, double distance, double time_dilation, double* new_x, double* new_y, double* new_z) {
    *new_x = x + velocity * time_dilation * distance;
    *new_y = y + velocity * time_dilation * distance;
    *new_z = z + velocity * time_dilation * distance;
}

int main() {
    // Get input from user
    double velocity;
    double distance;
    double original_time;
    double new_time;
    double new_x, new_y, new_z;

    // Prompt user for velocity
    printf("Enter velocity: ");
    scanf("%lf", &velocity);

    // Prompt user for distance
    printf("Enter distance: ");
    scanf("%lf", &distance);

    // Prompt user for original time
    printf("Enter original time: ");
    scanf("%lf", &original_time);

    // Calculate time dilation factor
    double time_dilation = calculate_time_dilation(velocity, distance);

    // Calculate new time
    new_time = calculate_new_time(original_time, time_dilation);

    // Calculate new coordinates
    calculate_new_coordinates(velocity, 0, 0, 0, distance, time_dilation, &new_x, &new_y, &new_z);

    // Print results
    printf("New time: %.2lf\n", new_time);
    printf("New coordinates: (%.2lf, %.2lf, %.2lf)\n", new_x, new_y, new_z);

    return 0;
}