//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

struct node {
    int data;
    int priority;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data, int priority) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = front;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node* temp = front;

    printf("Queue elements:\n");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(0));

    int choice, data;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data, rand() % 10);
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
                printf("Invalid choice!\n");
        }
    }

    return 0;
}