//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure representing the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create and initialize a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* temp = newNode(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    // If the front becomes NULL, set rear to NULL as well
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to run the queue operations
int main() {
    struct Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
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
                printf("%d enqueued to queue\n", value);
                break;

            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("%d dequeued from queue\n", value);
                }
                break;

            case 3:
                displayQueue(queue);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    // Freeing the allocated memory
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);

    return 0;
}