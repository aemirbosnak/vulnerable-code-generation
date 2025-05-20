//FormAI DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct
{
    int front; // Index of front element
    int rear;  // Index of rear element
    int count; // Total count of elements in the queue
    int queue[MAX_QUEUE_SIZE]; // Integer array to store the queue elements
} Queue;

// Function prototypes
void enqueue(Queue *q, int element);
int dequeue(Queue *q);
void display(Queue q);

int main()
{
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.count = 0;

    int choice, element;

    printf("Welcome to the Queue Implementation program!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit the program\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;
            case 2:
                element = dequeue(&q);
                if (element != -1)
                    printf("\nThe dequeued element is %d", element);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("\nThank you for using the Queue Implementation program!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue(Queue *q, int element)
{
    if (q->count == MAX_QUEUE_SIZE)
    {
        printf("\nSorry, the queue is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = element;
    q->count++;
    printf("\n%d has been enqueued to the queue.\n", element);
}

int dequeue(Queue *q)
{
    if (q->count == 0)
    {
        printf("\nSorry, the queue is empty.\n");
        return -1;
    }

    int element = q->queue[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return element;
}

void display(Queue q)
{
    if (q.count == 0)
    {
        printf("\nThe queue is empty.\n");
        return;
    }

    printf("\nThe elements in the queue are: ");
    for (int i = 0; i < q.count; i++)
    {
        int index = (q.front + i) % MAX_QUEUE_SIZE;
        printf("%d ", q.queue[index]);
    }
    printf("\n");
}