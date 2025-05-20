//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** frontRef, Node** rearRef, int data) {
    Node* newNode = createNode(data);
    if (*frontRef == NULL) {
        *frontRef = newNode;
        *rearRef = newNode;
    }
    else {
        (*rearRef)->next = newNode;
        *rearRef = newNode;
    }
}

int dequeue(Node** frontRef, Node** rearRef) {
    int data = (*frontRef)->data;
    Node* temp = *frontRef;
    *frontRef = (*frontRef)->next;
    if (*frontRef == NULL)
        *rearRef = NULL;
    free(temp);
    return data;
}

void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    printf("Queue after enqueueing elements: ");
    display(front);

    int dequeuedElement = dequeue(&front, &rear);
    printf("\nDequeued element: %d\n", dequeuedElement);

    printf("Queue after dequeuing an element: ");
    display(front);

    return 0;
}