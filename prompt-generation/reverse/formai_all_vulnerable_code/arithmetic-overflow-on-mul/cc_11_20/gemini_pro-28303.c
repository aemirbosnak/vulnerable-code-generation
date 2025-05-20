//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, m, i, j, k, l, x, y, z, a, b, c, d, e, f, g, h, o, p, q, r, s, t, u, v, w, x1, y1, z1, a1, b1, c1, d1, e1, f1, g1, h1, o1, p1, q1, r1, s1, t1, u1, v1, w1;
    scanf("%d %d", &n, &m);
    char grid[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }
    scanf("%d %d %d %d", &x, &y, &z, &w);
    char path[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            path[i][j] = '*';
        }
    }
    path[x][y] = 'S';
    path[z][w] = 'E';
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int queue[n * m][2];
    int head = 0;
    int tail = 0;
    queue[tail][0] = x;
    queue[tail][1] = y;
    tail++;
    while (head != tail) {
        x = queue[head][0];
        y = queue[head][1];
        head++;
        for (i = 0; i < 4; i++) {
            a = x + dx[i];
            b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && path[a][b] == '*') {
                if (grid[a][b] == '.' || grid[a][b] == 'E') {
                    path[a][b] = path[x][y] + 1;
                    queue[tail][0] = a;
                    queue[tail][1] = b;
                    tail++;
                }
            }
        }
    }
    if (path[z][w] == '*') {
        printf("No path found\n");
    } else {
        printf("Shortest path:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%c", path[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}