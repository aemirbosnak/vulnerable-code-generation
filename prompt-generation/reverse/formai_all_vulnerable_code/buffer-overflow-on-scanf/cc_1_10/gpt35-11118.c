//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_POINTS 100
#define CLUSTER_THRESH 2.0

/* Struct to represent a point in the plane */
typedef struct point {
    float x;
    float y;
} Point;

/* Function to calculate Euclidean distance between two points */
float getDistance(Point p1, Point p2) {
    float dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return dist;
}

/* Function to cluster points together */
void clusterPoints(Point points[], int numPoints) {
    int i, j, count, clusterNum;
    bool isClustered[MAX_POINTS] = { false };
    float dist;

    for (i = 0; i < numPoints; i++) {
        if (isClustered[i])
            continue;
        
        clusterNum++;
        printf("Cluster %d: ", clusterNum);
        isClustered[i] = true;
        
        for (j = i + 1; j < numPoints; j++) {
            if (isClustered[j])
                continue;

            dist = getDistance(points[i], points[j]);
            if (dist < CLUSTER_THRESH) {
                isClustered[j] = true;
                printf("(%0.2f, %0.2f) ", points[j].x, points[j].y);
            }
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    int i, numPoints;

    printf("Enter number of points: ");
    scanf("%d", &numPoints);

    Point points[MAX_POINTS];
    printf("Enter %d points in the format 'x y':\n", numPoints);
    for (i = 0; i < numPoints; i++)
        scanf("%f %f", &points[i].x, &points[i].y);

    clusterPoints(points, numPoints);
    
    return 0;
}