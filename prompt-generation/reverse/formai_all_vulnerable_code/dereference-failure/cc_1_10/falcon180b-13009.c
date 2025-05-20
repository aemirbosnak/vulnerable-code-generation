//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371 // in km
#define EARTH_CIRCUMFERENCE 40075 // in km
#define EARTH_SURFACE_AREA 510072000 // in km^2
#define MAX_ALIEN_SHIPS 1000

typedef struct {
    double x, y, z;
} Vector3D;

Vector3D randomPointOnEarth() {
    Vector3D point;
    point.x = (double)rand() / RAND_MAX * 360 - 180;
    point.y = (double)rand() / RAND_MAX * 180 - 90;
    point.z = 0;
    return point;
}

int countIntersections(Vector3D* alienShips, int numShips) {
    int count = 0;
    for (int i = 0; i < numShips; i++) {
        for (int j = i + 1; j < numShips; j++) {
            if (intersect(alienShips[i], alienShips[j])) {
                count++;
            }
        }
    }
    return count;
}

int intersect(Vector3D a, Vector3D b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    if (r <= 6371) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int numAlienShips = rand() % MAX_ALIEN_SHIPS + 1;
    Vector3D* alienShips = (Vector3D*)malloc(sizeof(Vector3D) * numAlienShips);
    for (int i = 0; i < numAlienShips; i++) {
        alienShips[i] = randomPointOnEarth();
    }

    int numIntersections = countIntersections(alienShips, numAlienShips);

    double invasionProbability = (double)numIntersections / (EARTH_SURFACE_AREA * numAlienShips);

    printf("There are %d alien ships hovering over Earth.\n", numAlienShips);
    printf("The probability of an invasion is %.2f%%\n", invasionProbability * 100);

    free(alienShips);

    return 0;
}