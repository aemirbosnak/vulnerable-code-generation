//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

// Defining the Queue structure
struct Queue {
    int front, rear, capacity;
    int* items;
};

// Function to create a queue of given capacity
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->items = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->rear < queue->front;
}

// Function to enqueue an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("\nThe queue is full. Cannot add more elements.\n");
        return;
    }
    queue->items[++queue->rear] = item;
    printf("\n%d is added to the queue.\n", item);
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nThe queue is empty. Cannot dequeue any element.\n");
        return -1;
    }
    return queue->items[queue->front++];
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nThe queue is empty.\n");
        return;
    }
    printf("\nThe elements of the queue are: ");
    for(int i=queue->front; i<=queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Main function to test the Queue implementation
int main() {
    int capacity, choice, element;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);
    struct Queue* queue = createQueue(capacity);
    do {
        printf("\nEnter:\n1. To enqueue an element.\n2. To dequeue an element.\n3. To display the elements of the queue.\n4. To Exit. \nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("\nEnter the element to enqueue: ");
                    scanf("%d", &element);
                    enqueue(queue, element);
                    break;
            case 2: element = dequeue(queue);
                    if(element != -1) {
                        printf("\n%d is dequeued from the queue.\n", element);
                    }
                    break;
            case 3: display(queue);
                    break;
            case 4: printf("\nExiting from the program.\n");
                    break;
            default: printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    } while(choice != 4);
    return 0;
}