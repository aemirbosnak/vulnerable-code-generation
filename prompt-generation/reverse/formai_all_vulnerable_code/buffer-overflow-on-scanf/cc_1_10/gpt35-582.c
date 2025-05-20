//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int matrix[ROW][COL];
bool visited[ROW][COL];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool isValid(int r, int c) {
    if (r < 0 || c < 0 || r >= ROW || c >= COL) {
        return false;
    }
    if (visited[r][c] || matrix[r][c] == 0) {
        return false;
    }
    return true;
}

void depthFirstSearch(int r, int c) {
    visited[r][c] = true;
    printf("(%d, %d) ", r, c);
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isValid(nr, nc)) {
            depthFirstSearch(nr, nc);
        }
    }
}

int main() {
    printf("Please enter the matrix (0 for empty, 1 for obstacle):\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int startRow, startCol;
    printf("Please enter the starting position (row, column): ");
    scanf("%d %d", &startRow, &startCol);
    printf("Depth-first search path: ");
    depthFirstSearch(startRow, startCol);
    printf("\n");
    return 0;
}