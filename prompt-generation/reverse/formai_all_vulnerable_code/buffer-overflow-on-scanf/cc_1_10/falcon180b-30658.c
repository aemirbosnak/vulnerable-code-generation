//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

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
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isEmpty(Queue* q) {
    if (q->size == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFull(Queue* q) {
    if (q->size == MAX_QUEUE_SIZE) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
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

int dequeue(Queue* q) {
    int data;
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    } else if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        q->size--;
    } else {
        data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }
    return data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        Node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();
    int choice, data;
    do {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            data = dequeue(q);
            printf("Dequeued data: %d\n", data);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}