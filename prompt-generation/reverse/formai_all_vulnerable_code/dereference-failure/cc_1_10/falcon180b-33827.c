//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char name[50];
    int degree;
    int *adj_list;
} Node;

void add_edge(Node *graph, int u, int v) {
    graph[v].adj_list[graph[v].degree++] = u;
}

void bfs(Node *graph, int start, int end) {
    bool visited[MAX_NODES];
    memset(visited, false, sizeof(visited));

    int queue[MAX_NODES];
    int front = 0, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front <= rear) {
        int curr = queue[front++];

        printf("%d ", curr);

        for (int i = 0; i < graph[curr].degree; i++) {
            int next = graph[curr].adj_list[i];

            if (!visited[next]) {
                visited[next] = true;
                queue[++rear] = next;
            }
        }
    }
}

int main() {
    Node graph[MAX_NODES];

    int n, m;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter node ID and name (in format ID name):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &graph[i].id, graph[i].name);
        graph[i].degree = 0;
        graph[i].adj_list = (int *)malloc(MAX_EDGES * sizeof(int));
        memset(graph[i].adj_list, -1, MAX_EDGES * sizeof(int));
    }

    printf("Enter edges (in format u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(graph, u, v);
    }

    int start, end;
    printf("Enter start node ID: ");
    scanf("%d", &start);

    printf("Enter end node ID: ");
    scanf("%d", &end);

    bfs(graph, start, end);

    return 0;
}