//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int x, y;
} point;

int manhattan_distance(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int euclidean_distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n, m, i, j, x1, y1, x2, y2, dist;
    point start, goal;
    int visited[100][100];
    point current_node, next_node;
    int min_dist = INT_MAX;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &visited[i][j]);
        }
    }
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    start.x = x1; start.y = y1;
    goal.x = x2; goal.y = y2;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (visited[i][j] == 0) {
                current_node.x = i; current_node.y = j;
                visited[i][j] = 1;
                dist = INT_MAX;
                while (dist!= 0) {
                    dist = 0;
                    for (j = 0; j < n; j++) {
                        for (i = 0; i < m; i++) {
                            if (visited[j][i] == 0) {
                                next_node.x = j; next_node.y = i;
                                if (manhattan_distance(current_node, next_node) < dist) {
                                    dist = manhattan_distance(current_node, next_node);
                                    next_node.x = j; next_node.y = i;
                                }
                            }
                        }
                    }
                    current_node = next_node;
                }
                if (dist == INT_MAX) {
                    printf("No path found.\n");
                } else {
                    printf("Minimum distance: %d\n", dist);
                }
            }
        }
    }
    return 0;
}