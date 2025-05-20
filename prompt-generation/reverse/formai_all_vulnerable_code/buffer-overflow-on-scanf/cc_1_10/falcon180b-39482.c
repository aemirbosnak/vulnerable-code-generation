//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
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
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    int value;
    struct node* temp = front;

    if (front == NULL) {
        printf("\nQueue is empty\n");
        return -1;
    } else if (front == rear) {
        value = front->data;
        free(front);
        front = rear = NULL;
    } else {
        value = front->data;
        front = front->next;
        free(temp);
    }

    return value;
}

void display() {
    struct node* temp = front;

    if (front == NULL) {
        printf("\nQueue is empty\n");
        return;
    } else {
        printf("\nElements in the queue are:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value!= -1)
                    printf("\nThe dequeued value is %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}