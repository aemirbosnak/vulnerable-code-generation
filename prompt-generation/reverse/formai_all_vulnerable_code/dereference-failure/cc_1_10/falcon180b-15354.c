//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct{
    int data;
    int index;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

Queue* createQueue(){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void enqueue(Queue* queue, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->index = -1;
    newNode->next = NULL;
    if(queue->front == NULL){
        queue->front = newNode;
        queue->rear = newNode;
    }
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue){
    if(queue->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int peek(Queue* queue){
    if(queue->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

int size(Queue* queue){
    int count = 0;
    Node* temp = queue->front;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int isEmpty(Queue* queue){
    return queue->front == NULL;
}

void printQueue(Queue* queue){
    Node* temp = queue->front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue* myQueue = createQueue();
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    printQueue(myQueue);
    printf("Size of queue is %d\n", size(myQueue));
    printf("Peek element is %d\n", peek(myQueue));
    dequeue(myQueue);
    dequeue(myQueue);
    printQueue(myQueue);
    printf("Size of queue is %d\n", size(myQueue));
    return 0;
}