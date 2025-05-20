//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

int maze[100][100];
int n;

int main() {
    srand(time(NULL));
    
    int i, j;
    int start[2];
    int end[2];
    int visited[100][100];
    
    printf("Enter the size of the maze: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            maze[i][j] = rand() % 2;
            visited[i][j] = 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (maze[i][j] == 1) {
                start[0] = i;
                start[1] = j;
            } else if (maze[i][j] == 0) {
                end[0] = i;
                end[1] = j;
            }
        }
    }
    
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int cost[4][2] = {2, 1, 1, 2};
    int path[100][100];
    
    Point start_pt;
    Point end_pt;
    int cost_so_far[100][100];
    
    start_pt.x = start[0];
    start_pt.y = start[1];
    end_pt.x = end[0];
    end_pt.y = end[1];
    
    cost_so_far[start[0]][start[1]] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cost_so_far[i][j] = 1000000000;
        }
    }
    
    path[start[0]][start[1]] = 0;
    
    while (1) {
        Point curr_pt;
        int min_cost = 1000000000;
        int min_cost_dir = 0;
        
        for (i = 0; i < 4; i++) {
            int x_diff = end_pt.x - curr_pt.x;
            int y_diff = end_pt.y - curr_pt.y;
            
            if (x_diff == 0 && y_diff == 0) {
                continue;
            }
            
            x_diff = x_diff * directions[i][0] - y_diff * directions[i][1];
            y_diff = y_diff * directions[i][0] + x_diff * directions[i][1];
            
            int cost_new = cost_so_far[curr_pt.x + x_diff][curr_pt.y + y_diff] + cost[i][0];
            
            if (cost_new < min_cost) {
                min_cost = cost_new;
                min_cost_dir = i;
            }
        }
        
        if (min_cost == 1000000000) {
            printf("No path found\n");
            break;
        }
        
        if (min_cost_dir == 0) {
            curr_pt.x += directions[min_cost_dir][0];
            curr_pt.y += directions[min_cost_dir][1];
        } else if (min_cost_dir == 1) {
            curr_pt.x += directions[min_cost_dir][0];
            curr_pt.y -= directions[min_cost_dir][1];
        } else if (min_cost_dir == 2) {
            curr_pt.x -= directions[min_cost_dir][0];
            curr_pt.y += directions[min_cost_dir][1];
        } else {
            curr_pt.x -= directions[min_cost_dir][0];
            curr_pt.y -= directions[min_cost_dir][1];
        }
        
        if (curr_pt.x == end_pt.x && curr_pt.y == end_pt.y) {
            printf("Path found!\n");
            printf("Shortest path: ");
            for (i = start[0]; i <= end[0]; i++) {
                for (j = start[1]; j <= end[1]; j++) {
                    if (path[i][j] == 0) {
                        printf("%d ", i);
                    }
                }
            }
            printf("\n");
            break;
        }
        
        if (maze[curr_pt.x][curr_pt.y] == 1) {
            cost_so_far[curr_pt.x][curr_pt.y] = min_cost;
            path[curr_pt.x][curr_pt.y] = min_cost_dir;
        }
    }
    
    return 0;
}