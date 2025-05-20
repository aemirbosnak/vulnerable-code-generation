//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = new_node;
    } else if (rear == NULL) {
        rear = new_node;
        front->next = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty");
    } else if (front == rear) {
        struct node* temp = front;
        front = rear = NULL;
        free(temp);
    } else {
        struct node* temp = front;
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty");
    } else {
        printf("\nElements in the queue are: ");
        struct node* temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, value;

    do {
        printf("\n\nMENU");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to be enqueued: ");
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
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice!= 4);

    return 0;
}