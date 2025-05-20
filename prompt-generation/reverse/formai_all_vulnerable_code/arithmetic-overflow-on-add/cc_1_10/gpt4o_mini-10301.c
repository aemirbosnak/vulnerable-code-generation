//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define COST_STRAIGHT 1
#define COST_DIAGONAL 14

typedef struct {
    int x, y;   // Position on the grid
    int g;      // Cost from start
    int h;      // Heuristic cost to end
    int f;      // Total cost
    struct Node *parent; // Pointer to previous node
} Node;

Node* create_node(int x, int y, Node *parent) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    node->parent = parent;
    return node;
}

void free_node(Node *node) {
    free(node);
}

int calculate_heuristic(Node *a, Node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void add_to_open(Node **open_list, Node *node, int *open_count) {
    open_list[*open_count] = node;
    (*open_count)++;
}

bool is_in_list(Node **list, int count, Node *node) {
    for (int i = 0; i < count; i++) {
        if (list[i]->x == node->x && list[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

void reconstruct_path(Node *current) {
    while (current != NULL) {
        printf("(%d, %d) <- ", current->x, current->y);
        current = current->parent;
    }
    printf("Start\n");
}

void a_star(Node *start, Node *end) {
    Node *open_list[WIDTH * HEIGHT];
    int open_count = 0;
    bool closed[WIDTH][HEIGHT] = {false};

    add_to_open(open_list, start, &open_count);

    while (open_count > 0) {
        // Find node with lowest f in open list
        int lowest_index = 0;
        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->f < open_list[lowest_index]->f) {
                lowest_index = i;
            }
        }

        Node *current = open_list[lowest_index];

        // Check if we reached the end
        if (current->x == end->x && current->y == end->y) {
            printf("Path Found: ");
            reconstruct_path(current);
            return;
        }

        // Remove current from open list
        open_count--;
        for (int i = lowest_index; i < open_count; i++) {
            open_list[i] = open_list[i + 1];
        }

        closed[current->x][current->y] = true;

        // Check neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;

                if (abs(dx) == abs(dy)) { // Diagonal
                    if (current->x + dx < 0 || current->x + dx >= WIDTH ||
                        current->y + dy < 0 || current->y + dy >= HEIGHT) continue; // Out of bounds
                    if (closed[current->x + dx][current->y + dy]) continue; // Already closed

                    Node *neighbor = create_node(current->x + dx, current->y + dy, current);
                    neighbor->g = current->g + COST_DIAGONAL;
                    neighbor->h = calculate_heuristic(neighbor, end);
                    neighbor->f = neighbor->g + neighbor->h;

                    if (is_in_list(open_list, open_count, neighbor)) {
                        free_node(neighbor); // Not adding to open list
                        continue; // Already in open list
                    }

                    add_to_open(open_list, neighbor, &open_count);
                } else { // Straight
                    if (current->x + dx < 0 || current->x + dx >= WIDTH ||
                        current->y + dy < 0 || current->y + dy >= HEIGHT) continue;
                    if (closed[current->x + dx][current->y + dy]) continue;

                    Node *neighbor = create_node(current->x + dx, current->y + dy, current);
                    neighbor->g = current->g + COST_STRAIGHT;
                    neighbor->h = calculate_heuristic(neighbor, end);
                    neighbor->f = neighbor->g + neighbor->h;

                    if (is_in_list(open_list, open_count, neighbor)) {
                        free_node(neighbor);
                        continue;
                    }

                    add_to_open(open_list, neighbor, &open_count);
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    Node *start = create_node(0, 0, NULL);
    Node *end = create_node(7, 7, NULL);
    a_star(start, end);

    free_node(start);
    free_node(end);

    return 0;
}