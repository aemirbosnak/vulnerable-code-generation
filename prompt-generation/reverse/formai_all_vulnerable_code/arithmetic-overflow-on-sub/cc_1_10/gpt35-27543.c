//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5
#define START_ROW 0
#define START_COL 0
#define END_ROW 4
#define END_COL 4

typedef struct node {
    int row, col, f, g, h;
    struct node* parent;
} Node;

Node* create_node(int row, int col, int f, int g, int h, Node* parent) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = f;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

void destroy_node(Node* node) {
    if (node != NULL) {
        free(node);
    }
}

bool is_valid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

bool is_obstacle(int row, int col) {
    // Assume random obstacles for now
    return rand() % 6 == 0;
}

int heuristic(int row, int col) {
    return abs(row - END_ROW) + abs(col - END_COL);
}

Node* get_lowest_f_node(Node** open_list, int open_size) {
    int lowest_f = open_list[0]->f;
    int lowest_i = 0;

    for (int i = 1; i < open_size; i++) {
        if (open_list[i]->f < lowest_f) {
            lowest_f = open_list[i]->f;
            lowest_i = i;
        }
    }

    return open_list[lowest_i];
}

bool node_in_list(Node** list, int list_size, Node* node) {
    for (int i = 0; i < list_size; i++) {
        Node* n = list[i];
        if (n->row == node->row && n->col == node->col) {
            return true;
        }
    }
    return false;
}

void add_to_list(Node** list, int* list_size, Node* node) {
    list[*list_size] = node;
    (*list_size)++;
}

void remove_from_list(Node** list, int* list_size, Node* node) {
    int index = -1;
    for (int i = 0; i < *list_size; i++) {
        Node* n = list[i];
        if (n->row == node->row && n->col == node->col) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Shift all elements after index to left
        for (int i = index; i < *list_size - 1; i++) {
            list[i] = list[i + 1];
        }
        (*list_size)--;
    }
}

void print_path(Node* end_node) {
    Node* node = end_node;
    while (node != NULL) {
        printf("(%d, %d) -> ", node->row, node->col);
        node = node->parent;
    }
    printf("\n");
}

void find_path() {
    Node* start_node = create_node(START_ROW, START_COL, 0, 0, heuristic(START_ROW, START_COL), NULL);
    Node** open_list = (Node**) malloc(sizeof(Node*) * ROWS * COLS);
    Node** closed_list = (Node**) malloc(sizeof(Node*) * ROWS * COLS);
    int open_size = 0;
    int closed_size = 0;
    add_to_list(open_list, &open_size, start_node);

    while (open_size > 0) {
        // Get node with lowest f value from open list
        Node* current_node = get_lowest_f_node(open_list, open_size);
        if (current_node->row == END_ROW && current_node->col == END_COL) {
            print_path(current_node);
            break;
        }

        // Move current node from open to closed list
        remove_from_list(open_list, &open_size, current_node);
        add_to_list(closed_list, &closed_size, current_node);

        // Check adjacent nodes
        int row = current_node->row;
        int col = current_node->col;
        int g = current_node->g + 1;

        for (int r = row - 1; r <= row + 1; r++) {
            for (int c = col - 1; c <= col + 1; c++) {
                if (is_valid(r, c) && !is_obstacle(r, c) && !(r == row && c == col)) {
                    Node* adjacent_node = create_node(r, c, 0, g, heuristic(r, c), current_node);

                    // Check if adjacent node is already in closed list
                    if (node_in_list(closed_list, closed_size, adjacent_node)) {
                        destroy_node(adjacent_node);
                        continue;
                    }

                    // Calculate f value for adjacent node
                    adjacent_node->f = adjacent_node->g + adjacent_node->h;

                    // Check if adjacent node is already in open list
                    Node* existing_node = NULL;
                    for (int i = 0; i < open_size; i++) {
                        Node* n = open_list[i];
                        if (n->row == adjacent_node->row && n->col == adjacent_node->col) {
                            existing_node = n;
                            break;
                        }
                    }

                    // If adjacent node is not in open list yet, add it to open list
                    // Else if its g value is lower using current path, update it
                    if (existing_node == NULL) {
                        add_to_list(open_list, &open_size, adjacent_node);
                    } else if (g < existing_node->g) {
                        existing_node->g = g;
                        existing_node->f = existing_node->g + existing_node->h;
                        existing_node->parent = current_node;
                        destroy_node(adjacent_node);
                    } else {
                        destroy_node(adjacent_node);
                    }
                }
            }
        }
    }

    // Free memory
    destroy_node(start_node);
    for (int i = 0; i < open_size; i++) {
        destroy_node(open_list[i]);
    }
    for (int i = 0; i < closed_size; i++) {
        destroy_node(closed_list[i]);
    }
    free(open_list);
    free(closed_list);
}

int main() {
    srand(time(NULL));
    find_path();
    return 0;
}