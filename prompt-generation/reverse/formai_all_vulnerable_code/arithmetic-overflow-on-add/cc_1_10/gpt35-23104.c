//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cryptic
/*Cloaked in mystery, behold the pathfinding algorithm*/
#include<stdio.h>
#include<stdlib.h>

/*The grid is cunningly hidden*/
#define M 10
#define N 10

/*The map is encoded in this array*/
int map[M][N] = {
   {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
   {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
};

/*These are the co-ordinates of our start and end points*/
int startX = 0, startY = 0;
int endX = 9, endY = 9;

/*The nodes in our search are like ghosts in the night*/
struct node {
    int x;
    int y;
    int distance;
    struct node *parent;
};

/*Behold, the queue of nodes*/
struct queue {
    int size;
    struct node **nodes;
};

/*The night is dark and full of terrors, but our queue holds gallant nodes*/
void enqueue(struct queue *queue, struct node *node) {
    queue->nodes[++queue->size] = node;
}

/*We remove nodes from the queue when the morning star rises*/
struct node *dequeue(struct queue *queue) {
    int i;
    struct node *res = queue->nodes[1];
    for (i = 2; i <= queue->size; i++) {
        queue->nodes[i - 1] = queue->nodes[i];
    }
    queue->size--;
    return res;
}

/*Here, we shall walk the path that leads us to enlightenment*/
void printPath(struct node *end) {
    if (end->parent != NULL) {
        printPath(end->parent);
    }
    printf("(%d,%d) -> ", end->x, end->y);
}

/*Our algorithm is nimble and sure, it shall find the path to the end*/
void findPath() {
    struct queue *queue = (struct queue*) malloc(sizeof(struct queue));
    queue->size = 0;
    queue->nodes = (struct node**) malloc(sizeof(struct node*) * 100);
    struct node *start = (struct node*) malloc(sizeof(struct node));
    start->x = startX;
    start->y = startY;
    start->distance = 0;
    start->parent = NULL;
    enqueue(queue, start);

    /*The path traversal commences*/
    while (queue->size > 0) {
        struct node *currentNode = dequeue(queue);
        int x = currentNode->x;
        int y = currentNode->y;
        if (x == endX && y == endY) {
            printPath(currentNode);
            printf("(%d,%d)", endX, endY);
            printf("\n");
            return;
        }
        /*We shall check every direction for hidden paths*/
        if (x > 0 && map[x - 1][y] == 0) {
            struct node *n = (struct node*) malloc(sizeof(struct node));
            n->x = x - 1;
            n->y = y;
            n->distance = currentNode->distance + 1;
            n->parent = currentNode;
            enqueue(queue, n);
            map[x - 1][y] = 2;
        }
        if (x < M - 1 && map[x + 1][y] == 0) {
            struct node *n = (struct node*) malloc(sizeof(struct node));
            n->x = x + 1;
            n->y = y;
            n->distance = currentNode->distance + 1;
            n->parent = currentNode;
            enqueue(queue, n);
            map[x + 1][y] = 2;
        }
        if (y > 0 && map[x][y - 1] == 0) {
            struct node *n = (struct node*) malloc(sizeof(struct node));
            n->x = x;
            n->y = y - 1;
            n->distance = currentNode->distance + 1;
            n->parent = currentNode;
            enqueue(queue, n);
            map[x][y - 1] = 2;
        }
        if (y < N - 1 && map[x][y + 1] == 0) {
            struct node *n = (struct node*) malloc(sizeof(struct node));
            n->x = x;
            n->y = y + 1;
            n->distance = currentNode->distance + 1;
            n->parent = currentNode;
            enqueue(queue, n);
            map[x][y + 1] = 2;
        }
    }
}

/*Our client shall tell us when to traverse the path*/
int main() {
    findPath();
    return 0;
}