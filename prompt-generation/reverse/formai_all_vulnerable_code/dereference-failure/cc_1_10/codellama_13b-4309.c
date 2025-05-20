//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    int y;
    int g; // cost to reach the node from the starting point
    int h; // heuristic function: estimated cost to reach the goal from the node
    struct Node* parent;
};

struct Node* newNode(int x, int y) {
    struct Node* node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    return node;
}

void printPath(struct Node* node) {
    if (node->parent == NULL) {
        printf("Starting point: (%d, %d)\n", node->x, node->y);
    } else {
        printPath(node->parent);
        printf("(%d, %d) -> ", node->x, node->y);
    }
}

int main() {
    int n = 5; // number of nodes
    int m = 5; // number of edges
    struct Node** nodes = malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(i, i);
    }

    // construct the graph
    for (int i = 0; i < m; i++) {
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);
        nodes[x]->g = cost;
        nodes[x]->parent = nodes[y];
    }

    // start the search from the starting point
    struct Node* start = nodes[0];
    start->g = 0;
    start->h = 0;

    // while there are still nodes to explore
    while (1) {
        // find the node with the lowest estimated cost
        struct Node* current = NULL;
        int minCost = 10000;
        for (int i = 0; i < n; i++) {
            if (nodes[i]->g + nodes[i]->h < minCost) {
                minCost = nodes[i]->g + nodes[i]->h;
                current = nodes[i];
            }
        }

        // if the current node is the goal, return the path
        if (current->x == n - 1) {
            printPath(current);
            break;
        }

        // expand the current node
        for (int i = 0; i < n; i++) {
            if (nodes[i]->g == 0) {
                nodes[i]->g = current->g + 1;
                nodes[i]->h = abs(nodes[i]->x - n - 1) + abs(nodes[i]->y - n - 1);
                nodes[i]->parent = current;
            }
        }
    }

    // free the memory
    for (int i = 0; i < n; i++) {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}