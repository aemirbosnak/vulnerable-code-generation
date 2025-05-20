//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int x;
    int y;
    int cost;
    bool visited;
    struct node* next;
} node;

bool is_valid(node* node, int size) {
    return (node->x >= 0 && node->x < size && node->y >= 0 && node->y < size);
}

node* create_node(int x, int y, int cost) {
    node* new_node = malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->cost = cost;
    new_node->visited = false;
    new_node->next = NULL;
    return new_node;
}

void enqueue(node** head, int x, int y, int cost) {
    node* new_node = create_node(x, y, cost);
    new_node->next = *head;
    *head = new_node;
}

void dequeue(node** head) {
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int bfs(node* start, node* goal, int size) {
    node* queue = NULL;
    node* visited = NULL;
    int num_moves = 0;
    node* current = NULL;

    enqueue(&queue, start->x, start->y, 0);

    while (queue!= NULL) {
        current = queue;
        queue = queue->next;

        if (current->x == goal->x && current->y == goal->y) {
            return num_moves;
        }

        if (current->visited) {
            continue;
        }

        current->visited = true;

        int moves = 0;

        if (current->x > 0 && is_valid(current->next, size)) {
            moves += current->next->cost;
            enqueue(&queue, current->next->x, current->next->y, current->next->cost);
        }

        if (current->x < size - 1 && is_valid(current->next, size)) {
            moves += current->next->cost;
            enqueue(&queue, current->next->x, current->next->y, current->next->cost);
        }

        if (current->y > 0 && is_valid(current->next, size)) {
            moves += current->next->cost;
            enqueue(&queue, current->next->x, current->next->y, current->next->cost);
        }

        if (current->y < size - 1 && is_valid(current->next, size)) {
            moves += current->next->cost;
            enqueue(&queue, current->next->x, current->next->y, current->next->cost);
        }

        num_moves += moves;
    }

    return -1;
}

int main() {
    int size = MAX_SIZE;
    int start_x = 0;
    int start_y = 0;
    int goal_x = size - 1;
    int goal_y = size - 1;

    node* start = create_node(start_x, start_y, 0);
    node* goal = create_node(goal_x, goal_y, 0);

    int moves = bfs(start, goal, size);

    printf("Path found: %d moves\n", moves);

    return 0;
}