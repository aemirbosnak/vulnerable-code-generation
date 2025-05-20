//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    int y;
    struct Node* parent;
};

struct Maze {
    int width;
    int height;
    int** grid;
};

void printMaze(struct Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->grid[i][j]);
        }
        printf("\n");
    }
}

int isValid(struct Maze* maze, struct Node* node) {
    return node->x >= 0 && node->x < maze->width && node->y >= 0 && node->y < maze->height && maze->grid[node->y][node->x] != 0;
}

struct Node* findPath(struct Maze* maze, struct Node* start, struct Node* end) {
    struct Node* current = start;
    while (current != end) {
        if (isValid(maze, current)) {
            current->parent = current;
            current = current->parent;
        } else {
            return NULL;
        }
    }
    return current;
}

int main() {
    struct Maze maze = {3, 3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}};
    struct Node start = {0, 0, NULL};
    struct Node end = {2, 2, NULL};
    struct Node* path = findPath(&maze, &start, &end);
    if (path) {
        printMaze(&maze);
        printf("Path: ");
        while (path) {
            printf("(%d, %d) ", path->x, path->y);
            path = path->parent;
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }
    return 0;
}