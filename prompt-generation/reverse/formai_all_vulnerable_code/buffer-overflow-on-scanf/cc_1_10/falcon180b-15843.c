//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
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
    } else {
        (*rearRef)->next = newNode;
        *rearRef = newNode;
    }
    printf("Enqueued %d\n", data);
}

int dequeue(Node** frontRef, Node** rearRef) {
    if (*frontRef == NULL)
        return -1;
    int data = (*frontRef)->data;
    Node* temp = *frontRef;
    *frontRef = (*frontRef)->next;
    if (*frontRef == NULL)
        *rearRef = NULL;
    free(temp);
    printf("Dequeued %d\n", data);
    return data;
}

int peek(Node* front) {
    if (front == NULL)
        return -1;
    return front->data;
}

bool isEmpty(Node* front) {
    return front == NULL;
}

void display(Node* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, data;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear);
                if (data!= -1)
                    printf("Dequeued %d\n", data);
                break;
            case 3:
                data = peek(front);
                if (data!= -1)
                    printf("Front element is %d\n", data);
                break;
            case 4:
                display(front);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (true);

    return 0;
}