//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue{
    int front, rear;
    int queue_array[MAX_SIZE];
};

//Function to check if the queue is full
int isFull(struct Queue* queue){
    return (queue->rear == MAX_SIZE - 1);
}

//Function to check if the queue is empty
int isEmpty(struct Queue* queue){
    return (queue->front == -1 || queue->front > queue->rear);
}

//Function to add an element to the queue
void enqueue(struct Queue* queue, int element){
    if(isFull(queue)){
        printf("Overflow!\n");
        return;
    } else {
        if(queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->queue_array[queue->rear] = element;
    }
}

//Function to remove an element from the queue
int dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Underflow!\n");
        return -1;
    } else {
        int element = queue->queue_array[queue->front];
        queue->front++;
        return element;
    }
}

//Function to display the queue
void display(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty!\n");
        return;
    } else {
        printf("Queue is: ");
        for(int i = queue->front; i <= queue->rear; i++){
            printf("%d ", queue->queue_array[i]);
        }
        printf("\n");
    }
}

int main(){
    struct Queue queue;
    queue.front = -1;
    queue.rear = -1;

    int choice, element;

    do {
        //Display menu
        printf("1. Enqueue element\n");
        printf("2. Dequeue element\n");
        printf("3. Display queue\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                element = dequeue(&queue);
                printf("Dequeued element is %d\n", element);
                break;
            case 3:
                display(&queue);
                break;
            case 0:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 0);

    return 0;
}