//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 4
#define E 5
#define INF 999999
#define MAX_ITER 1000

int graph[V][V];
int dist[V];
int parent[V];
int color[V];
int count_color[V];

void init_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = rand() % 101;
        }
    }
}

void dijkstra(int start_vertex) {
    int u, v, k, min_dist, min_index;
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
        color[i] = 0;
        count_color[i] = 0;
    }

    dist[start_vertex] = 0;

    for (int i = 0; i < MAX_ITER; i++) {
        int min_distance = INF;
        int u = -1;

        for (int j = 0; j < V; j++) {
            if (dist[j] <= min_distance &&!visited[j]) {
                min_distance = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                int new_dist = dist[u] + graph[u][v];

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    parent[v] = u;
                }
            }
        }
    }
}

void backtrack(int vertex) {
    int k = parent[vertex];

    if (k!= -1) {
        backtrack(k);
    }

    if (k == -1 || count_color[k] == 0) {
        color[vertex] = ++count_color[k];
    } else {
        color[vertex] = count_color[k];
    }
}

int main() {
    srand(time(0));
    init_graph();

    int start_vertex = 0;
    dijkstra(start_vertex);

    printf("Vertex\t Distance from Source\t Color\n");

    for (int i = 0; i < V; i++) {
        printf("%d \t %d \t %d\n", i, dist[i], color[i]);
    }

    return 0;
}