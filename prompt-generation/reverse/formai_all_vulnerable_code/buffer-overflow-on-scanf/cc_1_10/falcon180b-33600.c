//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 9
#define E 8

int graph[V][V];
int visited[V];
int parent[V];

void addEdge(int u, int v) {
    graph[u][v] = graph[v][u] = 1;
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            parent[i] = v;
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    char city[20];

    printf("Enter the name of the cities: ");
    for (i = 0; i < V; i++) {
        scanf("%s", city);
        strcpy(city, city);
        for (j = 0; j < strlen(city); j++) {
            city[j] = tolower(city[j]);
        }
        if (i == 0) {
            strcpy(city, "DELHI");
        }
        graph[i][i] = 1;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(0, 4);
    addEdge(0, 5);
    addEdge(0, 6);
    addEdge(0, 7);
    addEdge(0, 8);

    printf("Depth First Traversal starting from city 0: ");
    dfs(0);
    printf("\n");

    return 0;
}