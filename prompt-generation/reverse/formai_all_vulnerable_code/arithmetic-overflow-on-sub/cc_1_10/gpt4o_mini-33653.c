//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct Node {
    Position pos;
    int g; // Cost from start to this node
    int h; // Heuristic cost from this node to end
    int f; // Total cost
    struct Node* parent;
} Node;

char grid[GRID_WIDTH][GRID_HEIGHT] = {
    {'S', '0', '0', '0', '0', '1', '0', '0', '0', '0'},
    {'1', '1', '1', '1', '0', '1', '1', '1', '1', '0'},
    {'0', '0', '0', '1', '0', '0', '0', '1', '0', '0'},
    {'0', '1', '1', '1', '1', '0', '1', '1', '1', '0'},
    {'0', '0', '0', '0', '8', '0', '0', '0', '0', '0'},
    {'0', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0', '1', '0'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '1', '1', '1', '1', '1', '0', 'E'}
};

Node* create_node(Position pos, Node* parent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->pos = pos;
    new_node->parent = parent;
    new_node->g = (parent) ? parent->g + 1 : 0;
    new_node->h = abs(pos.x - 9) + abs(pos.y - 9); // Manhattan distance to the endpoint
    new_node->f = new_node->g + new_node->h;
    return new_node;
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT && (grid[x][y] == '0' || grid[x][y] == 'E'));
}

Node* find_path(Position start, Position end) {
    Node* open_list[GRID_WIDTH * GRID_HEIGHT];
    int open_count = 0;
    Node* closed_list[GRID_WIDTH * GRID_HEIGHT];
    int closed_count = 0;

    open_list[open_count++] = create_node(start, NULL);

    while (open_count > 0) {
        int lowest_index = 0;
        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->f < open_list[lowest_index]->f) {
                lowest_index = i;
            }
        }

        Node* current_node = open_list[lowest_index];

        if (current_node->pos.x == end.x && current_node->pos.y == end.y) {
            return current_node; // Path found
        }

        // Move current node to closed list
        closed_list[closed_count++] = current_node;
        open_count--;
        for (int i = lowest_index; i < open_count; i++) {
            open_list[i] = open_list[i + 1];
        }

        // Explore neighbors
        Position neighbors[4] = {{current_node->pos.x + 1, current_node->pos.y}, {current_node->pos.x - 1, current_node->pos.y},
                                 {current_node->pos.x, current_node->pos.y + 1}, {current_node->pos.x, current_node->pos.y - 1}};
        for (int i = 0; i < 4; i++) {
            Position neighbor_pos = neighbors[i];
            if (!is_valid(neighbor_pos.x, neighbor_pos.y)) {
                continue;
            }

            bool in_closed_list = false;
            for (int j = 0; j < closed_count; j++) {
                if (closed_list[j]->pos.x == neighbor_pos.x && closed_list[j]->pos.y == neighbor_pos.y) {
                    in_closed_list = true;
                    break;
                }
            }
            if (in_closed_list) {
                continue;
            }

            Node* neighbor_node = create_node(neighbor_pos, current_node);

            bool in_open_list = false;
            for (int j = 0; j < open_count; j++) {
                if (open_list[j]->pos.x == neighbor_node->pos.x && open_list[j]->pos.y == neighbor_node->pos.y) {
                    in_open_list = true;
                    if (neighbor_node->g < open_list[j]->g) {
                        open_list[j]->g = neighbor_node->g;
                        open_list[j]->parent = neighbor_node->parent;
                    }
                    break;
                }
            }

            if (!in_open_list) {
                open_list[open_count++] = neighbor_node;
            } else {
                free(neighbor_node); // Don't leak memory
            }
        }
    }
    return NULL; // Path not found
}

void print_path(Node* node) {
    if (node == NULL) return;
    print_path(node->parent);
    if (grid[node->pos.x][node->pos.y] != 'S' && grid[node->pos.x][node->pos.y] != 'E') {
        grid[node->pos.x][node->pos.y] = '*'; // Mark path
    }
}

int main() {
    Position start = {0, 0};
    Position end = {9, 9};

    Node* path_node = find_path(start, end);
    if (path_node) {
        print_path(path_node);
        grid[start.x][start.y] = 'S'; // Sanity check
        grid[end.x][end.y] = 'E'; // Sanity check
    } else {
        printf("No path found.\n");
    }

    // Print grid
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            printf("%c ", grid[x][y]);
        }
        printf("\n");
    }

    // Free allocated memory
    while (path_node) {
        Node* temp = path_node;
        path_node = path_node->parent;
        free(temp);
    }

    return 0;
}