//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100
#define INF 1000000

int visited[MAX_N];
int dist[MAX_N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int astar(int x1, int y1, int x2, int y2, int cost) {
    int n = 0;
    visited[n] = 0;
    dist[n] = INF;
    n++;

    dist[n] = 0;
    visited[n] = 1;
    n++;

    int start = n;
    int end = n;

    while (n < MAX_N) {
        int min = INF;
        int min_node = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                min_node = i;
            }
        }

        visited[min_node] = 1;

        for (int i = 0; i < 4; i++) {
            int x = dx[i] + x1;
            int y = dy[i] + y1;

            if (x >= 0 && x < MAX_N && y >= 0 && y < MAX_N) {
                if (dist[min_node] + cost < dist[n]) {
                    dist[n] = dist[min_node] + cost;
                    end = n;
                }
            }
        }

        n++;
    }

    return end;
}

int main() {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    printf("Enter start coordinates: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter end coordinates: ");
    scanf("%d %d", &x2, &y2);

    int cost = 10;

    int path = astar(x1, y1, x2, y2, cost);

    printf("The shortest path is: ");

    for (int i = 0; i < path; i++) {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}