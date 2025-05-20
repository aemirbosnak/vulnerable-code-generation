//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int x;
    int y;
    int direction;
    int visited;
};

int maze_size;

void generate_maze() {
    struct Node *maze = (struct Node*)malloc(maze_size * sizeof(struct Node));
    
    for (int i = 0; i < maze_size; i++) {
        for (int j = 0; j < maze_size; j++) {
            maze[i*maze_size+j].x = i;
            maze[i*maze_size+j].y = j;
            maze[i*maze_size+j].direction = 0;
            maze[i*maze_size+j].visited = 0;
        }
    }
    
    for (int i = 0; i < maze_size; i++) {
        for (int j = 0; j < maze_size; j++) {
            int current_node = i*maze_size+j;
            int x_min = -1;
            int y_min = -1;
            int x_max = -1;
            int y_max = -1;
            
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int temp_x = i + k;
                    int temp_y = j + l;
                    
                    if (temp_x >= 0 && temp_y >= 0 && temp_x < maze_size && temp_y < maze_size) {
                        if (maze[temp_x*maze_size+temp_y].direction == 0) {
                            if (maze[temp_x*maze_size+temp_y].visited == 0) {
                                if (maze[i*maze_size+j].x > maze[temp_x*maze_size+temp_y].x) {
                                    x_max = maze[i*maze_size+j].x;
                                }
                                if (maze[i*maze_size+j].x < maze[temp_x*maze_size+temp_y].x) {
                                    x_min = maze[i*maze_size+j].x;
                                }
                                if (maze[i*maze_size+j].y > maze[temp_x*maze_size+temp_y].y) {
                                    y_max = maze[i*maze_size+j].y;
                                }
                                if (maze[i*maze_size+j].y < maze[temp_x*maze_size+temp_y].y) {
                                    y_min = maze[i*maze_size+j].y;
                                }
                            }
                        }
                    }
                }
            }
            
            if (x_min == -1 || y_min == -1 || x_max == -1 || y_max == -1) {
                continue;
            }
            
            maze[i*maze_size+j].direction = 2;
            maze[i*maze_size+j].visited = 1;
            
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int temp_x = i + k;
                    int temp_y = j + l;
                    
                    if (temp_x >= 0 && temp_y >= 0 && temp_x < maze_size && temp_y < maze_size) {
                        if (maze[temp_x*maze_size+temp_y].direction == 0) {
                            if (maze[temp_x*maze_size+temp_y].visited == 0) {
                                maze[temp_x*maze_size+temp_y].direction = 2;
                                maze[temp_x*maze_size+temp_y].visited = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void print_maze(struct Node *maze) {
    for (int i = 0; i < maze_size; i++) {
        for (int j = 0; j < maze_size; j++) {
            if (maze[i*maze_size+j].direction == 0) {
                printf(".");
            } else if (maze[i*maze_size+j].direction == 1) {
                printf("^");
            } else if (maze[i*maze_size+j].direction == 2) {
                printf("v");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    maze_size = 10;
    
    struct Node *maze = (struct Node*)malloc(maze_size * sizeof(struct Node));
    
    generate_maze();
    print_maze(maze);
    
    return 0;
}