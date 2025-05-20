//Code Llama-13B DATASET v1.0 Category: Pathfinding algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    int y;
    struct node* parent;
};

struct node* create_node(int x, int y, struct node* parent) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->x = x;
    new_node->y = y;
    new_node->parent = parent;
    return new_node;
}

int is_goal(struct node* node, int goal_x, int goal_y) {
    return node->x == goal_x && node->y == goal_y;
}

int get_manhattan_distance(struct node* node, int goal_x, int goal_y) {
    return abs(goal_x - node->x) + abs(goal_y - node->y);
}

struct node* find_path(struct node* start, int goal_x, int goal_y) {
    struct node* current = start;
    while (!is_goal(current, goal_x, goal_y)) {
        int min_distance = 9999;
        struct node* next = NULL;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                int new_x = current->x + x;
                int new_y = current->y + y;
                if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10) {
                    struct node* new_node = create_node(new_x, new_y, current);
                    int distance = get_manhattan_distance(new_node, goal_x, goal_y);
                    if (distance < min_distance) {
                        min_distance = distance;
                        next = new_node;
                    }
                }
            }
        }
        current = next;
    }
    return current;
}

int main() {
    struct node* start = create_node(0, 0, NULL);
    struct node* goal = create_node(9, 9, NULL);
    struct node* path = find_path(start, goal->x, goal->y);
    while (path != NULL) {
        printf("(%d, %d) -> ", path->x, path->y);
        path = path->parent;
    }
    printf("(%d, %d)\n", start->x, start->y);
    return 0;
}