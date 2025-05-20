//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int x, y;
    struct Node* next;
};

int manhattanDistance(struct Node* a, struct Node* b) {
    return (a->x - b->x) + (a->y - b->y);
}

void printPath(struct Node* start, struct Node* end) {
    struct Node* current = end;
    struct Node* next;
    while (current!= start) {
        printf("%d, %d -> ", current->x, current->y);
        next = current->next;
        free(current);
        current = next;
    }
    printf("%d, %d\n", start->x, start->y);
}

int main() {
    struct Node* start = (struct Node*) malloc(sizeof(struct Node));
    struct Node* end = (struct Node*) malloc(sizeof(struct Node));
    start->x = 0;
    start->y = 0;
    end->x = 10;
    end->y = 10;
    struct Node* current = start;
    struct Node* openList[100];
    int openListSize = 0;
    struct Node* closedList[100];
    int closedListSize = 0;
    struct Node* currentNode;
    int distance;

    openList[openListSize] = start;
    openListSize++;

    while (openListSize > 0) {
        currentNode = openList[0];
        openListSize--;
        closedList[closedListSize] = currentNode;
        closedListSize++;
        distance = manhattanDistance(currentNode, end);
        if (distance == 0) {
            printPath(start, end);
            break;
        }
        for (int i = 0; i < openListSize; i++) {
            currentNode = openList[i];
            if (distance + manhattanDistance(currentNode, end) < manhattanDistance(currentNode->next, end)) {
                currentNode->next = openList[i];
                openList[i] = currentNode->next;
                openListSize--;
                distance = manhattanDistance(currentNode, end);
                if (distance == 0) {
                    printPath(start, end);
                    break;
                }
            }
        }
    }

    free(start);
    free(end);

    return 0;
}