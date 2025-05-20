//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
// Neon City's skyline, a tapestry of chrome and neon, pierces the heavens. Amidst the skyscrapers, a lone figure emerges from the shadows, a hacker known as Byte.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The city is a sea of data, and Byte's algorithm will navigate its currents.
typedef struct {
    float x;
    float y;
} Point;

// The city's inhabitants, as diverse as the pixels on a display, are represented by points.
Point points[100];

// Byte's algorithm, a neural net trained on the city's data, will find patterns in the chaos.
float distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// A cluster, a gathering of similar points, is a beacon in the city's data landscape.
typedef struct {
    Point center;
    float radius;
    int count;
} Cluster;

Cluster clusters[10];

// Byte's algorithm iteratively refines its clusters, drawing boundaries around the city's data.
void cluster() {
    for (int i = 0; i < 100; i++) {
        // Each point seeks its closest cluster, drawn by its neon glow.
        float minDistance = INFINITY;
        int minCluster = -1;
        for (int j = 0; j < 10; j++) {
            float dist = distance(points[i], clusters[j].center);
            if (dist < minDistance) {
                minDistance = dist;
                minCluster = j;
            }
        }

        // The point joins its chosen cluster, strengthening its identity.
        clusters[minCluster].count++;
        clusters[minCluster].center.x = (clusters[minCluster].center.x * clusters[minCluster].count + points[i].x) / (clusters[minCluster].count + 1);
        clusters[minCluster].center.y = (clusters[minCluster].center.y * clusters[minCluster].count + points[i].y) / (clusters[minCluster].count + 1);
    }

    // The clusters grow and evolve, their boundaries shifting with the data's flow.
    for (int i = 0; i < 10; i++) {
        clusters[i].radius = 0;
        for (int j = 0; j < 100; j++) {
            float dist = distance(points[j], clusters[i].center);
            if (dist > clusters[i].radius) {
                clusters[i].radius = dist;
            }
        }
    }
}

// Byte's algorithm, complete, reveals the city's hidden order, its clusters like islands in a sea of data.
int main() {
    // Byte's algorithm scans the city's data, its synthetic eyes absorbing the digital landscape.
    for (int i = 0; i < 100; i++) {
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    // Byte's algorithm, a symphony of code, analyzes the city's data, its rhythm echoing through the night.
    cluster();

    // Byte's algorithm, its task complete, displays the city's hidden order, its clusters like stars in a vast expanse.
    for (int i = 0; i < 10; i++) {
        printf("Cluster %d: center=(%f, %f), radius=%f\n", i, clusters[i].center.x, clusters[i].center.y, clusters[i].radius);
    }

    return 0;
}