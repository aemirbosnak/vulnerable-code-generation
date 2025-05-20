//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
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
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else if (rear == NULL) {
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue\n", value);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    }
    else if (front == NULL) {
        rear = NULL;
        printf("%d dequeued from the queue\n", rear->data);
        free(rear);
    }
    else if (rear == NULL) {
        front = NULL;
        printf("%d dequeued from the queue\n", front->data);
        free(front);
    }
    else {
        struct node* temp = front;
        printf("%d dequeued from the queue\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    }
    else {
        printf("Elements in the queue are: ");
        struct node* temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    do {
        printf("Enter 1 for enqueue, 2 for dequeue, 3 for display, 4 for exit: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}