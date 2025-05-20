//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000
#define INF INT_MAX

typedef struct {
    int x, y;
} Node;

Node graph[MAX_NODES];
int n, m;

void init() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &graph[i].x, &graph[i].y);
    }
}

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void AStar(int start, int end) {
    int openList[MAX_NODES], closedList[MAX_NODES];
    int openCount = 0, closedCount = 0;
    int parent[MAX_NODES];
    int gScore[MAX_NODES], fScore[MAX_NODES];

    for (int i = 0; i < n; i++) {
        gScore[i] = INF;
        fScore[i] = INF;
        parent[i] = -1;
    }

    gScore[start] = 0;
    openList[openCount++] = start;

    while (openCount > 0) {
        int u = -1;
        for (int i = 0; i < openCount; i++) {
            if (fScore[openList[i]] < fScore[u]) {
                u = openList[i];
            }
        }

        if (u == end) {
            break;
        }

        closedList[closedCount++] = u;
        openList[u] = -1;

        for (int v = 0; v < n; v++) {
            if (graph[u].x == graph[v].x && graph[u].y == graph[v].y) {
                if (gScore[u] + heuristic(graph[u], graph[v]) < gScore[v]) {
                    gScore[v] = gScore[u] + heuristic(graph[u], graph[v]);
                    fScore[v] = gScore[v] + heuristic(graph[v], graph[end]);
                    parent[v] = u;
                }
            }
        }
    }

    printf("Path: ");
    int v = end;
    while (v!= -1) {
        printf("%d ", v);
        v = parent[v];
    }
    printf("\n");
}

int main() {
    init();
    int start, end;
    scanf("%d %d", &start, &end);
    AStar(start, end);
    return 0;
}