//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEIGHT 100
#define MAX_DISTANCE 500

typedef struct {
    int x;
    int y;
    int z;
} Vector3D;

Vector3D position;
Vector3D direction;
float altitude;
float distance;

int main() {
    int i;
    int x, y, z;
    float height, distance;

    // Initialize position and direction vectors
    position.x = 0;
    position.y = 0;
    position.z = 0;
    direction.x = 0;
    direction.y = 0;
    direction.z = 1;

    // Get user input for height and distance
    printf("Enter altitude (in meters): ");
    scanf("%f", &height);
    printf("Enter distance (in meters): ");
    scanf("%f", &distance);

    // Check if altitude and distance are valid
    if (height < 0 || height > MAX_HEIGHT) {
        printf("Invalid altitude. Must be between 0 and %d meters.\n", MAX_HEIGHT);
        return 1;
    }
    if (distance < 0 || distance > MAX_DISTANCE) {
        printf("Invalid distance. Must be between 0 and %d meters.\n", MAX_DISTANCE);
        return 1;
    }

    // Move the drone to the specified altitude and distance
    altitude = height;
    distance = distance;
    while (distance > 0) {
        printf("Moving drone up %d meters...\n", altitude);
        if (position.z == altitude) {
            break;
        }
        position.z += altitude;
        distance -= altitude;
    }
    while (distance > 0) {
        printf("Moving drone forward %d meters...\n", distance);
        if (position.z == 0) {
            break;
        }
        position.x += distance * direction.x;
        position.y += distance * direction.y;
        position.z += distance * direction.z;
        distance -= distance;
    }

    // Print final position
    printf("Final position: (%d, %d, %d)\n", position.x, position.y, position.z);

    return 0;
}