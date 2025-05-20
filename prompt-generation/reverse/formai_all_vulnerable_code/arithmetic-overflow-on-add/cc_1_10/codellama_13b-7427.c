//Code Llama-13B DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
// A* Pathfinding Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Structure to represent a node in the graph
typedef struct {
    int x;
    int y;
    int g; // Distance from start
    int h; // Estimated distance to goal
    int f; // Total cost (g + h)
    struct node* parent; // Parent node
} node;

// Function to create a new node
node* newNode(int x, int y) {
    node* n = (node*)malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->g = INT_MAX;
    n->h = INT_MAX;
    n->f = INT_MAX;
    n->parent = NULL;
    return n;
}

// Function to calculate the heuristic value
int heuristic(node* n, node* goal) {
    return abs(n->x - goal->x) + abs(n->y - goal->y);
}

// Function to check if a node is in the open list
int inOpenList(node* n, node** openList, int openListSize) {
    for (int i = 0; i < openListSize; i++) {
        if (openList[i] == n) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a node is in the closed list
int inClosedList(node* n, node** closedList, int closedListSize) {
    for (int i = 0; i < closedListSize; i++) {
        if (closedList[i] == n) {
            return 1;
        }
    }
    return 0;
}

// Function to add a node to the open list
void addToOpenList(node* n, node** openList, int* openListSize) {
    openList[*openListSize] = n;
    *openListSize += 1;
}

// Function to add a node to the closed list
void addToClosedList(node* n, node** closedList, int* closedListSize) {
    closedList[*closedListSize] = n;
    *closedListSize += 1;
}

// Function to remove a node from the open list
void removeFromOpenList(node* n, node** openList, int* openListSize) {
    for (int i = 0; i < *openListSize; i++) {
        if (openList[i] == n) {
            openList[i] = openList[*openListSize - 1];
            *openListSize -= 1;
            break;
        }
    }
}

// Function to remove a node from the closed list
void removeFromClosedList(node* n, node** closedList, int* closedListSize) {
    for (int i = 0; i < *closedListSize; i++) {
        if (closedList[i] == n) {
            closedList[i] = closedList[*closedListSize - 1];
            *closedListSize -= 1;
            break;
        }
    }
}

// Function to find the minimum f value in the open list
node* minOpenList(node** openList, int openListSize) {
    node* min = openList[0];
    for (int i = 1; i < openListSize; i++) {
        if (openList[i]->f < min->f) {
            min = openList[i];
        }
    }
    return min;
}

// Function to run A* search
void aStarSearch(node* start, node* goal) {
    // Initialize open list
    node** openList = (node**)malloc(sizeof(node*) * 100);
    int openListSize = 0;
    addToOpenList(start, openList, &openListSize);

    // Initialize closed list
    node** closedList = (node**)malloc(sizeof(node*) * 100);
    int closedListSize = 0;

    // Loop until open list is empty
    while (openListSize > 0) {
        // Get the node with the minimum f value
        node* current = minOpenList(openList, openListSize);

        // If the current node is the goal, return the path
        if (current == goal) {
            printf("Found goal\n");
            node* parent = current->parent;
            while (parent != NULL) {
                printf("%d %d\n", parent->x, parent->y);
                parent = parent->parent;
            }
            return;
        }

        // Remove the current node from the open list
        removeFromOpenList(current, openList, &openListSize);

        // Add the current node to the closed list
        addToClosedList(current, closedList, &closedListSize);

        // Loop through all neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // If the neighbor is not the current node and not in the closed list, add it to the open list
                if (i != 0 || j != 0) {
                    int x = current->x + i;
                    int y = current->y + j;
                    node* neighbor = newNode(x, y);
                    if (!inClosedList(neighbor, closedList, closedListSize)) {
                        neighbor->g = current->g + 1;
                        neighbor->h = heuristic(neighbor, goal);
                        neighbor->f = neighbor->g + neighbor->h;
                        neighbor->parent = current;
                        addToOpenList(neighbor, openList, &openListSize);
                    }
                }
            }
        }
    }

    // If the open list is empty, return failure
    printf("Failed to find goal\n");
}

int main() {
    // Initialize the start and goal nodes
    node* start = newNode(0, 0);
    node* goal = newNode(5, 5);

    // Run A* search
    aStarSearch(start, goal);

    return 0;
}