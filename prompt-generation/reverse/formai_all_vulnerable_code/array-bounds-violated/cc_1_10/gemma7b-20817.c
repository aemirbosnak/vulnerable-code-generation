//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void findMazeRoute(Node* head) {
    time_t start = time(NULL);
    int visited[MAX_SIZE][MAX_SIZE] = {{0}};
    visited[head->x][head->y] = 1;

    // Breadth-First Search (BFS)
    Node* current = head;
    while (current) {
        printf("Current: (%d, %d)\n", current->x, current->y);
        visited[current->x][current->y] = 1;

        // Move right
        if (visited[current->x + 1][current->y] == 0) {
            current->next = createNode(current->x + 1, current->y);
            insertNode(current, current->x + 1, current->y);
        }

        // Move left
        if (visited[current->x - 1][current->y] == 0) {
            current->next = createNode(current->x - 1, current->y);
            insertNode(current, current->x - 1, current->y);
        }

        // Move up
        if (visited[current->x][current->y + 1] == 0) {
            current->next = createNode(current->x, current->y + 1);
            insertNode(current, current->x, current->y + 1);
        }

        // Move down
        if (visited[current->x][current->y - 1] == 0) {
            current->next = createNode(current->x, current->y - 1);
            insertNode(current, current->x, current->y - 1);
        }

        current = current->next;
    }

    time_t end = time(NULL);
    printf("Time taken: %.2f seconds\n", (double)(end - start));
}

int main() {
    Node* head = createNode(0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 3, 1);
    insertNode(head, 3, 2);
    insertNode(head, 3, 3);

    findMazeRoute(head);

    return 0;
}