//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

int start_row, start_col;
int end_row, end_col;

int maze[ROWS][COLS] = {
    {1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0},
    {1, 1, 1, 1, 1}
};

int visited[ROWS][COLS] = {0};
int path[ROWS][COLS] = {0};

bool found_end = false;

void dfs(int row, int col){
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) return;
    if(maze[row][col] == 0) return;
    if(visited[row][col] == 1) return;
    if(found_end) return;

    visited[row][col] = 1;
    path[row][col] = 1;

    if(row == end_row && col == end_col){
        found_end = true;
        return;
    }

    dfs(row+1, col);
    if(found_end) return;
    dfs(row-1, col);
    if(found_end) return;
    dfs(row, col+1);
    if(found_end) return;
    dfs(row, col-1);

    if(!found_end){
        path[row][col] = 0;
    }

}

int main(){

    printf("Select Starting point (row column): ");
    scanf("%d %d", &start_row, &start_col);

    printf("Select Ending point (row column): ");
    scanf("%d %d", &end_row, &end_col);

    dfs(start_row, start_col);

    if(found_end){
        printf("Path found!\n");
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(path[i][j] == 1){
                    printf("# ");
                }else{
                    printf("%d ", maze[i][j]);
                }
            }
            printf("\n");
        }

    }else{
        printf("No Path Found!\n");
    }

    return 0;
}