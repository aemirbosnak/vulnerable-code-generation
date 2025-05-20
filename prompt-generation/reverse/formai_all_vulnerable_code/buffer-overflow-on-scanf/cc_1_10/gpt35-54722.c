//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
// A Queue Implementation in C
#include <stdio.h>
#include <stdlib.h>

// Declare a structure for Queue
typedef struct queue{
    int* arr;
    int front; 
    int rear;
    int size;
}Queue;

// Create a new queue 
Queue* createQueue(int size){
    Queue* queue = (Queue*) malloc(sizeof(Queue));

    if(queue == NULL){
        printf("Queue creation failed.\n");
        return NULL;
    }

    queue->arr = (int*) malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;

    return queue;
}

// Check if the queue is full
int isFull(Queue* queue){
    return (queue->rear + 1) % queue->size == queue->front;
}

// Check if the queue is empty
int isEmpty(Queue* queue){
    return queue->front == -1;
}

// Add an element to the queue
void enqueue(Queue* queue, int data){
    if(isFull(queue)){
        printf("Queue overflow!\n");
        return;
    }

    if(queue->front == -1){
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = data;
}

// Remove an element from the queue
int dequeue(Queue* queue){
    int data;

    if(isEmpty(queue)){
        printf("Queue underflow!\n");
        return -1;
    }

    data = queue->arr[queue->front];

    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else{
        queue->front = (queue->front + 1) % queue->size;
    }

    return data;
}

// Display the elements of the queue
void display(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty!\n");
        return;
    }

    int i;

    for(i=queue->front; i!=queue->rear; i=(i+1)%queue->size){
        printf("%d ", queue->arr[i]);
    }

    printf("%d\n", queue->arr[i]);
}

// Driver function
int main(){
    printf("Enter the number of elements in the queue: ");
    int size;
    scanf("%d", &size);

    if(size <= 0){
        printf("Invalid size!\n");
        return 0;
    }

    Queue* queue = createQueue(size);

    if(queue == NULL){
        printf("Queue creation failed.\n");
        return 0;
    }

    printf("Enter the elements of the queue:\n");
    int i, data;

    for(i=0; i<size; i++){
        scanf("%d", &data);
        enqueue(queue, data);
    }

    printf("The queue is: ");
    display(queue);

    printf("Removing an element from the queue...\n");
    int removedData = dequeue(queue);
    printf("Removed element: %d\n", removedData);

    printf("The queue after removing the element is: ");
    display(queue);

    printf("Adding an element to the queue...\n");
    int newData;
    scanf("%d", &newData);
    enqueue(queue, newData);

    printf("The queue after adding the element is: ");
    display(queue);

    return 0;
}