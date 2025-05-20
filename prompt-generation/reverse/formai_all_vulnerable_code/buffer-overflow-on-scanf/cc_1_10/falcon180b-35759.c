//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 1000
#define MAX_EDGE_NUM 5000
#define INF 0x3f3f3f3f

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

Edge edge[MAX_EDGE_NUM];
int edge_count;

void add_edge(int from, int to, int cost) {
    edge[edge_count] = (Edge) {to, cost, -1};
    edge_count++;
}

int spfa(int start, int end, int *distance) {
    int i, j, k, u, v;
    int queue[MAX_VERTEX_NUM];
    int in_queue[MAX_VERTEX_NUM];
    int count = 0;
    int shortest_distance = INF;

    memset(distance, 0x3f, sizeof(int) * MAX_VERTEX_NUM);
    distance[start] = 0;
    in_queue[start] = true;
    queue[count++] = start;

    while (count > 0) {
        u = queue[0];
        queue[0] = queue[--count];
        in_queue[u] = false;

        for (i = edge[u].next; i!= -1; i = edge[i].next) {
            v = edge[i].to;
            if (distance[u] + edge[i].cost < distance[v]) {
                distance[v] = distance[u] + edge[i].cost;
                if (!in_queue[v]) {
                    in_queue[v] = true;
                    queue[count++] = v;
                }
            }
        }
    }

    return shortest_distance;
}

int main() {
    int n, m, start, end;
    scanf("%d %d", &n, &m);

    edge_count = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    int distance[MAX_VERTEX_NUM];
    int shortest_distance = spfa(0, n - 1, distance);

    printf("The shortest path is: %d\n", shortest_distance);

    return 0;
}