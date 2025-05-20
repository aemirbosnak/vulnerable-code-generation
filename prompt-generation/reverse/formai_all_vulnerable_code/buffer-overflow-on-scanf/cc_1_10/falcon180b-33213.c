//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isEmpty(Queue* queue) {
    if (queue->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Queue* queue) {
    if (queue->size == MAX_SIZE) {
        return 1;
    } else {
        return 0;
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
    int data = -1;
    if (!isEmpty(queue)) {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = queue->front->next;
        free(temp);
        queue->size--;
    }
    return data;
}

void display(Queue* queue) {
    Node* temp = queue->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    int choice, data;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                } else {
                    printf("Queue is empty\n");
                }
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