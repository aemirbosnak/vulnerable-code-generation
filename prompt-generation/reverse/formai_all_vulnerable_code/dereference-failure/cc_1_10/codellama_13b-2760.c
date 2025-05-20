//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct node {
    int x;
    int y;
    int g;
    int h;
    struct node* parent;
} node;

node* create_node(int x, int y) {
    node* n = malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->g = 0;
    n->h = 0;
    n->parent = NULL;
    return n;
}

void destroy_node(node* n) {
    free(n);
}

void print_path(node* start, node* end) {
    node* current = end;
    while (current != start) {
        printf("(%d, %d) -> ", current->x, current->y);
        current = current->parent;
    }
    printf("(%d, %d)\n", start->x, start->y);
}

int heuristic(node* start, node* end) {
    int dx = end->x - start->x;
    int dy = end->y - start->y;
    return abs(dx) + abs(dy);
}

void a_star(node* start, node* end) {
    int closed[MAX_NODES][MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            closed[i][j] = 0;
        }
    }

    node* open[MAX_NODES];
    int open_size = 0;
    open[open_size++] = start;

    while (open_size > 0) {
        node* current = open[--open_size];

        if (current == end) {
            print_path(start, end);
            return;
        }

        closed[current->x][current->y] = 1;

        int x = current->x;
        int y = current->y;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int new_x = x + i;
                int new_y = y + j;

                if (new_x < 0 || new_x >= MAX_NODES || new_y < 0 || new_y >= MAX_NODES) {
                    continue;
                }

                if (closed[new_x][new_y]) {
                    continue;
                }

                int g = current->g + 1;
                int h = heuristic(current, end);

                if (g + h < open[open_size - 1]->g + open[open_size - 1]->h) {
                    node* new_node = create_node(new_x, new_y);
                    new_node->g = g;
                    new_node->h = h;
                    new_node->parent = current;

                    open[open_size++] = new_node;
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    node* start = create_node(0, 0);
    node* end = create_node(9, 9);

    a_star(start, end);

    destroy_node(start);
    destroy_node(end);

    return 0;
}