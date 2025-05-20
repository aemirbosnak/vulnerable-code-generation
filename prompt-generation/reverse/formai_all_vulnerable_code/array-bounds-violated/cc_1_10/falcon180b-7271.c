//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define M 1000
#define INF 999999

typedef struct {
    int x, y, t;
} node;

node graph[N][M];

void add_edge(int u, int v, int t) {
    graph[u][v] = (node) {.x = v,.y = u,.t = t };
}

int dijkstra(int start, int end) {
    int dist[N];
    int visited[N];
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    int count = 0;
    while (count < N - 1) {
        int u = -1;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && dist[i] <= dist[u])
                u = i;
        }
        visited[u] = 1;
        count++;
        for (int v = 0; v < N; v++) {
            if (!visited[v]) {
                node temp = graph[u][v];
                if (dist[u] + temp.t < dist[v]) {
                    dist[v] = dist[u] + temp.t;
                }
            }
        }
    }
    return dist[end];
}

int main() {
    int n, m, u, v, w, start, end;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    scanf("%d %d", &start, &end);
    int ans = dijkstra(start, end);
    printf("%d", ans);
    return 0;
}