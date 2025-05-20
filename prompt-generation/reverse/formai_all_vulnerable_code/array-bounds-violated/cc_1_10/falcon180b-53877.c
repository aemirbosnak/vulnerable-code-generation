//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define INF 9999
#define V 8

int dist[MAX][V];
int pred[MAX][V];

void initDist(int start, int end) {
    for(int i = 0; i < V; i++) {
        dist[start][i] = INF;
        pred[start][i] = -1;
    }
    dist[start][end] = 0;
}

void dijkstra(int start, int end) {
    int u, v;
    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[start][j]!= INF && dist[start][j] + dist[j][end] < dist[start][j]) {
                dist[start][j] = dist[start][j] + dist[j][end];
                pred[start][j] = j;
            }
        }
    }
}

void printPath(int start, int end) {
    int u = end;
    while(u!= -1) {
        printf("%d ", u);
        u = pred[u][end];
    }
    printf("\n");
}

int main() {
    int start, end;
    srand(time(NULL));
    start = rand() % MAX;
    end = rand() % MAX;
    printf("Start: %d\n", start);
    printf("End: %d\n", end);
    initDist(start, end);
    dijkstra(start, end);
    printPath(start, end);
    return 0;
}