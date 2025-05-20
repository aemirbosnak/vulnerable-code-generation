//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int x;
    int y;
    int cost;
    struct Node* parent;
};

// Function to calculate the heuristic cost of a node
int heuristic(int x, int y, int goal_x, int goal_y) {
    return abs(x - goal_x) + abs(y - goal_y);
}

// Function to add a node to the open list
void add_to_open_list(struct Node* node, struct Node** open_list, int* open_list_size) {
    open_list[(*open_list_size)++] = node;
}

// Function to remove the node with the lowest cost from the open list
struct Node* remove_from_open_list(struct Node** open_list, int* open_list_size) {
    int lowest_cost = 10000;
    int lowest_cost_index = -1;
    for (int i = 0; i < *open_list_size; i++) {
        if (open_list[i]->cost < lowest_cost) {
            lowest_cost = open_list[i]->cost;
            lowest_cost_index = i;
        }
    }
    struct Node* node = open_list[lowest_cost_index];
    open_list[lowest_cost_index] = open_list[(*open_list_size) - 1];
    (*open_list_size)--;
    return node;
}

// Function to check if a node is in the closed list
int in_closed_list(struct Node* node, struct Node** closed_list, int closed_list_size) {
    for (int i = 0; i < closed_list_size; i++) {
        if (closed_list[i]->x == node->x && closed_list[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a node is in the open list
int in_open_list(struct Node* node, struct Node** open_list, int open_list_size) {
    for (int i = 0; i < open_list_size; i++) {
        if (open_list[i]->x == node->x && open_list[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// Function to find the path from the start node to the goal node
struct Node* find_path(struct Node* start, struct Node* goal) {
    struct Node* open_list[1000];
    int open_list_size = 0;
    struct Node* closed_list[1000];
    int closed_list_size = 0;

    add_to_open_list(start, open_list, &open_list_size);

    while (open_list_size > 0) {
        struct Node* current = remove_from_open_list(open_list, &open_list_size);
        if (current->x == goal->x && current->y == goal->y) {
            return current;
        }
        closed_list[closed_list_size++] = current;

        for (int i = 0; i < 8; i++) {
            int new_x = current->x + (i % 2 ? 1 : 0);
            int new_y = current->y + (i % 2 ? 0 : 1);
            if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
                struct Node* new_node = malloc(sizeof(struct Node));
                new_node->x = new_x;
                new_node->y = new_y;
                new_node->cost = current->cost + 1;
                new_node->parent = current;
                if (!in_closed_list(new_node, closed_list, closed_list_size)) {
                    if (!in_open_list(new_node, open_list, open_list_size)) {
                        add_to_open_list(new_node, open_list, &open_list_size);
                    } else if (new_node->cost < open_list[i]->cost) {
                        open_list[i]->cost = new_node->cost;
                        open_list[i]->parent = new_node->parent;
                    }
                }
            }
        }
    }

    return NULL;
}

int main() {
    struct Node start = {0, 0, 0, NULL};
    struct Node goal = {7, 7, 0, NULL};
    struct Node* path = find_path(&start, &goal);

    while (path != NULL) {
        printf("(%d, %d) ", path->x, path->y);
        path = path->parent;
    }

    return 0;
}