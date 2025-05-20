//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50 // maximum size of the queue

// defining the queue structure
typedef struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue)); // allocating memory for the queue
    queue->front = -1; // initializing the front
    queue->rear = -1; // initializing the rear
    queue->size = 0; // initializing the size
    return queue;
}

// function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// function to add an element to the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) { // checking if the queue is full
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) { // if the queue is empty
        queue->front = 0; // set the front to 0
    }
    queue->rear++; // increment the rear
    queue->arr[queue->rear] = element; // adding the element to the queue
    queue->size++; // increase the size
    printf("%d has been added to the queue!\n", element); // printing the element added
}

// function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) { // checking if the queue is empty
        printf("Queue is empty!\n");
        return -1;
    }
    int element = queue->arr[queue->front]; // storing the element to be removed
    queue->front++; // increment the front
    queue->size--; // decrease the size
    if (queue->front > queue->rear) { // if all the elements have been removed
        queue->front = -1; // set the front back to -1
        queue->rear = -1; // set the rear back to -1
    }
    printf("%d has been removed from the queue!\n", element); // printing the element removed
    return element;
}

// function to display the elements of the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) { // checking if the queue is empty
        printf("Queue is empty!\n");
        return;
    }
    printf("Current Queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) { // printing the elements of the queue
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// main function
int main() {
    printf("Welcome to my futuristic C Queue Implementation program!\n");

    Queue* queue = createQueue(); // creating a new queue

    int choice, element;

    do {
        printf("\n\nChoose an option:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be added: ");
                scanf("%d", &element);
                enqueue(queue, element); // adding the element to the queue
                break;
            case 2:
                dequeue(queue); // removing an element from the queue
                break;
            case 3:
                displayQueue(queue); // displaying the elements of the queue
                break;
            case 4:
                printf("\nThank you for using my futuristic C Queue Implementation program!\n");
                exit(0); // exiting the program
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 4); // performing the operations until the user chooses to exit

    return 0;
}