//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct queue
{
    int front, rear;
    int items[MAX_SIZE];
};

typedef struct queue Queue;

void enqueue(Queue* queue, int value)
{
    if(queue->rear == MAX_SIZE - 1)
    {
        printf("Queue is full!\n");
    } 
    else 
    {
        if(queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Adding %d to the Queue\n", value);
    }
}

void dequeue(Queue* queue)
{
    if(queue->front == -1 || queue->front > queue->rear)
    {
        printf("Queue is empty!\n");
    } 
    else 
    {
        printf("Removing %d from the Queue\n", queue->items[queue->front]);
        queue->front++;
    }
}

void display(Queue* queue)
{
    if(queue->rear == -1)
    {
        printf("Queue is empty!\n");
    } 
    else 
    {
        printf("Items in the Queue:\n");
        for(int i=queue->front; i <= queue->rear; i++)
            printf("%d ", queue->items[i]);
        printf("\n");
    }
}

int main()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;

    printf("Welcome to the futuristic Queue implementation!\n");

    int choice, value;
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the value to be added: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Thank you for using the futuristic Queue implementation! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    free(queue);

    return 0;
}