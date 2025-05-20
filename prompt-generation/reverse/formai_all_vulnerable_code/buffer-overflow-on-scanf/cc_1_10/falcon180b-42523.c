//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** frontRef, int data) {
    Node* newNode = createNode(data);
    if (*frontRef == NULL) {
        *frontRef = newNode;
        return;
    }
    Node* last = *frontRef;
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

int dequeue(Node** frontRef) {
    if (*frontRef == NULL)
        return -1;
    Node* temp = *frontRef;
    *frontRef = (*frontRef)->next;
    int data = temp->data;
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
    int choice, data;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;
            case 2:
                data = dequeue(&front);
                if (data!= -1)
                    printf("Dequeued data: %d\n", data);
                break;
            case 3:
                printf("Queue: ");
                display(front);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}