//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000
#define MAXM 1000
#define INF 1000000000

int n, m, k, u, v, w, i, j, c, d, x, y, z, t, cnt, res;
int graph[MAXN][MAXN], dist[MAXN], parent[MAXN], color[MAXN], minDist[MAXN];
int q[MAXM], front, rear;

void init() {
    for (int i = 0; i < MAXN; i++) {
        graph[i][i] = 0;
        for (int j = i + 1; j < MAXN; j++) {
            graph[i][j] = INF;
            graph[j][i] = INF;
        }
    }
}

void dijkstra(int start) {
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
        color[i] = -1;
        parent[i] = -1;
    }
    dist[start] = 0;
    q[rear++] = start;
    while (front < rear) {
        int u = q[front++];
        for (int v = 0; v < MAXN; v++) {
            if (graph[u][v]!= INF && dist[u]!= INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                q[rear++] = v;
            }
        }
    }
}

void colorGraph() {
    int s = 0;
    for (int i = 0; i < MAXN; i++) {
        if (dist[i] > dist[s]) {
            s = i;
        }
    }
    for (int i = 0; i < MAXN; i++) {
        if (i!= s && dist[i] == dist[s]) {
            cnt++;
        }
    }
    if (cnt == 0) {
        for (int i = 0; i < MAXN; i++) {
            color[i] = 0;
        }
    } else if (cnt == 1) {
        for (int i = 0; i < MAXN; i++) {
            if (i!= s) {
                color[i] = 1;
            }
        }
    } else {
        for (int i = 0; i < MAXN; i++) {
            if (i == s) {
                color[i] = 0;
            } else if (dist[i] == dist[s] - 1) {
                color[i] = 1;
            } else {
                color[i] = 2;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    init();
    dijkstra(0);
    colorGraph();
    printf("Minimum Coloring: %d\n", res);
    return 0;
}