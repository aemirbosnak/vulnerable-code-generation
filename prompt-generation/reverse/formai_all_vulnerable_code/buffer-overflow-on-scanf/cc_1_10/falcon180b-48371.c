//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

bool isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

bool isFull(struct Queue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(struct Queue* queue) {
    int data = -1;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    } else if (queue->front == queue->rear) {
        struct Node* temp = queue->front;
        data = temp->data;
        queue->front = NULL;
        queue->rear = NULL;
        free(temp);
    } else {
        struct Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;
        free(temp);
    }
    queue->size--;
    return data;
}

void display(struct Queue* queue) {
    struct Node* temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    int choice, data;

    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                printf("%d enqueued successfully\n", data);
                break;
            case 2:
                data = dequeue(&queue);
                printf("%d dequeued successfully\n", data);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}