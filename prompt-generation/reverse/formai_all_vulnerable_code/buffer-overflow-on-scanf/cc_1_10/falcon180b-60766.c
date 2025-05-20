//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    int data = 0;
    struct Node* temp = q->front;

    if (!isEmpty(q)) {
        data = temp->data;
        q->front = temp->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }

        free(temp);
    }

    return data;
}

void display(struct Queue* q) {
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    int choice, data;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}