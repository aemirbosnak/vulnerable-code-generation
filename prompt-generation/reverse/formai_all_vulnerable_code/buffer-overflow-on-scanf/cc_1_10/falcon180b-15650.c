//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

Edge edge[MAX_EDGE];
int parent[MAX_VERTEX];
int rank[MAX_VERTEX];

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (parent[v]!= v) {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}

void union_set(int u, int v) {
    int pu = find_set(u);
    int pv = find_set(v);
    if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else {
        parent[pu] = pv;
        if (rank[pu] == rank[pv]) {
            rank[pv]++;
        }
    }
}

bool kruskal() {
    int count = 0;
    for (int i = 0; i < MAX_EDGE; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int pu = find_set(u);
        int pv = find_set(v);
        if (pu!= pv) {
            count++;
            union_set(u, v);
        }
    }
    return count == MAX_VERTEX - 1;
}

void print_solution(int n) {
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == find_set(i) && j == find_set(j)) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

void read_graph(int n) {
    printf("Enter the edges of the graph:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    read_graph(n);

    if (kruskal()) {
        print_solution(n);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}