//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 1000000000

struct node {
    int x;
    int y;
    int g;
    int h;
};

struct node *createNode(int x, int y, int g, int h) {
    struct node *node = malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Error: Unable to allocate memory\n");
        return NULL;
    }
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    return node;
}

void freeNode(struct node *node) {
    free(node);
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void printNode(struct node *node) {
    printf("(%d, %d) ", node->x, node->y);
}

int main() {
    struct node *start = createNode(0, 0, 0, 0);
    struct node *goal = createNode(5, 5, 0, 0);

    struct node *openSet[100];
    int openSetSize = 0;
    struct node *closedSet[100];
    int closedSetSize = 0;

    start->g = 0;
    start->h = heuristic(start->x, start->y, goal->x, goal->y);
    openSet[openSetSize++] = start;

    while (openSetSize > 0) {
        struct node *current = openSet[0];
        openSet[0] = openSet[--openSetSize];

        printf("Current node: ");
        printNode(current);

        if (current == goal) {
            printf("Goal reached!\n");
            break;
        }

        int i, j;
        for (i = -1; i < 2; i++) {
            for (j = -1; j < 2; j++) {
                int newX = current->x + i;
                int newY = current->y + j;

                if (newX < 0 || newX >= 10 || newY < 0 || newY >= 10) {
                    continue;
                }

                struct node *neighbor = createNode(newX, newY, current->g + 1, current->h + abs(i + j));

                if (closedSet[newX + 10 * newY]!= NULL) {
                    continue;
                }

                if (neighbor->g > openSet[0]->g) {
                    continue;
                }

                if (openSet[0]->g == neighbor->g && neighbor->h < openSet[0]->h) {
                    continue;
                }

                openSet[openSetSize++] = neighbor;
                closedSet[newX + 10 * newY] = neighbor;
            }
        }

        printf("Closed set size: %d\n", closedSetSize);
    }

    return 0;
}