//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 20
#define MAX_COL 20

char maze[MAX_ROW][MAX_COL] = {
    ".#.#.",
    "...#.",
    ".#...",
    "...#.",
    ".###.",
};
int start_row = 0;
int start_col = 0;
int end_row = 4;
int end_col = 4;

typedef struct Coordinate {
    int x;
    int y;
    struct Coordinate* next;
} Coordinate;

Coordinate* create_coordinate(int x, int y) {
    Coordinate* coord = (Coordinate*)malloc(sizeof(Coordinate));
    coord->x = x;
    coord->y = y;
    coord->next = NULL;
}

void add_to_list(Coordinate* list, Coordinate* coord) {
    while (list->next != NULL) {
        list = list->next;
    }
    list->next = coord;
}

Coordinate* find_path(char maze[MAX_ROW][MAX_COL], int start_row, int start_col, int end_row, int end_col) {
    int visited[MAX_ROW][MAX_COL] = {0};
    int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    
    Coordinate* queue = create_coordinate(start_row, start_col);
    visited[start_row][start_col] = 1;
    
    while (queue != NULL) {
        Coordinate* current_coord = queue;
        queue = queue->next;
        
        for (int i=0; i<4; i++) {
            int next_row = current_coord->x + directions[i][0];
            int next_col = current_coord->y + directions[i][1];
            
            if (next_row >= 0 && next_row < MAX_ROW && next_col >= 0 && next_col < MAX_COL 
                && maze[next_row][next_col] == '.' && !visited[next_row][next_col]) {
                
                visited[next_row][next_col] = 1;
                Coordinate* next_coord = create_coordinate(next_row, next_col);
                next_coord->next = current_coord;
                add_to_list(queue, next_coord);
                
                if (next_row == end_row && next_col == end_col) {
                    return next_coord;
                }
            }
        }
    }
    return NULL;
}

void print_path(Coordinate* path) {
    while (path != NULL) {
        printf("(%d, %d) ", path->x, path->y);
        path = path->next;
    }
}

int main() {
    Coordinate* path = find_path(maze, start_row, start_col, end_row, end_col);
    printf("Finding the route...\n\n");
    print_path(path);
    printf("\n\nRoute found successfully!");
    return 0;
}