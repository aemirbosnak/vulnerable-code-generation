//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    int size;
    Point members[MAX_POINTS];
} Cluster;

void printPoint(Point p) {
    printf("(%lf, %lf)", p.x, p.y);
}

void printCluster(Cluster c) {
    printf("Center: ");
    printPoint(c.center);
    printf("\nMembers: [");
    for (int i = 0; i < c.size; i++) {
        printPoint(c.members[i]);
        printf(", ");
    }
    printf("]\n");
}

double euclideanDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int closestCluster(Point p, Cluster* clusters, int numClusters) {
    double minDistance = euclideanDistance(p, clusters[0].center);
    int index = 0;
    for (int i = 1; i < numClusters; i++) {
        double distance = euclideanDistance(p, clusters[i].center);
        if (distance < minDistance) {
            minDistance = distance;
            index = i;
        }
    }
    return index;
}

void updateCenters(Cluster* clusters, int numClusters) {
    for (int i = 0; i < numClusters; i++) {
        if (clusters[i].size > 0) {
            double sumX = 0, sumY = 0;
            for (int j = 0; j < clusters[i].size; j++) {
                sumX += clusters[i].members[j].x;
                sumY += clusters[i].members[j].y;
            }
            clusters[i].center.x = sumX / clusters[i].size;
            clusters[i].center.y = sumY / clusters[i].size;
        }
    }
}

void clusterPoints(Point* points, int numPoints, Cluster* clusters, int numClusters) {
    int iterations = 0;
    int changed = 1;
    int closest;
    while (changed && iterations < MAX_ITERATIONS) {
        changed = 0;
        for (int i = 0; i < numPoints; i++) {
            closest = closestCluster(points[i], clusters, numClusters);
            if (&clusters[closest].members[clusters[closest].size] != &points[i]) {
                clusters[closest].members[clusters[closest].size++] = points[i];
                changed = 1;
            }
        }
        updateCenters(clusters, numClusters);
        iterations++;
    }
}

int main() {
    int numPoints, numClusters;
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);
    printf("Enter the number of clusters: ");
    scanf("%d", &numClusters);

    Point points[numPoints];
    for (int i = 0; i < numPoints; i++) {
        printf("Enter point #%d: ", i+1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    Cluster clusters[numClusters];
    for (int i = 0; i < numClusters; i++) {
        printf("Enter initial center for cluster #%d: ", i+1);
        scanf("%lf %lf", &clusters[i].center.x, &clusters[i].center.y);
        clusters[i].size = 0;
    }

    clusterPoints(points, numPoints, clusters, numClusters);

    printf("\nFinal Clusters:\n");
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster #%d:\n", i+1);
        printCluster(clusters[i]);
    }

    return 0;
}