//MISTRAL-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_ASTEROIDS 100
#define FIELD_RADIUS 50
#define MIN_DISTANCE 10.0
#define MAX_DISTANCE 50.0

typedef struct {
    double x, y, z;
} Vector3;

Vector3 randomVector() {
    Vector3 v;
    v.x = (double) rand() / RAND_MAX * 2.0 - 1.0;
    v.y = (double) rand() / RAND_MAX * 2.0 - 1.0;
    v.z = (double) rand() / RAND_MAX * 2.0 - 1.0;
    return v;
}

double distance(Vector3 a, Vector3 b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void generateAsteroidField(Vector3 *asteroids) {
    srand(time(NULL));
    for (int i = 0; i < NUM_ASTEROIDS; i++) {
        Vector3 asteroid;
        asteroid.x = FIELD_RADIUS + randomVector().x * MAX_DISTANCE;
        asteroid.y = FIELD_RADIUS + randomVector().y * MAX_DISTANCE;
        asteroid.z = FIELD_RADIUS + randomVector().z * MAX_DISTANCE;
        double minDistance = MIN_DISTANCE;
        for (int j = 0; j < i; j++) {
            double d = distance(asteroids[i], asteroids[j]);
            if (d < minDistance) {
                minDistance = d;
                asteroid.x += (asteroids[j].x - asteroid.x) * 0.1;
                asteroid.y += (asteroids[j].y - asteroid.y) * 0.1;
                asteroid.z += (asteroids[j].z - asteroid.z) * 0.1;
            }
        }
        asteroids[i] = asteroid;
    }
}

int main() {
    Vector3 asteroids[NUM_ASTEROIDS];
    generateAsteroidField(asteroids);
    for (int i = 0; i < NUM_ASTEROIDS; i++) {
        printf("Asteroid %d: (%f, %f, %f)\n", i, asteroids[i].x, asteroids[i].y, asteroids[i].z);
    }
    return 0;
}