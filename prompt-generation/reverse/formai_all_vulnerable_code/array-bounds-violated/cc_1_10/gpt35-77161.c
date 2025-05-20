//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// define the size of the grid
#define ROW 10
#define COL 10

// define the starting and ending point
#define STARTROW 0
#define STARTCOL 0
#define ENDROW 9
#define ENDCOL 9

// define the heuristic function
int heuristic(int row, int col) {
    return abs(row - ENDROW) + abs(col - ENDCOL);
}

// define the node
typedef struct Node {
    int row;
    int col;
    int f;
    int g;
    int h;
    struct Node* parent;
} Node;

// define the priority queue
typedef struct PriorityQueue {
    int size;
    Node** nodes;
} PriorityQueue;

// initialize the node
Node* initializeNode(int row, int col, int g, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->g = g;
    node->h = heuristic(row, col);
    node->f = g + node->h;
    node->parent = parent;
    return node;
}

// calculate the shortest path using the A* algorithm
void astar(int grid[ROW][COL]) {
    // initialize starting node
    Node* start = initializeNode(STARTROW, STARTCOL, 0, NULL);
    start->f = start->h;

    // initialize the priority queue
    PriorityQueue q;
    q.size = 0;
    q.nodes = malloc(sizeof(Node*) * ROW * COL);
    q.nodes[q.size++] = start;

    // initialize the closed set
    int closedSet[ROW][COL] = {0};

    while (q.size > 0) {
        // get the node with the lowest f score from the queue
        Node* current = q.nodes[0];
        int currentIndex = 0;
        for (int i = 1; i < q.size; i++) {
            if (q.nodes[i]->f < current->f) {
                current = q.nodes[i];
                currentIndex = i;
            }
        }

        // remove the node from the queue
        q.nodes[currentIndex] = q.nodes[--q.size];

        // check if current node is the end node
        if (current->row == ENDROW && current->col == ENDCOL) {
            // output the shortest path
            int path[ROW * COL][2];
            int pathLength = 0;
            Node* node;
            for (node = current; node != NULL; node = node->parent) {
                path[pathLength][0] = node->row;
                path[pathLength][1] = node->col;
                pathLength++;
            }
            for (int i = pathLength - 1; i >= 0; i--) {
                printf("(%d,%d) ", path[i][0], path[i][1]);
            }
            return;
        }

        // mark current node as closed
        closedSet[current->row][current->col] = 1;

        // generate successors
        Node* successors[4];
        int numSuccessors = 0;
        if (current->row > 0) {
            successors[numSuccessors++] = initializeNode(current->row - 1, current->col, current->g + 1, current);
        }
        if (current->row < ROW - 1) {
            successors[numSuccessors++] = initializeNode(current->row + 1, current->col, current->g + 1, current);
        }
        if (current->col > 0) {
            successors[numSuccessors++] = initializeNode(current->row, current->col - 1, current->g + 1, current);
        }
        if (current->col < COL - 1) {
            successors[numSuccessors++] = initializeNode(current->row, current->col + 1, current->g + 1, current);
        }

        // process each successor
        for (int i = 0; i < numSuccessors; i++) {
            Node* successor = successors[i];

            // skip if the successor is already in the closed set
            if (closedSet[successor->row][successor->col]) {
                free(successor);
                continue;
            }

            // calculate the f score and add the successor to the queue
            successor->f = successor->g + successor->h;
            int j;
            for (j = 0; j < q.size; j++) {
                if (successor->f < q.nodes[j]->f) {
                    break;
                }
            }
            for (int k = q.size; k > j; k--) {
                q.nodes[k] = q.nodes[k - 1];
            }
            q.nodes[j] = successor;
            q.size++;
        }
    }
}

int main() {
    // define the grid
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    astar(grid);

    return 0;
}