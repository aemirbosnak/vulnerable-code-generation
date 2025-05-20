//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAZE_SIZE 100
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

typedef struct {
    int x;
    int y;
} Point;

char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
int maze_size;
Point start_point;
Point end_point;

int is_valid_move(Point point) {
    return point.x >= 0 && point.x < maze_size && point.y >= 0 && point.y < maze_size && maze[point.x][point.y] != WALL;
}

int find_path(Point current_point) {
    if (current_point.x == end_point.x && current_point.y == end_point.y) {
        return 1;
    }

    maze[current_point.x][current_point.y] = WALL;

    Point neighbors[] = {
        {current_point.x - 1, current_point.y},
        {current_point.x + 1, current_point.y},
        {current_point.x, current_point.y - 1},
        {current_point.x, current_point.y + 1}
    };

    for (int i = 0; i < 4; i++) {
        if (is_valid_move(neighbors[i])) {
            if (find_path(neighbors[i])) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    printf("Enter the size of the maze: ");
    scanf("%d", &maze_size);

    printf("Enter the maze: ");
    for (int i = 0; i < maze_size; i++) {
        scanf("%s", maze[i]);
    }

    printf("Enter the starting point: ");
    scanf("%d %d", &start_point.x, &start_point.y);

    printf("Enter the ending point: ");
    scanf("%d %d", &end_point.x, &end_point.y);

    if (find_path(start_point)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}