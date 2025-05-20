//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

int isFull(Queue *q) {
    Node *temp = q->rear;
    while (temp!= NULL) {
        temp = temp->next;
    }
    return temp == NULL;
}

void enqueue(Queue *q, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(Queue *q) {
    int data;
    Node *temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    data = temp->data;
    q->front = temp->next;
    free(temp);
    return data;
}

void display(Queue *q) {
    Node *temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    int choice, data;
    do {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                if (data!= -1) {
                    printf("Dequeued element is: %d\n", data);
                }
                break;
            case 3:
                display(q);
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