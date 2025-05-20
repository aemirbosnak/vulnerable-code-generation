//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define MAX_NODES 1000
#define INF 9999999

typedef struct {
    int id;
    int pos;
    int score;
} Player;

typedef struct {
    int id;
    int pos;
    int next;
} Node;

Node graph[MAX_NODES];
Player players[MAX_PLAYERS];

void init() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        graph[i].id = i;
        graph[i].pos = i;
        graph[i].next = -1;
    }
    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i;
        players[i].pos = 0;
        players[i].score = 0;
    }
}

void add_edge(int u, int v) {
    graph[u].next = v;
}

int bfs(int start, int end) {
    int q[MAX_NODES], front = 0, rear = 0;
    int visited[MAX_NODES];
    memset(visited, 0, sizeof(visited));
    q[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int u = q[front++];
        for (int v = graph[u].next; v!= -1; v = graph[v].next) {
            if (!visited[v]) {
                q[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    return visited[end];
}

int main() {
    int n, m, u, v, start, end, i;
    scanf("%d %d", &n, &m);
    init();
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    scanf("%d %d", &start, &end);
    int dist = bfs(start, end);
    if (dist == 0) {
        printf("No path found.\n");
    } else {
        printf("Shortest path: %d\n", dist);
    }
    return 0;
}