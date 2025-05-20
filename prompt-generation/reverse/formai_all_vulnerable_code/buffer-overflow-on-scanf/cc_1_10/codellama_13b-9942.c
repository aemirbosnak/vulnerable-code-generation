//Code Llama-13B DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LATITUDE 90
#define MIN_LATITUDE -90
#define MAX_LONGITUDE 180
#define MIN_LONGITUDE -180

int main() {
    // Define variables
    double latitude, longitude, distance;
    int choice;

    // Initialize random number generator
    srand(time(NULL));

    // Initialize GPS coordinates
    latitude = (double)rand() / RAND_MAX * (MAX_LATITUDE - MIN_LATITUDE) + MIN_LATITUDE;
    longitude = (double)rand() / RAND_MAX * (MAX_LONGITUDE - MIN_LONGITUDE) + MIN_LONGITUDE;

    // Print initial coordinates
    printf("Initial coordinates: (%.2f, %.2f)\n", latitude, longitude);

    // Get user input
    printf("Enter a choice:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Exit\n");
    scanf("%d", &choice);

    // Move forward
    if (choice == 1) {
        distance = (double)rand() / RAND_MAX * 100;
        latitude += distance;
        printf("Moved forward %.2f meters\n", distance);
        printf("New coordinates: (%.2f, %.2f)\n", latitude, longitude);
    }

    // Move backward
    else if (choice == 2) {
        distance = (double)rand() / RAND_MAX * 100;
        latitude -= distance;
        printf("Moved backward %.2f meters\n", distance);
        printf("New coordinates: (%.2f, %.2f)\n", latitude, longitude);
    }

    // Turn left
    else if (choice == 3) {
        distance = (double)rand() / RAND_MAX * 10;
        longitude -= distance;
        printf("Turned left %.2f degrees\n", distance);
        printf("New coordinates: (%.2f, %.2f)\n", latitude, longitude);
    }

    // Turn right
    else if (choice == 4) {
        distance = (double)rand() / RAND_MAX * 10;
        longitude += distance;
        printf("Turned right %.2f degrees\n", distance);
        printf("New coordinates: (%.2f, %.2f)\n", latitude, longitude);
    }

    // Exit
    else if (choice == 5) {
        printf("Exiting...\n");
        exit(0);
    }

    // Invalid input
    else {
        printf("Invalid input.\n");
    }

    return 0;
}