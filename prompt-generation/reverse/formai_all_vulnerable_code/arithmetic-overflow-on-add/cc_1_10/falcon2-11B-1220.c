//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int width;
    int height;
    char** maze;
} Maze;

Maze* create_maze(int width, int height) {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    if (maze == NULL) {
        printf("Error: Failed to allocate memory for maze.\n");
        return NULL;
    }
    maze->width = width;
    maze->height = height;
    maze->maze = (char**)malloc(height * sizeof(char*));
    if (maze->maze == NULL) {
        free(maze);
        printf("Error: Failed to allocate memory for maze.\n");
        return NULL;
    }
    for (int i = 0; i < height; i++) {
        maze->maze[i] = (char*)malloc((width + 1) * sizeof(char));
        if (maze->maze[i] == NULL) {
            free(maze->maze);
            free(maze);
            printf("Error: Failed to allocate memory for maze.\n");
            return NULL;
        }
    }
    return maze;
}

void destroy_maze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

bool is_valid_move(int x, int y, Maze* maze) {
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
        return false;
    }
    if (maze->maze[y][x] == '#') {
        return false;
    }
    return true;
}

void generate_maze(Maze* maze) {
    int width = maze->width;
    int height = maze->height;
    char** maze_copy = (char**)malloc((height + 1) * sizeof(char*));
    if (maze_copy == NULL) {
        printf("Error: Failed to allocate memory for maze copy.\n");
        return;
    }
    for (int i = 0; i < height; i++) {
        maze_copy[i] = (char*)malloc((width + 1) * sizeof(char));
        if (maze_copy[i] == NULL) {
            free(maze_copy);
            printf("Error: Failed to allocate memory for maze copy.\n");
            return;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze_copy[i][j] = maze->maze[i][j];
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze_copy[i][j] == '.') {
                if (is_valid_move(j - 1, i, maze)) {
                    maze_copy[i][j - 1] = '#';
                    generate_maze(maze);
                }
                if (is_valid_move(j + 1, i, maze)) {
                    maze_copy[i][j + 1] = '#';
                    generate_maze(maze);
                }
                if (is_valid_move(j, i - 1, maze)) {
                    maze_copy[i - 1][j] = '#';
                    generate_maze(maze);
                }
                if (is_valid_move(j, i + 1, maze)) {
                    maze_copy[i + 1][j] = '#';
                    generate_maze(maze);
                }
            }
        }
    }
    for (int i = 0; i < height; i++) {
        free(maze_copy[i]);
    }
    free(maze_copy);
}

int main() {
    int width, height;
    printf("Enter the width and height of the maze: ");
    scanf("%d%d", &width, &height);
    Maze* maze = create_maze(width, height);
    if (maze == NULL) {
        return 1;
    }
    generate_maze(maze);
    printf("Maze generated successfully!\n");
    printf("Maze: ");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", maze->maze[i][j]);
        }
        printf("\n");
    }
    destroy_maze(maze);
    return 0;
}