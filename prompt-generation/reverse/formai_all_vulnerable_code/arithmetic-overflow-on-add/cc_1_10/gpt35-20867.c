//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 8

typedef struct node {
    int x, y;
    int f, g, h;
    struct node* parent;
} Node;

int grid[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

Node* create_node(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    return node;
}

void print_path(Node* node) {
    if (node->parent) {
        print_path(node->parent);
    }
    printf("(%d,%d)\n", node->x, node->y);
}

int calculate_h(int x, int y, int end_x, int end_y) {
    return abs(x - end_x) + abs(y - end_y);
}

Node* get_neighbor(Node* node, int dx, int dy, int end_x, int end_y) {
    int x = node->x + dx;
    int y = node->y + dy;
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] == 0) {
        Node* neighbor = create_node(x, y);
        neighbor->parent = node;
        neighbor->g = node->g + 1;
        neighbor->h = calculate_h(x, y, end_x, end_y);
        neighbor->f = neighbor->g + neighbor->h;
        return neighbor;
    }
    return NULL;
}

void a_star(int start_x, int start_y, int end_x, int end_y) {
    Node* start = create_node(start_x, start_y);
    start->f = 0;
    start->g = 0;
    start->h = 0;

    Node* open_list[ROWS * COLS];
    Node* closed_list[ROWS * COLS];
    int open_size = 1;
    int closed_size = 0;
    open_list[0] = start;

    while (open_size > 0) {
        Node* current = open_list[0];

        if (current->x == end_x && current->y == end_y) {
            print_path(current);
            return;
        }

        for (int i = 0; i < open_size - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        open_size--;

        closed_list[closed_size++] = current;

        Node* neighbors[8];
        neighbors[0] = get_neighbor(current, -1, -1, end_x, end_y);
        neighbors[1] = get_neighbor(current, -1, 0, end_x, end_y);
        neighbors[2] = get_neighbor(current, -1, 1, end_x, end_y);
        neighbors[3] = get_neighbor(current, 0, -1, end_x, end_y);
        neighbors[4] = get_neighbor(current, 0, 1, end_x, end_y);
        neighbors[5] = get_neighbor(current, 1, -1, end_x, end_y);
        neighbors[6] = get_neighbor(current, 1, 0, end_x, end_y);
        neighbors[7] = get_neighbor(current, 1, 1, end_x, end_y);

        for (int i = 0; i < 8; i++) {
            if (neighbors[i] != NULL) {

                int in_closed = 0;
                for (int j = 0; j < closed_size; j++) {
                    if (neighbors[i]->x == closed_list[j]->x && neighbors[i]->y == closed_list[j]->y) {
                        in_closed = 1;
                        break;
                    }
                }
                if (in_closed) {
                    continue;
                }

                int in_open = 0;
                for (int j = 0; j < open_size; j++) {
                    if (neighbors[i]->x == open_list[j]->x && neighbors[i]->y == open_list[j]->y) {
                        in_open = 1;
                        if (neighbors[i]->f < open_list[j]->f) {
                            open_list[j] = neighbors[i];
                        }
                        break;
                    }
                }
                if (in_open) {
                    continue;
                }

                open_list[open_size++] = neighbors[i];
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    a_star(1, 1, 3, 6);
    return 0;
}