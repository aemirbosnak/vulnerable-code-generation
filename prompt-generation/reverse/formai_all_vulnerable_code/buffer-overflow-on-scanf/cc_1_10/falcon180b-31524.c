//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define EPS 1e-6

typedef struct {
    int x, y;
} Point;

typedef struct {
    int v1, v2;
} Edge;

Point vertices[MAX_VERTEX];
Edge edges[MAX_EDGE];
int numVertices, numEdges;

double distance(int i, int j) {
    return sqrt(pow(vertices[i].x - vertices[j].x, 2) + pow(vertices[i].y - vertices[j].y, 2));
}

void readVertices() {
    printf("Enter the number of vertices:\n");
    scanf("%d", &numVertices);
    for (int i = 0; i < numVertices; i++) {
        printf("Enter the coordinates of vertex %d:\n", i + 1);
        scanf("%d %d", &vertices[i].x, &vertices[i].y);
    }
}

void readEdges() {
    printf("Enter the number of edges:\n");
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        printf("Enter the endpoints of edge %d (in the form v1 v2):\n", i + 1);
        scanf("%d %d", &edges[i].v1, &edges[i].v2);
    }
}

void GrahamScan() {
    int hull[MAX_VERTEX];
    int k = 0;
    for (int i = 0; i < numVertices; i++) {
        int j = 0;
        for (int l = 0; l < k; l++) {
            double angle = atan2(vertices[hull[l]].y - vertices[i].y, vertices[hull[l]].x - vertices[i].x) - atan2(vertices[hull[0]].y - vertices[hull[k - 1]].y, vertices[hull[0]].x - vertices[hull[k - 1]].x);
            if (angle > M_PI) angle -= 2 * M_PI;
            if (angle < -M_PI) angle += 2 * M_PI;
            if (angle > EPS) j = l + 1;
        }
        if (j == k) {
            hull[k++] = i;
        } else {
            int temp = hull[j];
            hull[j] = hull[k - 1];
            hull[k - 1] = temp;
        }
    }
    printf("The convex hull has %d vertices:\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", hull[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    readVertices();
    readEdges();
    GrahamScan();
    return 0;
}