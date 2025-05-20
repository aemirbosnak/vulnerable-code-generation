//FormAI DATASET v1.0 Category: Queue ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

// Defining a struct for the queue
typedef struct {
    int arr[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Function prototypes
void init_queue(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);
int is_queue_full(Queue*);
int is_queue_empty(Queue*);
void print_queue(Queue*);

int main() {
    Queue a_queue;
    init_queue(&a_queue);

    printf("Welcome to the Imaginative Queue Program!\n");

    int choice = 0;
    int data = 0;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(is_queue_full(&a_queue)) {
                    printf("\nQueue is full!\n");
                    break;
                }
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&a_queue, data);
                printf("\nEnqueued %d successfully!\n", data);
                break;

            case 2:
                if(is_queue_empty(&a_queue)) {
                    printf("\nQueue is empty!\n");
                    break;
                }
                data = dequeue(&a_queue);
                printf("\nDequeued %d successfully!\n", data);
                break;

            case 3:
                print_queue(&a_queue);
                break;

            case 4:
                printf("\nThank you for using the Imaginative Queue Program!\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    } while(1); // Infinite loop

    return 0;
}

/* Function to initialize the queue */
void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    q->count = 0;

    // Initializing all elements to -1 (can be any initial value)
    for(int i=0; i<QUEUE_SIZE; i++) {
        q->arr[i] = -1;
    }
}

/* Function to enqueue data into the queue */
void enqueue(Queue *q, int data) {
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->arr[q->rear] = data;
    q->count++;
    if(q->front == -1) {
        q->front = q->rear;
    }
}

/* Function to dequeue data from the queue */
int dequeue(Queue *q) {
    int data = q->arr[q->front];
    q->arr[q->front] = -1;
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return data;
}

/* Function to check if queue is full */
int is_queue_full(Queue *q) {
    return q->count == QUEUE_SIZE ? 1 : 0;
}

/* Function to check if queue is empty */
int is_queue_empty(Queue *q) {
    return q->count == 0 ? 1 : 0;
}

/* Function to print the entire queue */
void print_queue(Queue *q) {
    printf("\nQueue: ");
    if(q->count == 0) {
        printf("Empty\n");
        return;
    }
    for(int i=0; i<QUEUE_SIZE; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}