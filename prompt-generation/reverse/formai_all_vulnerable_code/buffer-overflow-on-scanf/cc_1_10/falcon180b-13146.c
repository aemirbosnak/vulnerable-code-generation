//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_POINTS 1000
#define MAX_EDGES 2000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p1, p2;
    int weight;
} Edge;

int n, m;
Point points[MAX_POINTS];
Edge edges[MAX_EDGES];

void readPoints() {
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 1000;
        points[i].y = rand() % 1000;
        printf("%d %d\n", points[i].x, points[i].y);
    }
}

void readEdges() {
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the endpoints and weight of each edge:\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i].p1.x = points[u].x;
        edges[i].p1.y = points[u].y;
        edges[i].p2.x = points[v].x;
        edges[i].p2.y = points[v].y;
        edges[i].weight = w;
    }
}

void kruskal() {
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int e = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int u = findParent(parent, i);
            int v = findParent(parent, j);
            if (u!= v) {
                parent[u] = v;
                edges[e].p1 = points[i];
                edges[e].p2 = points[j];
                edges[e].weight = rand() % 100;
                e++;
            }
        }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        Point p1 = edges[i].p1;
        Point p2 = edges[i].p2;
        printf("(%d, %d) -- (%d, %d) = %d\n", p1.x, p1.y, p2.x, p2.y, edges[i].weight);
    }
}

int findParent(int parent[], int v) {
    if (parent[v] == v)
        return v;
    else
        return findParent(parent, parent[v]);
}

int main() {
    srand(time(NULL));
    readPoints();
    readEdges();
    kruskal();
    return 0;
}