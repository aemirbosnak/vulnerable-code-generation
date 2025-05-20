//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#define MAXSIZE 10
 
typedef struct{
    int front;
    int rear;
    int capacity;
    int* array;
}Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

void enqueue(Queue* queue, int item) {
    if ((queue->front == 0 && queue->rear == queue->capacity-1) || (queue->rear == (queue->front-1)%(queue->capacity-1))) {
        printf("\nQueue is full!");
        return;
    }
    else if (queue->front == -1) {
        queue->front = queue->rear = 0;
        queue->array[queue->rear] = item;
    }
    else if (queue->rear == queue->capacity-1 && queue->front != 0) {
        queue->rear = 0;
        queue->array[queue->rear] = item;
    }
    else {
        queue->rear++;
        queue->array[queue->rear] = item;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == -1) {
        printf("\nQueue is empty!");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->array[queue->front] = -1;
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }
    else if (queue->front == queue->capacity-1) {
        queue->front = 0;
    }
    else {
        queue->front++;
    }
    return item;
}

int main(){
    printf("Welcome to the Queue!\n");
    printf("This is a unique C Queue Implementation example program.\n");
    printf("You can enqueue or dequeue elements from the queue.\n");
    Queue* myQueue = createQueue(MAXSIZE);
    int choice;
    int item;
    do{
        printf("\nChoose an option below:\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter an element to enqueue: ");
                scanf("%d", &item);
                enqueue(myQueue, item);
                printf("\nElement enqueued successfully!");
                break;
            case 2:
                item = dequeue(myQueue);
                if(item != -1){
                    printf("\nElement dequeued successfully! Value: %d", item);
                }
                break;
            case 3:
                printf("\nThanks for using the Queue. Have a good day!");
                exit(0);
            default:
                printf("\nEnter a valid choice.");
        }
    }while(1);
    return 0;
}