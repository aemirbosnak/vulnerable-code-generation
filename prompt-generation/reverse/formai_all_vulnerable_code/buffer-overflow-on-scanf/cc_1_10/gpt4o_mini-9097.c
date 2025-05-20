//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function to create a queue of a given capacity
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1; // This is important, see the enqueue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue. 
// It changes rear and size
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity; // Circular increment
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("Enqueued %d to queue\n", item);
}

// Function to remove an item from the queue. 
// It changes front and size
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity; // Circular increment
    queue->size = queue->size - 1;
    printf("Dequeued %d from queue\n", item);
    return item;
}

// Function to display the queue elements
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

// Main function for the program
int main() {
    unsigned capacity;
    printf("Enter queue capacity: ");
    scanf("%u", &capacity);
    
    Queue* queue = createQueue(capacity);
    
    int choice, value;
    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    free(queue->array);
    free(queue);
    return 0;
}