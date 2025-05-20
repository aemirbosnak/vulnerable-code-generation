//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int dest, weight; } Edge;

void init(int *parent, int n) {
    int i;
    for (i = 0; i < n; i++) parent[i] = i;
}

int find(int *parent, int node) {
    if (parent[node] != node) {
        parent[node] = find(parent, parent[node]);
    }
    return parent[node];
}

void union_set(int *parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    const Edge *aa = (const Edge *)a;
    const Edge *bb = (const Edge *)b;
    return aa->weight < bb->weight ? -1 : aa->weight > bb->weight;
}

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    Edge *edges = malloc(m * sizeof(Edge));

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].dest, &edges[i].weight, &j);
        edges[i].dest--; // adjust for zero indexing
    }

    qsort(edges, m, sizeof(Edge), compare);

    int *parent = malloc(n * sizeof(int));
    init(parent, n);

    int num_edges = 0;
    for (i = 0; i < m && num_edges < n - 1; i++) {
        int a = find(parent, edges[i].dest);
        int b = find(parent, edges[i + 1].dest);
        if (a != b) {
            printf("Edge (%d, %d) added.\n", edges[i].dest + 1, edges[i].dest + 1 > edges[i + 1].dest ? edges[i].dest + 1 : edges[i + 1].dest + 1);
            union_set(parent, a, b);
            num_edges++;
        }
    }

    free(parent);
    free(edges);

    printf("MST constructed with %d edges.\n", num_edges);

    return 0;
}