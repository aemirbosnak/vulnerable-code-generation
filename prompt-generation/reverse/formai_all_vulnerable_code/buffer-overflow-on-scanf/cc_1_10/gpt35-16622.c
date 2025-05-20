//FormAI DATASET v1.0 Category: Queue Implementation ; Style: configurable
/******************************************************************************
* Program: Configurable Queue Implementation
*
* Description:
*    This program implements a queue data structure where the length of the queue 
*    can be customized with an input parameter. 
*
* Operations supported are:
*   - enqueue   
*   - dequeue   
*   - display   
*   - empty     
*   - isFull    
*
* Author: (Your name here)
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int front;
    int rear;
    int capacity;
    int size;
    int *array;
} CQueue;

// function prototypes
CQueue* createQueue(int);
int isFull(CQueue*);
int isEmpty(CQueue*);
void enqueue(CQueue*, int);
int dequeue(CQueue*);
void display(CQueue*);

int main() 
{
    int capacity; 
    printf("\nEnter capacity of Queue: ");
    scanf("%d", &capacity);
    CQueue* queue = createQueue(capacity);
    int choice, ele;
    
    do 
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if queue is empty\n");
        printf("5. Check if queue is full\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                printf("\nEnter data to enequeue : ");
                scanf("%d", &ele);
                if(isFull(queue))
                    printf("\nQueue is full. Cannot enqueue.");
                else 
                    enqueue(queue, ele);
                break;
            case 2:
                if(isEmpty(queue))
                    printf("\nQueue is empty. Cannot dequeue.");
                else 
                    printf("\nDequeued element is %d\n", dequeue(queue));
                break;
            case 3:
                display(queue);
                break;
            case 4:
                if(isEmpty(queue))
                    printf("\nQueue is empty.");
                else 
                    printf("\nQueue is not empty.");
                break;
            case 5:
                if(isFull(queue))
                    printf("\nQueue is full.");
                else 
                    printf("\nQueue is not full.");
                break;
            case 6:
                printf("\nExiting program...");
                exit(1);
            default:
                printf("\nInvalid choice.");
        }
    } while(1);
}

CQueue* createQueue(int capacity) 
{
    CQueue* queue = (CQueue*)malloc(sizeof(CQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(CQueue* queue) 
{
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

int isEmpty(CQueue* queue) 
{
    return (queue->front == -1 && queue->rear == -1);
}

void enqueue(CQueue* queue, int data) 
{
    if(isFull(queue)) 
    {
        printf("\nQueue is full. Cannot enqueue.");
        return;
    }
    else if(isEmpty(queue)) 
    {
        queue->front = queue->rear = 0;
        queue->array[queue->rear] = data;
        queue->size++;
    }
    else 
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = data;
        queue->size++;
    }
}

int dequeue(CQueue* queue) 
{
    int data;
    if(isEmpty(queue)) 
    {
        printf("\nQueue is empty. Cannot dequeue.");
        return -9999;
    }
    else if(queue->front == queue->rear) 
    {
        data = queue->array[queue->front];
        queue->front = queue->rear = -1;
        queue->size--;
    }
    else 
    {
        data = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
    }
    return data;
}

void display(CQueue* queue) 
{
    if(isEmpty(queue)) 
    {
        printf("\nQueue is empty. Nothing to display.");
        return;
    }
    else {
        int i;
        printf("\nThe elements in queue are: ");
        for(i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) 
            printf("%d ", queue->array[i]);
        printf("%d", queue->array[i]);
    }   
}