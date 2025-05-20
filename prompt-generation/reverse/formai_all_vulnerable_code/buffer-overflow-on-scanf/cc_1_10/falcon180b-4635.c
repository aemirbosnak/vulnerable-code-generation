//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Error\n");
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
        return;
    }
    (*rearRef)->next = newNode;
    *rearRef = newNode;
}

int dequeue(Node** frontRef, Node** rearRef) {
    if (*frontRef == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = *frontRef;
    *frontRef = (*frontRef)->next;
    int data = temp->data;
    free(temp);
    if (*frontRef == NULL) {
        *rearRef = NULL;
    }
    return data;
}

void display(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, data;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            break;
        case 2:
            data = dequeue(&front, &rear);
            if (data!= -1) {
                printf("Dequeued element is: %d\n", data);
            }
            break;
        case 3:
            display(front);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}