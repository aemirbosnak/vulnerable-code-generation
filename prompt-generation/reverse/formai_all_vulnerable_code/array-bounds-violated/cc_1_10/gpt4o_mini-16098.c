//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define ROW 10
#define COL 10

#define INF 99999 

typedef struct {
    int x, y;
    int f, g, h;
} Node;

typedef struct {
    Node *nodes;
    int size;
} NodeList;

NodeList openList;
NodeList closedList;
int grid[ROW][COL] = {
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

void addToList(NodeList* list, Node node) {
    list->nodes = realloc(list->nodes, (list->size + 1) * sizeof(Node));
    list->nodes[list->size] = node;
    list->size++;
}

bool isInList(NodeList list, Node node) {
    for (int i = 0; i < list.size; i++) {
        if (list.nodes[i].x == node.x && list.nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void printPath(Node* path, int pathLength) {
    for (int i = 0; i < pathLength; i++) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

void aStar(int startX, int startY, int endX, int endY) {
    Node start = {startX, startY, 0, 0, 0};
    Node end = {endX, endY, 0, 0, 0};

    addToList(&openList, start);

    while (openList.size > 0) {
        Node current = openList.nodes[0];
        int currentIndex = 0;

        for (int i = 1; i < openList.size; i++) {
            if (openList.nodes[i].f < current.f) {
                current = openList.nodes[i];
                currentIndex = i;
            }
        }

        // Remove current from open list
        for (int i = currentIndex; i < openList.size - 1; i++) {
            openList.nodes[i] = openList.nodes[i + 1];
        }
        openList.size--;

        // Add to closed list
        addToList(&closedList, current);

        // Check for goal
        if (current.x == end.x && current.y == end.y) {
            printf("Path found: ");
            printPath(closedList.nodes, closedList.size);
            return;
        }

        // Generate neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals
                int neighborX = current.x + dx;
                int neighborY = current.y + dy;

                if (neighborX >= 0 && neighborX < ROW && neighborY >= 0 && neighborY < COL && grid[neighborX][neighborY] == 0) {
                    Node neighbor = {neighborX, neighborY, 0, current.g + 1, heuristic((Node){neighborX, neighborY}, end)};
                    neighbor.f = neighbor.g + neighbor.h;

                    if (isInList(closedList, neighbor)) continue;

                    if (!isInList(openList, neighbor)) {
                        addToList(&openList, neighbor);
                    }
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    openList.nodes = NULL;
    openList.size = 0;

    closedList.nodes = NULL;
    closedList.size = 0;

    int startX, startY, endX, endY;
    printf("Enter start coordinates (x y): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter end coordinates (x y): ");
    scanf("%d %d", &endX, &endY);

    if (grid[startX][startY] == 1 || grid[endX][endY] == 1) {
        printf("Invalid start or end coordinates.\n");
        return 1;
    }

    aStar(startX, startY, endX, endY);

    free(openList.nodes);
    free(closedList.nodes);
    return 0;
}