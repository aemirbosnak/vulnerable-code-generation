//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
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
}

int dequeue(Node** frontRef, Node** rearRef) {
    Node* tempNode = *frontRef;
    int data = tempNode->data;
    if (*frontRef == *rearRef) {
        *frontRef = NULL;
        *rearRef = NULL;
    } else {
        *frontRef = (*frontRef)->next;
    }
    free(tempNode);
    return data;
}

bool isEmpty(Node* queue) {
    return (queue == NULL);
}

void display(Node* queue) {
    Node* temp = queue;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* queue = NULL;
    int choice, data;

    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, &queue, data);
                break;
            case 2:
                data = dequeue(&queue, &queue);
                if (data!= -1)
                    printf("Dequeued element is %d\n", data);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}