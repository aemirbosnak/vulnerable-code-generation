//FormAI DATASET v1.0 Category: Queue ; Style: synchronous
#include <stdio.h>
#define MAX_QUEUE_SIZE 10

struct Queue {
    int front, rear;
    int data[MAX_QUEUE_SIZE];
};

typedef struct Queue Queue;

void init(Queue *queue) { //function to initialize the queue
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) { //function to check if the queue is empty
    return queue->front == -1;
}

int isFull(Queue *queue) { //function to check if the queue is full
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

int enqueue(Queue *queue, int value) { //function to add an element to the queue
    if (isFull(queue)) {
        printf("\nQueue is full. Cannot enqueue element\n");
        return -1;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
        queue->data[queue->rear] = value;
        return 0;
    }
    queue->data[++queue->rear] = value;
    return 0;
}

int dequeue(Queue *queue) { //function to remove an element from the queue
    if (isEmpty(queue)) {
        printf("\nQueue is empty. Cannot dequeue element.\n");
        return -1;
    }
    int dequeuedValue = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
        return dequeuedValue;
    }
    queue->front++;
    return dequeuedValue;
}

void display(Queue *queue) { //function to display the elements in the queue
    if (isEmpty(queue)) {
        printf("\nQueue is empty\n");
    }
    printf("\nCurrent Queue: ");
    for(int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    init(&queue);
    int choice, element;
    while (1) { //main menu-driven program
        printf("\nQueue Operations\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element you want to enqueue: ");
                scanf("%d", &element);
                if (enqueue(&queue, element) == 0) {
                    printf("\n%d enqueued to the queue\n", element);
                }
                break;
            case 2:
                element = dequeue(&queue);
                if (element != -1) {
                    printf("\n%d dequeued from the queue\n", element);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("\nExiting program");
                return 0;
            default:
                printf("\nInvalid choice. Please try again\n");
                break;
        }
    }
}