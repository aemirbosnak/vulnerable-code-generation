//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ALTITUDE 1
#define MAX_ALTITUDE 100
#define MIN_SPEED 10
#define MAX_SPEED 50
#define MIN_BATTERY 10
#define MAX_BATTERY 100
#define MIN_DISTANCE 10
#define MAX_DISTANCE 1000

int main() {

    srand(time(NULL));

    printf("Welcome to your new C Drone Remote Control program!\n\n");

    int altitude = MIN_ALTITUDE + rand() % (MAX_ALTITUDE - MIN_ALTITUDE + 1);
    int speed = MIN_SPEED + rand() % (MAX_SPEED - MIN_SPEED + 1);
    int battery = MIN_BATTERY + rand() % (MAX_BATTERY - MIN_BATTERY + 1);
    int distance = MIN_DISTANCE + rand() % (MAX_DISTANCE - MIN_DISTANCE + 1);

    printf("Your drone is currently at an altitude of %dm, flying at a speed of %dkm/h.\n\n", 
           altitude, speed);

    printf("The battery is currently at %d%% capacity, and the drone can fly up to %dkm on a single charge.\n\n", 
           battery, distance);

    printf("Please enter the desired altitude (in meters): ");

    int desired_altitude;
    scanf("%d", &desired_altitude);

    if (desired_altitude < MIN_ALTITUDE || desired_altitude > MAX_ALTITUDE) {
        printf("Error: The desired altitude must be between %d and %d meters.\n", MIN_ALTITUDE, MAX_ALTITUDE);
        return 1;
    }

    printf("\nAscending to %d meters...\n", desired_altitude);

    int i;
    for (i = altitude; i <= desired_altitude; i++) {
        printf("Current altitude: %d meters\n", i);
    }

    printf("\nReached desired altitude!\n\n");

    printf("Current battery level: %d%%\n", battery);

    int estimated_time = (desired_altitude - altitude) / speed;
    int estimated_distance = estimated_time * speed;

    if (estimated_distance > distance) {
        printf("Warning: The desired altitude is too far for the remaining battery capacity.\n");
        return 1;
    }

    printf("\nEnter the desired distance to fly (in km): ");

    int desired_distance;
    scanf("%d", &desired_distance);

    if (desired_distance < MIN_DISTANCE || desired_distance > MAX_DISTANCE) {
        printf("Error: The desired distance must be between %d and %d km.\n", MIN_DISTANCE, MAX_DISTANCE);
        return 1;
    }

    if (desired_distance > estimated_distance) {
        printf("Warning: The desired distance is too far for the remaining battery capacity.\n");
        return 1;
    }

    int remaining_distance = distance - estimated_distance;

    printf("\nFlying %d km...\n", desired_distance);

    int j;
    for (j = 1; j <= desired_distance; j++) {
        printf("Traveled distance: %d km\n", j);
    }

    printf("\nReached destination!\n\n");

    printf("Current battery level: %d%%\n", battery - (desired_distance * 2));

    return 0;
}