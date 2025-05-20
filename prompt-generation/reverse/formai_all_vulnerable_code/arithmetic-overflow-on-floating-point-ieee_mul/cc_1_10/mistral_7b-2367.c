//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/* Constants */
#define EARTH_RADIUS 6371.0 /* km */
#define PI M_PI
#define ALIEN_VELOCITY 25.5 /* km/s */
#define ARRIVAL_ANGLE_MIN -PI / 2
#define ARRIVAL_ANGLE_MAX PI / 2
#define NUM_ALIENS 1000000
#define NUM_TRIALS 1000000

/* Structures */
typedef struct {
    double x, y, z;
} Vector3D;

/* Functions */
Vector3D randomVector(void);
double alienImpactProbability(Vector3D alienPosition);

/* Program */
int main(void) {
    srand(time(NULL));
    int i, j, alienImpacts = 0;
    for (i = 0; i < NUM_TRIALS; i++) {
        Vector3D alienPosition = randomVector();
        if (alienImpactProbability(alienPosition) > 0.5) {
            alienImpacts++;
        }
    }
    double alienInvasionProbability = (double) alienImpacts / NUM_TRIALS;
    printf("Alien Invasion Probability: %.16f\n", alienInvasionProbability);
    return EXIT_SUCCESS;
}

/* Helper functions */
Vector3D randomVector(void) {
    Vector3D vector;
    vector.x = (double) rand() / RAND_MAX * 2.0 * PI;
    vector.y = (double) rand() / RAND_MAX * 2.0 * PI;
    vector.z = sqrt(pow(EARTH_RADIUS, 2) / (pow(ALIEN_VELOCITY, 2) * PI * PI));
    return vector;
}

double alienImpactProbability(Vector3D alienPosition) {
    Vector3D earthPosition = {0.0, 0.0, EARTH_RADIUS};
    Vector3D directionVector = {cos(alienPosition.x), cos(alienPosition.y), sin(alienPosition.x)};
    double distance = sqrt(pow(earthPosition.x - cos(alienPosition.x) * EARTH_RADIUS, 2) +
                          pow(earthPosition.y - cos(alienPosition.y) * EARTH_RADIUS, 2) +
                          pow(earthPosition.z - sin(alienPosition.x) * EARTH_RADIUS, 2));
    double probability = distance / (EARTH_RADIUS + ALIEN_VELOCITY * distance);
    return probability;
}