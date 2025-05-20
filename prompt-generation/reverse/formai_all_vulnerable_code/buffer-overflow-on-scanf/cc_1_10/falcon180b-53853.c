//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Queue is full! ");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    if(front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("%d enqueued to the queue. ", data);
}

void dequeue() {
    if(front == NULL) {
        printf("Queue is empty! ");
        exit(1);
    }

    Node* temp = front;
    printf("%d dequeued from the queue. ", temp->data);

    if(front == rear) {
        free(front);
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }
}

void display() {
    if(front == NULL) {
        printf("Queue is empty! ");
        exit(1);
    }

    Node* temp = front;

    printf("Elements in the queue are: ");
    while(temp!= NULL) {
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

        switch(choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
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
                printf("Invalid choice! ");
        }
    } while(choice!= 4);

    return 0;
}