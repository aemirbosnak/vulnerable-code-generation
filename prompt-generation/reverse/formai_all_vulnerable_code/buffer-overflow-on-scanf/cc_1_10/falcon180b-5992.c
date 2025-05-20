//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool isEmpty(Queue* queue) {
    if (queue->size == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFull(Queue* queue) {
    if (queue->size == MAX_SIZE) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

int dequeue(Queue* queue) {
    int data = 0;
    Node* temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        data = temp->data;
        queue->front = temp->next;
        if (isEmpty(queue)) {
            queue->rear = NULL;
        }
        free(temp);
        queue->size--;
    }
    return data;
}

void display(Queue* queue) {
    Node* temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* queue = createQueue();
    int choice, data;
    while (true) {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue:\n");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                printf("Dequeued data: %d\n", data);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}