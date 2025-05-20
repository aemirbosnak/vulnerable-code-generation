//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUTES 100
#define MAX_NODES  1000
#define INF        1 << 30

int nRoutes, nNodes;
int graph[MAX_NODES][MAX_NODES], dist[MAX_ROUTES][MAX_NODES][MAX_NODES];

void floydWarshall() {
    int i, j, k, r;
    for (r = 0; r < nRoutes; r++) {
        for (k = 0; k < nNodes; k++) {
            for (i = 0; i < nNodes; i++) {
                for (j = 0; j < nNodes; j++) {
                    if (graph[i][k] != -1 && graph[k][j] != -1) {
                        int newDist = graph[i][k] + graph[k][j];
                        if (newDist < dist[r][i][j]) {
                            dist[r][i][j] = newDist;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int i, j, k, r, s, t;

    scanf("%d %d", &nNodes, &nRoutes);

    for (r = 0; r < nRoutes; r++) {
        for (i = 0; i < nNodes; i++) {
            for (j = 0; j < nNodes; j++) {
                dist[r][i][j] = INF;
            }
        }
    }

    for (i = 0; i < nNodes; i++) {
        for (j = 0; j < nNodes; j++) {
            graph[i][j] = -1;
        }
    }

    for (r = 0; r < nRoutes; r++) {
        scanf("%d", &k);

        int node[k];

        for (s = 0; s < k; s++) {
            scanf("%d", &node[s]);
        }

        for (s = 0; s < k; s++) {
            for (t = s + 1; t < k; t++) {
                int u = node[s] - 1, v = node[t] - 1;
                graph[u][v] = 1;
                graph[v][u] = 1;
            }
        }
    }

    floydWarshall();

    for (r = 0; r < nRoutes; r++) {
        int minDist = INF;

        for (i = 0; i < nNodes; i++) {
            for (j = i + 1; j < nNodes; j++) {
                if (dist[r][i][j] < minDist) {
                    minDist = dist[r][i][j];
                }
            }
        }

        printf("Route %d: %d\n", r + 1, minDist);
    }

    return 0;
}