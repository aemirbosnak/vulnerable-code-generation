//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>

#define MAX_NODE 100
#define MAX_EDGE 200
#define INF 9999999

typedef struct {
    int x, y;
}Node;

typedef struct {
    int u, v, cost;
}Edge;

Edge graph[MAX_EDGE];
int n, m;

void init() {
    memset(graph, 0, sizeof(graph));
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);
        graph[i].u = u;
        graph[i].v = v;
        graph[i].cost = cost;
    }
}

void dijkstra(int start, int end) {
    int dist[MAX_NODE];
    int prev[MAX_NODE];
    int visited[MAX_NODE];
    memset(dist, INF, sizeof(dist));
    memset(prev, -1, sizeof(prev));
    dist[start] = 0;

    for(int i=0; i<n; i++) {
        int u = -1, min_dist = INF;
        for(int j=0; j<n; j++) {
            if(!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        visited[u] = 1;

        for(int j=0; j<m; j++) {
            if(graph[j].u == u &&!visited[graph[j].v]) {
                int new_dist = dist[u] + graph[j].cost;
                if(new_dist < dist[graph[j].v]) {
                    dist[graph[j].v] = new_dist;
                    prev[graph[j].v] = u;
                }
            }
        }
    }

    int path[MAX_NODE];
    int path_size = 0;
    int v = end;
    while(v!= -1) {
        path[path_size++] = v;
        v = prev[v];
    }
    path_size--;

    printf("Shortest path from node %d to node %d:\n", start, end);
    for(int i=path_size-1; i>=0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    init();
    int start, end;
    printf("Enter start node: ");
    scanf("%d", &start);
    printf("Enter end node: ");
    scanf("%d", &end);
    dijkstra(start, end);
    return 0;
}