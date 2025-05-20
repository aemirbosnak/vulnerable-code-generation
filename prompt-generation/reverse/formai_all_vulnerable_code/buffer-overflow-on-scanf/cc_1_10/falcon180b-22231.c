//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

void init(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue* q, int value) {
    node* new_node = (node*)malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void dequeue(queue* q) {
    node* temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

void display(queue* q) {
    node* temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    int choice, value;

    init(&q);

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}