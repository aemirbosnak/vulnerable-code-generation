//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    do {
        printf("\n\nMENU\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d has been enqueued to the queue\n", value);
}

void dequeue() {
    if(front == NULL) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }

    Node* temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    printf("%d has been dequeued from the queue\n", temp->data);
    free(temp);
}

void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue are: ");
    Node* temp = front;

    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}