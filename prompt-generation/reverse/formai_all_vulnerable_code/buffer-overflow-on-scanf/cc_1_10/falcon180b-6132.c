//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Queue Node Structure
struct queueNode {
    int data;
    struct queueNode* next;
};

// Queue Structure
struct queue {
    struct queueNode* front;
    struct queueNode* rear;
    int size;
};

// Functions
void enqueue(struct queue* q, int data);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);
int isFull(struct queue* q);
void display(struct queue* q);

// Main Function
int main() {
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;

    int choice, data;

    do {
        printf("\nQUEUE OPERATIONS\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;

            case 2:
                data = dequeue(&q);
                if(data!= -1)
                    printf("Dequeued element: %d\n", data);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}

// Enqueue Function
void enqueue(struct queue* q, int data) {
    struct queueNode* newNode = (struct queueNode*)malloc(sizeof(struct queueNode));

    if(newNode == NULL) {
        printf("Memory Error\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// Dequeue Function
int dequeue(struct queue* q) {
    if(isEmpty(q))
        return -1;

    struct queueNode* temp = q->front;
    int data = temp->data;

    if(q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }

    free(temp);
    q->size--;

    return data;
}

// isEmpty Function
int isEmpty(struct queue* q) {
    if(q->front == NULL)
        return 1;

    return 0;
}

// isFull Function
int isFull(struct queue* q) {
    if(q->size == MAX_QUEUE_SIZE)
        return 1;

    return 0;
}

// Display Function
void display(struct queue* q) {
    if(isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        struct queueNode* temp = q->front;
        while(temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}