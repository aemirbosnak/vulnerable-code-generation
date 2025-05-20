//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node* next;
}QueueNode;

typedef struct{
    QueueNode* front;
    QueueNode* rear;
}Queue;


Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q){
    return q->front == NULL;
}

int isFull(Queue* q){
    QueueNode* temp = q->front;
    int count = 0;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

void enqueue(Queue* q, int data){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q){
    int data = -1;
    if(!isEmpty(q)){
        QueueNode* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

void display(Queue* q){
    QueueNode* temp = q->front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    return 0;
}