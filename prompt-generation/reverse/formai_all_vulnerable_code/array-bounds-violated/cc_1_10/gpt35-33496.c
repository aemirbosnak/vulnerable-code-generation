//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: standalone
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#define ROW 5 
#define COL 5 

int dx[4] = { 1, -1, 0, 0 }; 
int dy[4] = { 0, 0, 1, -1 }; 

bool isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL); 
} 

bool isEnd(int x, int y, int end_x, int end_y) {
    return (x == end_x && y == end_y); 
} 

int BFS(int mat[][COL], int start_x, int start_y, int end_x, int end_y) {
    bool visited[ROW][COL];
    memset(visited, false, sizeof(visited)); 

    visited[start_x][start_y] = true; 

    int queue[ROW*COL]; 
    int front = -1, rear = -1; 

    queue[++rear] = start_x; 
    queue[++rear] = start_y; 

    int level = 0, nodesLeft = 1, nodesNext = 0; 
    while (front != rear) {
        int curr_x = queue[++front]; 
        int curr_y = queue[++front]; 

        if (isEnd(curr_x, curr_y, end_x, end_y)) 
            return level; 

        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i]; 
            int next_y = curr_y + dy[i]; 

            if (isValid(next_x, next_y) && !visited[next_x][next_y] && mat[next_x][next_y]) {
                visited[next_x][next_y] = true; 
                queue[++rear] = next_x; 
                queue[++rear] = next_y; 
                nodesNext++; 
            } 
        } 

        nodesLeft--; 
        if (nodesLeft == 0) {
            nodesLeft = nodesNext; 
            nodesNext = 0; 
            level++; 
        } 
    } 

    return -1; 
} 

int main() {
    int mat[ROW][COL] = { { 1, 0, 1, 0, 1 }, 
                          { 1, 1, 1, 1, 0 }, 
                          { 0, 1, 0, 1, 1 }, 
                          { 0, 1, 1, 1, 0 }, 
                          { 1, 1, 1, 0, 1 } };
    int start_x = 0, start_y = 0, end_x = 3, end_y = 3; 

    int shortestDistance = BFS(mat, start_x, start_y, end_x, end_y); 
    if (shortestDistance == -1) 
        printf("No path found\n"); 
    else 
        printf("Shortest Distance: %d\n", shortestDistance); 

    return 0; 
}