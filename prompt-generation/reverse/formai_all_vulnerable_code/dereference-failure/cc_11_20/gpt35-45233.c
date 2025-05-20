//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>

int main() {
    int n, v = 0, k = 0, count = 0, connected = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int* visited = (int*) calloc(n, sizeof(int));
    int** graph = (int**) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) calloc(n, sizeof(int));
    }
    printf("Enter the %d x %d adjacency matrix: \n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("The adjacency matrix is: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
            if (graph[i][j] == 1) {
                count++;
            }
        }
        printf("\n");
    }
    count = count / 2; // Since the graph is undirected, we've counted twice
    printf("The graph has %d edges\n", count);
    
    while (k < n) {
        printf("Enter the source vertex to traverse the graph from: ");
        scanf("%d", &v);
        k = v - 1;
        if (v < 1 || v > n) {
            printf("Invalid vertex\n");
        }
    }
    
    printf("The graph is traversed from vertex %d as: ", v);
    visited[k] = 1;
    printf("%d ", k + 1);
    for (int i = 0; i < n; i++) {
        if (graph[k][i] == 1 && visited[i] == 0) {
            connected++;
        }
    }
    while (connected > 0) {
        for (int i = 0; i < n; i++) {
            if (graph[k][i] == 1 && visited[i] == 0) {
                connected--;
                visited[i] = 1;
                printf("%d ", i + 1);
                k = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (graph[k][i] == 1 && visited[i] == 0) {
                connected++;
            }
        }
    }
    printf("\n");
    return 0;
}