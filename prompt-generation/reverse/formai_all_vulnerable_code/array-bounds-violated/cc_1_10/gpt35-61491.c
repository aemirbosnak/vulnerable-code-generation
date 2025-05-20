//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int visited[MAX];

bool dfs(int current, int parent, int target, int n) {
    visited[current] = true;

    for(int i = 0; i < n; i++) {
        if(graph[current][i] == 1 && visited[i] == false) {
            if(i == target) {
                return true;
            } else {
                if(dfs(i, current, target, n)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for(int i = 0; i < n; i++) {
        visited[i] = false;

        for(int j = 0; j < n; j++) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    printf("Enter edges: \n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter start and end nodes: ");
    scanf("%d %d", &u, &v);

    if(dfs(u, -1, v, n)) {
        printf("Path exists between %d and %d\n", u, v);
    } else {
        printf("Path does not exist between %d and %d\n", u, v);
    }

    return 0;
}