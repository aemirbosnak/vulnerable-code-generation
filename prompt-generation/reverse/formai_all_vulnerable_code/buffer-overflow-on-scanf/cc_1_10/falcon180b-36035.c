//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

struct node {
    int data;
    int priority;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data, int priority) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else if (rear->priority < priority) {
        rear->next = new_node;
        rear = new_node;
    } else {
        struct node* temp = front;

        while (temp->next!= NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    struct node* temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, priority;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
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