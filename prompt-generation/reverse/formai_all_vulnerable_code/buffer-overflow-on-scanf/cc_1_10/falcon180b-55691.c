//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
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

    if(new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    if(front == NULL) {
        front = new_node;
        rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;

    printf("Elements in the queue are: ");

    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    do {
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
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);

    return 0;
}