//FormAI DATASET v1.0 Category: Queue ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
//Defining queue structure
struct queue{
    int data[MAX_SIZE];
    int front, rear;
};

//Function to initialize a new queue
void init(struct queue *q){
    q->front = q->rear = -1;
}

//Function to check if the queue is full
int isFull(struct queue *q){
    return (q->rear == MAX_SIZE - 1);
}

//Function to check if the queue is empty
int isEmpty(struct queue *q){
    return (q->front == -1 || q->front > q->rear);
}

//Function to add an element to the queue
void enqueue(struct queue *q, int element){
    if(isFull(q)){
        printf("Error: Queue is full\n");
        return;
    }
    if(q->front == -1){
        q->front++;
    }
    q->data[++q->rear] = element;
}

//Function to remove an element from the queue
int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Error: Queue is empty\n");
        return -1;
    }
    return q->data[q->front++];
}

//Function to display the queue
void display(struct queue *q){
    int i;
    printf("Queue contents: ");
    for(i = q->front; i <= q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

//Main function
int main(){
    int choice, element;
    struct queue myQueue;
    init(&myQueue);
    do{
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element you want to enqueue: ");
                scanf("%d", &element);
                enqueue(&myQueue, element);
                break;
            case 2:
                element = dequeue(&myQueue);
                if(element != -1){
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                display(&myQueue);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }while(choice != 4);
    return 0;
}