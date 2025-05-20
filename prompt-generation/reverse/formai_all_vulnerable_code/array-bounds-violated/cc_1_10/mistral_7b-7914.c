//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define M 6
#define N 6

typedef struct {
    int x, y;
} point;

char map[M][N];
int visit[M][N];
point neighbors[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool isValid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N && map[x][y] != '#';
}

void colorMap(int x, int y, char color) {
    map[x][y] = color;
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + neighbors[i].x, ny = y + neighbors[i].y;
        if (isValid(nx, ny)) {
            colorMap(nx, ny, color);
        }
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] != '#' && visit[i][j] == 0) {
                int color = map[i][j] == 'H' ? 'R' : 'B' ;
                colorMap(i, j, color);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    for (int i = 0; i < M; i++) {
        fgets(map[i], N, stdin);
        map[i][N] = '\0';
    }

    solve();

    for (int i = 0; i < M; i++) {
        printf("%s\n", map[i]);
    }

    return 0;
}