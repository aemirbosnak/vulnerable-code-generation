//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
// A unique C Queue Implementation example program in a thoughtful style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// A structure to represent the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, the new node is both the front and rear
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    // Check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    // Get the front element
    struct Node* front = queue->front;
    int data = front->data;

    // Update the front pointer to the next node
    queue->front = front->next;

    // Free the memory allocated to the front node
    free(front);

    return data;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Display the queue
    displayQueue(queue);

    // Dequeue some elements
    int data = dequeue(queue);
    printf("Dequeued %d\n", data);
    data = dequeue(queue);
    printf("Dequeued %d\n", data);

    // Display the queue again
    displayQueue(queue);

    // Free the memory allocated to the queue
    free(queue);

    return 0;
}