//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a 3D point
typedef struct {
    double x;
    double y;
    double z;
} Point3D;

// Function to calculate the distance between two 3D points
double distance(Point3D p1, Point3D p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Function to generate a random 3D point within a given radius
Point3D generateRandomPoint(double radius) {
    Point3D point;
    point.x = (double)rand() / RAND_MAX * 2 * radius - radius;
    point.y = (double)rand() / RAND_MAX * 2 * radius - radius;
    point.z = (double)rand() / RAND_MAX * 2 * radius - radius;
    return point;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numPoints;
    printf("Enter the number of points to generate: ");
    scanf("%d", &numPoints);

    double radius;
    printf("Enter the radius of the sphere: ");
    scanf("%lf", &radius);

    Point3D center = {0, 0, 0}; // Center of the sphere
    Point3D *points = malloc(numPoints * sizeof(Point3D)); // Allocate memory for the points

    for (int i = 0; i < numPoints; i++) {
        points[i] = generateRandomPoint(radius); // Generate a random point within the sphere
    }

    double totalDistance = 0;
    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            totalDistance += distance(points[i], points[j]); // Calculate the distance between all pairs of points
        }
    }

    printf("The total distance between all points is: %.2lf\n", totalDistance);

    free(points); // Free the memory allocated for the points
    return 0;
}