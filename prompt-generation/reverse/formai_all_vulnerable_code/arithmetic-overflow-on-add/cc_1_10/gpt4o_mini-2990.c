//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE '#'
#define PATH '.'
#define START 'S'
#define GOAL 'G'
#define EMPTY ' '

typedef struct {
    int x;
    int y;
    int g_cost; // Cost from start to current node
    int h_cost; // Heuristic cost from current to goal
    int f_cost; // Total cost: g_cost + h_cost
    struct Node* parent;
} Node;

typedef struct {
    Node* nodes[WIDTH * HEIGHT];
    int size;
} NodeList;

void initNodeList(NodeList* list) {
    list->size = 0;
}

void addNode(NodeList* list, Node* node) {
    list->nodes[list->size++] = node;
}

Node* removeLowestFCostNode(NodeList* list) {
    int lowestIndex = 0;
    for (int i = 1; i < list->size; i++) {
        if (list->nodes[i]->f_cost < list->nodes[lowestIndex]->f_cost) {
            lowestIndex = i;
        }
    }
    Node* lowestNode = list->nodes[lowestIndex];
    list->nodes[lowestIndex] = list->nodes[--list->size]; // Replace with last node
    return lowestNode;
}

bool contains(NodeList* list, Node* node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i]->x == node->x && list->nodes[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void reconstructPath(Node* node) {
    while (node != NULL) {
        printf("Path: (%d, %d)\n", node->x, node->y);
        node = node->parent;
    }
}

void aStar(char grid[HEIGHT][WIDTH], Node* start, Node* goal) {
    NodeList openSet, closedSet;
    initNodeList(&openSet);
    initNodeList(&closedSet);

    addNode(&openSet, start);

    while (openSet.size > 0) {
        Node* current = removeLowestFCostNode(&openSet);

        if (current->x == goal->x && current->y == goal->y) {
            reconstructPath(current);
            return;
        }

        addNode(&closedSet, current);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue; // Skip diagonal movements

                int nx = current->x + dx;
                int ny = current->y + dy;

                if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT ||
                    grid[ny][nx] == OBSTACLE || contains(&closedSet, &(Node){nx, ny, 0, 0, 0, NULL})) {
                    continue;
                }

                int gCost = current->g_cost + 1;
                Node* neighbor = &(Node){nx, ny, gCost, heuristic(&(Node){nx, ny, 0, 0, 0, NULL}, goal), 0, current};

                if (!contains(&openSet, neighbor) || gCost < neighbor->g_cost) {
                    neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;
                    if (!contains(&openSet, neighbor)) {
                        addNode(&openSet, neighbor);
                    }
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    char grid[HEIGHT][WIDTH] = {
        { 'S', EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY },
        { OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, OBSTACLE, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, OBSTACLE },
        { EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, OBSTACLE, EMPTY },
        { EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 'G' }
    };

    Node start = {0, 0, 0, heuristic(&(Node){0, 0, 0, 0, 0, NULL}, &(Node){9, 9, 0, 0, 0, NULL}), 0, NULL};
    Node goal = {9, 9, 0, 0, 0, NULL};

    aStar(grid, &start, &goal);
    return 0;
}