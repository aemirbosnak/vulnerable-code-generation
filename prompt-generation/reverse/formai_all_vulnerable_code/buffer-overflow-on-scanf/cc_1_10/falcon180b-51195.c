//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define INF 999

int dist[MAX][MAX];
int path[MAX][MAX];

void initialise() {
    int i, j;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            dist[i][j] = INF;
            path[i][j] = -1;
        }
    }
}

void dijkstra(int start, int end) {
    int u, v, min_dist, i, j;
    int visited[MAX];
    for(i=0; i<MAX; i++) {
        visited[i] = 0;
    }
    initialise();
    dist[start][start] = 0;
    for(i=0; i<MAX-1; i++) {
        for(j=0; j<MAX-1; j++) {
            if(dist[start][j]!= INF && dist[j][end]!= INF) {
                if(dist[start][j] + dist[j][end] < dist[start][end]) {
                    path[start][end] = j;
                    dist[start][end] = dist[start][j] + dist[j][end];
                }
            }
        }
    }
    printf("\nThe shortest path from %d to %d is:\n", start, end);
    printf("%d", end);
    while(path[end][--start]!= -1) {
        printf(" -> %d", start);
    }
    printf("\n");
}

int main() {
    int start, end, i, j;
    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the end node: ");
    scanf("%d", &end);
    dijkstra(start, end);
    return 0;
}