//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** frontRef, int data) {
    node *newNode = createNode(data);
    if (*frontRef == NULL) {
        newNode->next = NULL;
        *frontRef = newNode;
        return;
    }
    else {
        node* temp = *frontRef;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        return;
    }
}

void dequeue(node** frontRef) {
    if (*frontRef == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node* temp = *frontRef;
    *frontRef = temp->next;
    free(temp);
    return;
}

void display(node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    node* front = NULL;
    int choice, data;
    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;
            case 2:
                dequeue(&front);
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