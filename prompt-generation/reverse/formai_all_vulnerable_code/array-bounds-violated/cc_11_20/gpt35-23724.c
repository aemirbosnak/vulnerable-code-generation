//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    char grid[10][10];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the grid:\n");
    for(int i=0; i<rows; i++) {
        scanf("%s", grid[i]);
    }
    printf("The grid is:\n");
    for(int i=0; i<rows; i++) {
        printf("%s\n", grid[i]);
    }
    int start_row, start_col, end_row, end_col;
    printf("Enter start position (row col): ");
    scanf("%d %d", &start_row, &start_col);
    printf("Enter end position (row col): ");
    scanf("%d %d", &end_row, &end_col);
    int visited[10][10] = {0};
    int parent[10][10][2];
    int queue[100][2], front=-1, rear=-1;
    queue[++rear][0] = start_row;
    queue[rear][1] = start_col;
    visited[start_row][start_col] = 1;
    parent[start_row][start_col][0] = -1;
    parent[start_row][start_col][1] = -1;
    int found = 0;
    while(front != rear && !found) {
        int curr_row = queue[++front][0];
        int curr_col = queue[front][1];
        if(curr_row == end_row && curr_col == end_col) {
            found = 1;
            break;
        }
        // add all neighbors to the queue
        for(int r=curr_row-1; r<=curr_row+1; r++) {
            for(int c=curr_col-1; c<=curr_col+1; c++) {
                if(r < 0 || r >= rows || c < 0 || c >= cols) {
                    continue;
                }
                if(visited[r][c] || grid[r][c] == '#') {
                    continue;
                }
                queue[++rear][0] = r;
                queue[rear][1] = c;
                visited[r][c] = 1;
                parent[r][c][0] = curr_row;
                parent[r][c][1] = curr_col;
            }
        }
    }
    if(!found) {
        printf("No Path Found!\n");
        return 0;
    }
    printf("Path Found!\n");
    int path[100][2], path_len = 0;
    int curr_row = end_row, curr_col = end_col;
    while(curr_row != -1 && curr_col != -1) {
        path[path_len][0] = curr_row;
        path[path_len][1] = curr_col;
        path_len++;
        int old_row = curr_row;
        curr_row = parent[old_row][curr_col][0];
        curr_col = parent[old_row][curr_col][1];
    }
    printf("The Path is:\n");
    for(int i=path_len-1; i>=0; i--) {
        printf("(%d, %d)\n", path[i][0], path[i][1]);
    }
    return 0;
}