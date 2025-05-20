//FormAI DATASET v1.0 Category: Queue ; Style: calm
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

// Structure to represent the queue
struct Queue 
{
    int items[MAX];
    int front;
    int rear;
};

// Function prototypes
void initQueue(struct Queue* q);
int isFull(struct Queue* q);
int isEmpty(struct Queue* q);
void enqueue(struct Queue* q, int data);
int dequeue(struct Queue* q);
void printQueue(struct Queue* q);

int main() 
{
    struct Queue q;
    int choice, data;

    initQueue(&q);

    do 
    {
        // Display menu
        printf("Queue Operation Menu\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Print Queue\n");
        printf("4.Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);

                // Enqueue data
                if (!isFull(&q)) 
                {
                    enqueue(&q, data);
                    printf("%d enqueued successfully.\n", data);
                }
                else
                {
                    printf("Queue full. Cannot enqueue data.\n");
                }
                break;

            case 2:
                // Dequeue data
                if (!isEmpty(&q)) 
                {
                    data = dequeue(&q);
                    printf("%d dequeued successfully.\n", data);
                }
                else
                {
                    printf("Queue empty. Cannot dequeue data.\n");
                }
                break;

            case 3:
                // Print queue
                printf("Queue elements: ");
                printQueue(&q);
                break;

            case 4:
                // Exit
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to initialize the queue
void initQueue(struct Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* q) 
{
    if (q->rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int data) 
{
    if (isEmpty(q)) 
    {
        q->front = 0;
        q->rear = 0;
    }
    else 
    {
        q->rear++;
    }

    q->items[q->rear] = data;
}

// Function to remove an element from the queue
int dequeue(struct Queue* q)
{
    int data = q->items[q->front];

    if (q->front == q->rear) 
    {
        q->front = -1;
        q->rear = -1;
    }
    else 
    {
        q->front++;
    }

    return data;
}

// Function to print all the elements of the queue
void printQueue(struct Queue* q) 
{
    int i;

    if (isEmpty(q))
    {
        printf("Queue empty. Nothing to print.\n");
    }
    else 
    {
        for (i = q->front; i <= q->rear; i++) 
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}