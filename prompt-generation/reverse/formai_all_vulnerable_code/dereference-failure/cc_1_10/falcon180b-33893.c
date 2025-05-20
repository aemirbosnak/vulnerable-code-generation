//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int data;
    int color;
    struct node* next;
} node;

node* createNode(int data, int color) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->color = color;
    newNode->next = NULL;
    return newNode;
}

void addEdge(node** head, int u, int v, int color) {
    node* newNode = createNode(v, color);
    node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printGraph(node* head) {
    node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void dfs(node* head, int start, int color) {
    node* temp = head;
    while (temp!= NULL) {
        if (temp->data == start) {
            temp->color = color;
            return;
        }
        temp = temp->next;
    }
}

int main() {
    node* head = NULL;
    int n, m, u, v, start;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&head, u, v, 0);
        addEdge(&head, v, u, 0);
    }
    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);
    dfs(head, startNode, 1);
    printf("DFS traversal starting from node %d:\n", startNode);
    printGraph(head);
    return 0;
}