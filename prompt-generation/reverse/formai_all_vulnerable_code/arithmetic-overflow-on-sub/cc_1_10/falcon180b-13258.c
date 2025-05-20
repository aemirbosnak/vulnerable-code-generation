//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_V 1000
#define MAX_E 10000
#define INF INT_MAX
#define EPS 0.0001

typedef struct {
    int u, v, c;
} Edge;

typedef struct {
    int v, dist;
    int prev;
} Vertex;

Vertex* V;
Edge* E;
int VNum, ENum;

void init() {
    V = (Vertex*)malloc(MAX_V * sizeof(Vertex));
    E = (Edge*)malloc(MAX_E * sizeof(Edge));
    VNum = 0;
    ENum = 0;
}

int SPFA(int start, int end) {
    int i, j, k, u, v, min_dist;
    int count = 0;
    time_t start_time, end_time;
    double elapsed_time;

    start_time = clock();

    for (i = 0; i < VNum; i++) {
        V[i].dist = INF;
        V[i].prev = -1;
    }

    V[start].dist = 0;

    while (count < VNum - 1) {
        min_dist = INF;
        u = -1;

        for (i = 0; i < VNum; i++) {
            if (V[i].dist < min_dist) {
                min_dist = V[i].dist;
                u = i;
            }
        }

        count++;

        if (u == -1) {
            break;
        }

        for (j = 0; j < ENum; j++) {
            v = E[j].v;
            if (V[u].dist + E[j].c < V[v].dist) {
                V[v].dist = V[u].dist + E[j].c;
                V[v].prev = u;
            }
        }
    }

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Shortest path: %d\n", V[end].dist);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return 0;
}

int main() {
    int i, j, u, v, c;

    init();

    printf("Enter the number of vertices: ");
    scanf("%d", &VNum);

    printf("Enter the number of edges: ");
    scanf("%d", &ENum);

    printf("Enter the vertices and their edges (u v c):\n");

    for (i = 0; i < ENum; i++) {
        scanf("%d %d %d", &u, &v, &c);
        E[i].u = u;
        E[i].v = v;
        E[i].c = c;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &u);

    printf("Enter the ending vertex: ");
    scanf("%d", &v);

    SPFA(u, v);

    return 0;
}