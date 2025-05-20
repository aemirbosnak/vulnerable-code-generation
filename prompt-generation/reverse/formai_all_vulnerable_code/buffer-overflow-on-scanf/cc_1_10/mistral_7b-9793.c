//MISTRAL-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_VERTS 100
#define INF 100000

typedef struct {
    int x, y;
    char name[50];
} Vertex;

bool isValid(int **matrix, int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (matrix[x][y] == INF)
        return false;
    return true;
}

int dijkstra(int **matrix, int n, int m, int start) {
    int dist[MAX_VERTS];
    bool visited[MAX_VERTS];
    int current = start;

    memset(dist, INF, sizeof(dist));
    memset(visited, false, sizeof(visited));

    dist[start] = 0;

    while (true) {
        bool foundMin = false;
        int minDist = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                current = i;
                foundMin = true;
            }
        }

        if (!foundMin)
            break;

        visited[current] = true;

        for (int i = 0; i < m; i++) {
            int neighbor = i + current * m;
            if (isValid(matrix, current / m, i % m, n, m) &&
                dist[current] + matrix[current / m][i % m] < dist[neighbor]) {
                dist[neighbor] = dist[current] + matrix[current / m][i % m];
            }
        }
    }

    return dist[start];
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    int **matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = calloc(m, sizeof(int));
    }

    printf("Enter edges (x, y, weight):\n");
    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        matrix[x / m][y % m] = w;
        matrix[y / m][x % m] = w;
    }

    int start;
    printf("Enter starting vertex:\n");
    scanf("%d", &start);

    printf("Shortest path from %s to all others: ", "You");
    for (int i = 0; i < n; i++) {
        Vertex vert = {i / m, i % m, ""};
        sprintf(vert.name, "%c%c", 'A' + i / m, 'A' + i % m);
        printf("%s: %d ", vert.name, dijkstra(matrix, n, m, i));
    }
    printf("\n");

    free(matrix);
    return 0;
}