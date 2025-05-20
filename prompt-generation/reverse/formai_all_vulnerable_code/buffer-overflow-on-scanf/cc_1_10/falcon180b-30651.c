//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value);
int dequeue();
void *runner(void *param);

int main()
{
    int i, choice, value;

    printf("Enter the size of the queue: ");
    scanf("%d", &choice);

    for(i = 0; i < choice; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        enqueue(value);
    }

    pthread_t thread_id[choice];

    for(i = 0; i < choice; i++)
    {
        pthread_create(&thread_id[i], NULL, runner, NULL);
    }

    for(i = 0; i < choice; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}

void enqueue(int value)
{
    if(rear == MAX-1)
        printf("\nQueue is full!");
    else if(front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}

int dequeue()
{
    int value;

    if(front == -1 || front > rear)
        return -1;

    value = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;

    return value;
}

void *runner(void *param)
{
    int value, choice;

    printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter element to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();
            if(value!= -1)
                printf("\nDequeued element is %d", value);
            break;

        default:
            printf("\nInvalid choice!");
    }

    return NULL;
}