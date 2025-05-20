//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    int size;
} queue;

queue* createQueue() {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

bool isEmpty(queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return true;
    } else {
        return false;
    }
}

bool isFull(queue* q) {
    if (q->size == MAX_SIZE) {
        return true;
    } else {
        return false;
    }
}

void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = q->front->data;
        node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
        return data;
    }
}

int peek(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->front->data;
    }
}

void display(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    queue* q = createQueue();
    int choice, data;
    do {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to be enqueued: ");
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
                data = peek(q);
                if (data!= -1) {
                    printf("Front element is: %d\n", data);
                }
                break;
            case 4:
                display(q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);
    free(q);
    return 0;
}