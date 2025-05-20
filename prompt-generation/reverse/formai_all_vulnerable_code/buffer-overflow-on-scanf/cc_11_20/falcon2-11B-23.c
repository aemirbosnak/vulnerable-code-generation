//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int x;
    int y;
} Coord;

int visited[MAX_ROWS][MAX_COLS];
int parent[MAX_ROWS][MAX_COLS];

int dfs(int x, int y) {
    visited[x][y] = 1;
    if (x == 0 && y == 0) {
        printf("Destination reached.\n");
        return 1;
    }
    
    int child_count = 0;
    int child[MAX_ROWS][MAX_COLS];
    
    if (x > 0 &&!visited[x-1][y]) {
        child_count++;
        child[child_count][0] = x-1;
        child[child_count][1] = y;
    }
    if (x < MAX_ROWS-1 &&!visited[x+1][y]) {
        child_count++;
        child[child_count][0] = x+1;
        child[child_count][1] = y;
    }
    if (y > 0 &&!visited[x][y-1]) {
        child_count++;
        child[child_count][0] = x;
        child[child_count][1] = y-1;
    }
    if (y < MAX_COLS-1 &&!visited[x][y+1]) {
        child_count++;
        child[child_count][0] = x;
        child[child_count][1] = y+1;
    }
    
    for (int i = 0; i < child_count; i++) {
        if (dfs(child[i][0], child[i][1])) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    int x = 0, y = 0;
    
    printf("Enter the start coordinates (row, column): ");
    scanf("%d %d", &x, &y);
    
    int x_end = x, y_end = y;
    
    while (1) {
        printf("Enter the end coordinates (row, column): ");
        scanf("%d %d", &x_end, &y_end);
        
        if (x_end == x && y_end == y) {
            printf("Destination reached.\n");
            break;
        }
        
        visited[x_end][y_end] = 1;
        
        if (x_end == 0 && y_end == 0) {
            printf("Destination reached.\n");
            break;
        }
        
        int child_count = 0;
        int child[MAX_ROWS][MAX_COLS];
        
        if (x_end > 0 &&!visited[x_end-1][y_end]) {
            child_count++;
            child[child_count][0] = x_end-1;
            child[child_count][1] = y_end;
        }
        if (x_end < MAX_ROWS-1 &&!visited[x_end+1][y_end]) {
            child_count++;
            child[child_count][0] = x_end+1;
            child[child_count][1] = y_end;
        }
        if (y_end > 0 &&!visited[x_end][y_end-1]) {
            child_count++;
            child[child_count][0] = x_end;
            child[child_count][1] = y_end-1;
        }
        if (y_end < MAX_COLS-1 &&!visited[x_end][y_end+1]) {
            child_count++;
            child[child_count][0] = x_end;
            child[child_count][1] = y_end+1;
        }
        
        for (int i = 0; i < child_count; i++) {
            if (dfs(child[i][0], child[i][1])) {
                return 1;
            }
        }
    }
    
    return 0;
}