//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL) {
        front = newnode;
    }
    else {
        rear->next = newnode;
    }
    rear = newnode;
    printf("Element %d added to queue\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element %d removed from queue\n", front->data);
    Node *temp = front;
    front = front->next;
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = front;
    printf("Queue elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}