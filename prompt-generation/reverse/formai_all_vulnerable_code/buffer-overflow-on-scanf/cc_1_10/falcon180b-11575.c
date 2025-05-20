//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
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

void dequeue(Node** frontRef, Node** rearRef) {
    if (*frontRef == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = *frontRef;
    *frontRef = (*frontRef)->next;
    if (*frontRef == NULL)
        *rearRef = NULL;
    free(temp);
}

void display(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, data;

    printf("Enter 1 to enqueue\n");
    printf("Enter 2 to dequeue\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            break;

        case 2:
            dequeue(&front, &rear);
            break;

        case 3:
            display(front);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}