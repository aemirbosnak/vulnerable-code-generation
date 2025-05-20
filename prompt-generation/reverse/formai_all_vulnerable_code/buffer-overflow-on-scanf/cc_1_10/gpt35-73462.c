//FormAI DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
        // Check if queue is full.
        if(rear == MAX_SIZE - 1)
        {
                printf("Queue overflow.\n");
                return;
        }

        // Add element to the queue.
        if(front == -1)
                front = 0;
        rear++;
        queue[rear] = data;
        printf("Element %d is enqueued to the queue.\n", data);
}

int dequeue()
{
        // Check if queue is empty.
        if(front == -1 || front > rear)
        {
                printf("Queue underflow.\n");
                return -1;
        }

        // Remove element from the queue.
        int deleted_element = queue[front];
        front++;
        printf("Element %d is dequeued from the queue.\n", deleted_element);
        return deleted_element;
}

void display()
{
        // Check if queue is empty.
        if(front == -1 || front > rear)
        {
                printf("Queue is empty.\n");
                return;
        }

        // Display elements in the queue.
        printf("Elements in the queue are: ");
        for(int i=front; i<=rear; i++)
                printf("%d ", queue[i]);
        printf("\n");
}

int main()
{
        int option;
        while(1)
        {
                printf("\n1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Exit\n");
                printf("Enter your option: ");
                scanf("%d", &option);

                switch(option)
                {
                        case 1:
                        {
                                int data;
                                printf("Enter element to be enqueued: ");
                                scanf("%d", &data);
                                enqueue(data);
                                break;
                        }
                        case 2:
                        {
                                int deleted_element = dequeue();
                                if(deleted_element != -1)
                                        printf("Deleted element is %d.\n", deleted_element);
                                break;
                        }
                        case 3:
                        {
                                display();
                                break;
                        }
                        case 4:
                        {
                                printf("Exiting program.\n");
                                return 0;
                        }
                        default:
                        {
                                printf("Invalid option entered.\n");
                                break;
                        }
                }
        }
        return 0;
}