//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 999999

int graph[MAX_VERTEX][MAX_VERTEX];
int dist[MAX_VERTEX];
int n;

void bellman_ford(int start)
{
    int i, j, k;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        graph[i][start] = 0;
    }
    dist[start] = 0;

    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (graph[j][k]!= INF && graph[k][j]!= INF && graph[j][k] + graph[k][j] < dist[j]) {
                    dist[j] = graph[j][k] + graph[k][j];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i]!= INF && dist[i] + graph[i][j] < dist[j]) {
                dist[j] = dist[i] + graph[i][j];
            }
        }
    }
}

int main()
{
    int i, j, k;
    char str[10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%s", str);
            if (str[0] == 'Y') {
                graph[i][j] = 1;
            }
        }
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bellman_ford(start);

    printf("Vertex\tDistance\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}