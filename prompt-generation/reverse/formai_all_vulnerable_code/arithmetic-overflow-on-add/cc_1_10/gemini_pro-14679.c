//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point p;
    int g, h;
    struct node *parent;
} node;

typedef struct {
    int size;
    node **nodes;
} priority_queue;

priority_queue *priority_queue_new(int size) {
    priority_queue *pq = malloc(sizeof(priority_queue));
    pq->size = size;
    pq->nodes = malloc(sizeof(node *) * size);
    return pq;
}

void priority_queue_free(priority_queue *pq) {
    free(pq->nodes);
    free(pq);
}

void priority_queue_push(priority_queue *pq, node *n) {
    int i;
    for (i = 0; i < pq->size; i++) {
        if (pq->nodes[i] == NULL || n->g + n->h < pq->nodes[i]->g + pq->nodes[i]->h) {
            break;
        }
    }
    for (int j = pq->size - 1; j > i; j--) {
        pq->nodes[j] = pq->nodes[j - 1];
    }
    pq->nodes[i] = n;
}

node *priority_queue_pop(priority_queue *pq) {
    node *n = pq->nodes[0];
    for (int i = 1; i < pq->size; i++) {
        pq->nodes[i - 1] = pq->nodes[i];
    }
    pq->nodes[pq->size - 1] = NULL;
    return n;
}

int priority_queue_empty(priority_queue *pq) {
    return pq->nodes[0] == NULL;
}

int main(int argc, char **argv) {
    int width, height;
    scanf("%d %d", &width, &height);

    int **grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    point start, end;
    scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);

    node *start_node = malloc(sizeof(node));
    start_node->p = start;
    start_node->g = 0;
    start_node->h = abs(end.x - start.x) + abs(end.y - start.y);
    start_node->parent = NULL;

    priority_queue *pq = priority_queue_new(width * height);
    priority_queue_push(pq, start_node);

    while (!priority_queue_empty(pq)) {
        node *current = priority_queue_pop(pq);

        if (current->p.x == end.x && current->p.y == end.y) {
            break;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int x = current->p.x + i;
                int y = current->p.y + j;

                if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x] == 0) {
                    node *neighbor = malloc(sizeof(node));
                    neighbor->p.x = x;
                    neighbor->p.y = y;
                    neighbor->g = current->g + 1;
                    neighbor->h = abs(end.x - x) + abs(end.y - y);
                    neighbor->parent = current;

                    priority_queue_push(pq, neighbor);
                }
            }
        }
    }

    if (priority_queue_empty(pq)) {
        printf("No path found.\n");
    } else {
        node *n = priority_queue_pop(pq);
        while (n != NULL) {
            printf("(%d, %d)\n", n->p.x, n->p.y);
            n = n->parent;
        }
    }

    priority_queue_free(pq);
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}