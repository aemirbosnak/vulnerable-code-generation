//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define MAX 5
#define FULL 0
#define EMPTY 1

int buffer[MAX];
int front = -1;
int rear = -1;
int mutex = 0;
int empty = 1;
int full = 0;

void init()
{
    int i;
    for(i=0;i<MAX;i++)
    {
        buffer[i] = 0;
    }
    front = -1;
    rear = -1;
    mutex = 0;
    empty = 1;
    full = 0;
}

void enqueue(int item)
{
    if(full == 1)
    {
        printf("\nQueue is full");
        return;
    }
    else if(empty == 0)
    {
        front = 0;
        rear = 0;
        buffer[rear] = item;
    }
    else
    {
        rear++;
        buffer[rear] = item;
    }
    empty = 0;
}

void dequeue()
{
    if(empty == 1)
    {
        printf("\nQueue is empty");
        return;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
        empty = 1;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue is: ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",buffer[i]);
        }
    }
}

void *producer(void *arg)
{
    int i,item;
    for(i=0;i<10;i++)
    {
        item = i*2;
        enqueue(item);
        printf("\nProduced %d",item);
        sleep(1);
    }
    pthread_exit(0);
}

void *consumer(void *arg)
{
    int i,item;
    for(i=0;i<10;i++)
    {
        dequeue();
        printf("\nConsumed %d",buffer[i]);
        sleep(1);
    }
    pthread_exit(0);
}

int main()
{
    pthread_t thread_id[2];
    int i;
    init();
    pthread_create(&thread_id[0],NULL,producer,NULL);
    pthread_create(&thread_id[1],NULL,consumer,NULL);
    for(i=0;i<2;i++)
    {
        pthread_join(thread_id[i],NULL);
    }
    return 0;
}