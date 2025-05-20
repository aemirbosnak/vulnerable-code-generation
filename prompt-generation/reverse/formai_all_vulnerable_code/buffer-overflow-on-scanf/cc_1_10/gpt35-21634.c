//FormAI DATASET v1.0 Category: Queue Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Define Queue structure
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Create Queue and initialize its values 
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if an element can be inserted in Queue
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if an element can be removed from Queue
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Add an element to the rear end of Queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        printf("Queue Overflow!\n");
    else {
        queue->rear = (queue->rear + 1)%queue->capacity;
        queue->array[queue->rear] = item;
        queue->size++;
        printf("%d has been added to Queue.\n", item);
    }
}

// Removes an element from front end of Queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
        return INT_MIN;
    }
    else {
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1)%queue->capacity;
        queue->size--;
        printf("%d has been removed from Queue.\n", item);
        return item;
    }
}

// Returns front element of Queue without removing it
int front(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    else
        return queue->array[queue->front];
}

// Returns rear element of Queue without removing it
int rear(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    else
        return queue->array[queue->rear];
}

// Print current state of Queue
void printQueue(struct Queue* queue) {
    if(isEmpty(queue))
        printf("Queue is empty!\n");
    else {
        printf("Current state of Queue is:\n");
        for(int i = 0; i < queue->size; i++)
            printf("%d\n", queue->array[(queue->front + i)%queue->capacity]);
    }
}

int main() {
    int capacity, option, item;
    printf("Enter capacity of the Queue: ");
    scanf("%d", &capacity);
    struct Queue* queue = createQueue(capacity);
    printf("\nWelcome to Queue implementation program!\n\n");
    printf("Choose an option from below:\n");
    printf("--------------------------------\n");
    printf("1. Add an element to Queue\n");
    printf("2. Remove an element from Queue\n");
    printf("3. Peek front element of Queue\n");
    printf("4. Peek rear element of Queue\n");
    printf("5. Print current state of Queue\n");
    printf("6. Exit the program\n");
    printf("--------------------------------\n");
    do {
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: printf("Enter the element to add: ");
                    scanf("%d", &item);
                    enqueue(queue, item);
                    break;
            case 2: item = dequeue(queue);
                    if(item != INT_MIN)
                        printf("%d has been removed from Queue.\n", item);
                    break;
            case 3: item = front(queue);
                    if(item != INT_MIN)
                        printf("Front element of Queue is %d\n", item);
                    break;
            case 4: item = rear(queue);
                    if(item != INT_MIN)
                        printf("Rear element of Queue is %d\n", item);
                    break;
            case 5: printQueue(queue);
                    break;
            case 6: printf("Thank you for using Queue implementation program!\n");
                    break;
            default: printf("Invalid choice! Please try again.\n");
                    break;
        }
    }while(option != 6);
    return 0;
}