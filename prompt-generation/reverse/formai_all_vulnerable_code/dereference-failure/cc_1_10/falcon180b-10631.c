//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
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
    Node* lastNode = *frontRef;
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

int dequeue(Node** frontRef) {
    if (*frontRef == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* tempNode = *frontRef;
    *frontRef = (*frontRef)->next;
    int data = tempNode->data;
    free(tempNode);
    return data;
}

void display(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* currNode = front;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, data;
    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;
            case 2:
                data = dequeue(&front);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}