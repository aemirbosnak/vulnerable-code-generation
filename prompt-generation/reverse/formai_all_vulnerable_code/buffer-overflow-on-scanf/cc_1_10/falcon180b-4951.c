//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define INF 999999

int n, m;
int graph[MAX_NODES][MAX_EDGES];
int dist[MAX_NODES];
int parent[MAX_NODES];
int path[MAX_NODES];
int start, end;

void init() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            graph[i][j] = rand() % 1000;
        }
    }
}

void a_star() {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    int open_list[n];
    int open_size = 1;
    int closed_size = 0;
    int open_front = 0;
    int closed_front = 0;
    open_list[0] = start;
    while (open_size > 0 || closed_size > 0) {
        if (open_front == open_size) {
            open_front = 0;
            closed_front = 0;
            for (int i = 0; i < n; i++) {
                if (i!= start && i!= end) {
                    if (dist[i] < INF) {
                        open_list[open_size] = i;
                        open_size++;
                    }
                }
            }
        }
        int u = open_list[open_front++];
        closed_size++;
        for (int v = 0; v < n; v++) {
            if (graph[u][v]!= INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                if (v!= start) {
                    if (open_front == open_size) {
                        open_front = 0;
                    }
                    open_list[open_front++] = v;
                    open_size++;
                }
            }
        }
        if (u == end) {
            break;
        }
    }
    int v = end;
    while (v!= -1) {
        path[v] = start;
        v = parent[v];
    }
}

void print_path() {
    printf("Path from %d to %d: ", start, end);
    for (int i = start; i!= -1; i = path[i]) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init();
    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the end node: ");
    scanf("%d", &end);
    a_star();
    print_path();
    return 0;
}