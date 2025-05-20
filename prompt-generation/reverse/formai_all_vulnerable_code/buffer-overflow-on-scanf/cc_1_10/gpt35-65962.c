//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_DISTANCE 1000
#define MAX_SPEED 80

int main() {
    printf("GPS Navigation Simulation\n");

    // Initialize random number generator
    srand(time(NULL));

    // Generate random distance
    int distance = rand() % MAX_DISTANCE + 1;
    printf("Distance to your destination: %d km\n", distance);
    
    // Get user's starting point
    int starting_point;
    printf("Enter your starting point (km from destination): ");
    scanf("%d", &starting_point);

    // Calculate remaining distance to destination
    int remaining_distance = distance - starting_point;
    printf("You have %d km to travel\n", remaining_distance);

    // Generate random speed
    int speed = rand() % MAX_SPEED + 1;
    printf("Current speed: %d km/h\n", speed);

    // Calculate estimated time of arrival
    double estimated_time = (double)remaining_distance / (double)speed;
    printf("Estimated time of arrival: %.2f hours\n", estimated_time);

    // Check if user will arrive on time (within 10% margin)
    double margin = estimated_time * 0.1;
    if (estimated_time <= 2.0) {
        margin = 0.2;
    }
    double min_time = estimated_time - margin;
    double max_time = estimated_time + margin;
    printf("You should arrive between %.2f and %.2f hours\n", min_time, max_time);

    // Check if user is speeding
    if (speed > 90) {
        printf("You are exceeding the speed limit\n");
    }

    return 0;
}