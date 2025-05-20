//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 1000000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m;
int dist[MAX_NODES];
int visited[MAX_NODES];

void bellmanFord(int start) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (k = 1; k < n; k++) {
        for (i = 0; i < m; i++) {
            j = edges[i].u;
            if (dist[j]!= INF && dist[j] + edges[i].w < dist[edges[i].v]) {
                dist[edges[i].v] = dist[j] + edges[i].w;
            }
        }
    }

    for (i = 0; i < m; i++) {
        j = edges[i].u;
        if (dist[j]!= INF && dist[j] + edges[i].w < dist[edges[i].v]) {
            printf("Negative weight cycle found!\n");
            exit(0);
        }
    }
}

int main() {
    int i, j, u, v, w;
    char filename[50];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(0);
    }

    fscanf(fp, "%d %d", &n, &m);
    printf("Number of nodes: %d\n", n);
    printf("Number of edges: %d\n", m);

    for (i = 0; i < m; i++) {
        fscanf(fp, "%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    fclose(fp);

    printf("Enter the starting node: ");
    scanf("%d", &u);

    bellmanFord(u);

    printf("\nVertex\tDistance\n");
    for (i = 0; i < n; i++) {
        if (dist[i]!= INF) {
            printf("%d\t%d\n", i, dist[i]);
        }
    }

    return 0;
}