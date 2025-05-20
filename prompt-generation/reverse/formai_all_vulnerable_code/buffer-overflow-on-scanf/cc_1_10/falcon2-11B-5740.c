//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100

bool is_blocked(int x, int y) {
    // implementation for blocked space
    return false;
}

bool dfs(int start_x, int start_y, int end_x, int end_y, int r, int c) {
    if (start_x == end_x && start_y == end_y) {
        return true;
    }
    
    if (is_blocked(start_x, start_y) || r < 0 || c < 0 || start_x < 0 || start_y < 0 || start_x >= r || start_y >= c) {
        return false;
    }
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int new_x = start_x + dx[i];
        int new_y = start_y + dy[i];
        if (is_blocked(new_x, new_y)) {
            continue;
        }
        
        if (dfs(new_x, new_y, end_x, end_y, r, c)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int start_x = 0, start_y = 0;
    int end_x = 0, end_y = 0;
    
    printf("Enter start position (x,y): ");
    scanf("%d %d", &start_x, &start_y);
    printf("Enter end position (x,y): ");
    scanf("%d %d", &end_x, &end_y);
    
    int r = MAX_ROWS;
    int c = MAX_COLS;
    
    if (dfs(start_x, start_y, end_x, end_y, r, c)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }
    
    return 0;
}