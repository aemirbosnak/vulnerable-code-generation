//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAP_WIDTH  10
#define MAP_HEIGHT 10

#define START_X     0
#define START_Y     0
#define GOAL_X     9
#define GOAL_Y     9

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int g_score;
    int h_score;
    int f_score;
    struct Node *parent;
} Node;

typedef struct {
    Node *nodes[MAP_WIDTH * MAP_HEIGHT];
    int size;
} PriorityQueue;

Node *create_node(Position position, int g_score, int h_score) {
    Node *node = malloc(sizeof(Node));
    node->position = position;
    node->g_score = g_score;
    node->h_score = h_score;
    node->f_score = g_score + h_score;
    node->parent = NULL;
    return node;
}

PriorityQueue *create_priority_queue() {
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->size = 0;
    return queue;
}

void insert_node(PriorityQueue *queue, Node *node) {
    int i;
    for (i = queue->size; i > 0; i--) {
        if (node->f_score < queue->nodes[i - 1]->f_score) {
            queue->nodes[i] = queue->nodes[i - 1];
        } else {
            break;
        }
    }
    queue->nodes[i] = node;
    queue->size++;
}

Node *pop_node(PriorityQueue *queue) {
    Node *node = queue->nodes[queue->size - 1];
    queue->size--;
    return node;
}

int is_valid_position(Position position) {
    return position.x >= 0 && position.x < MAP_WIDTH && position.y >= 0 && position.y < MAP_HEIGHT;
}

int is_obstacle(Position position) {
    return position.x == 3 && position.y == 3;
}

int calculate_h_score(Position position) {
    int dx = abs(position.x - GOAL_X);
    int dy = abs(position.y - GOAL_Y);
    return dx + dy;
}

Node *a_star_search(Position start, Position goal) {
    PriorityQueue *open_set = create_priority_queue();
    Node *start_node = create_node(start, 0, calculate_h_score(start));
    insert_node(open_set, start_node);
    while (open_set->size > 0) {
        Node *current_node = pop_node(open_set);
        if (current_node->position.x == goal.x && current_node->position.y == goal.y) {
            return current_node;
        }
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                Position соседняя_позиция = { current_node->position.x + dx, current_node->position.y + dy };
                if (is_valid_position(соседняя_позиция) && !is_obstacle(соседняя_позиция)) {
                    int tentative_g_score = current_node->g_score + 1;
                    Node *соседний_узел = create_node(соседняя_позиция, tentative_g_score, calculate_h_score(соседняя_позиция));
                    соседний_узел->parent = current_node;
                    insert_node(open_set, соседний_узел);
                }
            }
        }
    }
    return NULL;
}

void print_path(Node *node) {
    if (node == NULL) {
        printf("No path found.\n");
    } else {
        printf("Path:\n");
        while (node != NULL) {
            printf("(%d, %d)\n", node->position.x, node->position.y);
            node = node->parent;
        }
    }
}

int main() {
    Position start = { START_X, START_Y };
    Position goal = { GOAL_X, GOAL_Y };
    Node *path = a_star_search(start, goal);
    print_path(path);
    return 0;
}