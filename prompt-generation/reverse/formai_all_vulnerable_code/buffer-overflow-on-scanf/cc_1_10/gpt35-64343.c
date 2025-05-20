//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_SIZE 10

typedef struct Queue {
    int data[QUEUE_MAX_SIZE];
    int front, rear;
} Queue;

// function prototypes
Queue* queue_init();
void enqueue(Queue*, int);
int dequeue(Queue*);
void display(Queue*);
int is_empty(Queue*);
int is_full(Queue*);

int main() {
    int option, element;
    Queue* queue = NULL;

    // display menu
    do {
        printf("\nSelect an option:\n");
        printf("1. Initialize Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter option number: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                queue = queue_init();
                printf("Queue initialized\n");
                break;
            case 2:
                if(queue == NULL) {
                    printf("Queue not initialized\n");
                    break;
                }
                printf("Enter element to be enqueued: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 3:
                if(queue == NULL) {
                    printf("Queue not initialized\n");
                    break;
                }
                element = dequeue(queue);
                if(element != -1)
                    printf("%d dequeued from queue\n", element);
                break;
            case 4:
                if(queue == NULL) {
                    printf("Queue not initialized\n");
                    break;
                }
                display(queue);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid option entered\n");
        }
    } while(option != 5);

    return 0;
}

// initialize a new queue
Queue* queue_init() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// add element to queue
void enqueue(Queue* queue, int element) {
    if(is_full(queue)) {
        printf("Queue is full\n");
        return;
    }
    if(is_empty(queue))
        queue->front++;
    queue->rear++;
    queue->data[queue->rear] = element;
    printf("%d enqueued into queue\n", element);
}

// remove element from queue
int dequeue(Queue* queue) {
    if(is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = queue->data[queue->front];
    queue->front++;
    if(queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return element;
}

// display all elements in queue
void display(Queue* queue) {
    if(is_empty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = queue->front; i <= queue->rear; i++)
        printf("%d\t", queue->data[i]);
    printf("\n");
}

// check if queue is empty
int is_empty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// check if queue is full
int is_full(Queue* queue) {
    return ((queue->rear + 1) % QUEUE_MAX_SIZE == queue->front);
}