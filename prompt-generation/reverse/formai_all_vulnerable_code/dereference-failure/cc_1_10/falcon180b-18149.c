//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct queue{
    Node* front;
    Node* rear;
}Queue;

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(q->rear == NULL){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q){
    if(q->front == NULL){
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if(q->front == NULL){
        q->rear = NULL;
    }
    return data;
}

void display(Queue* q){
    Node* temp = q->front;
    printf("Queue elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int x = dequeue(q);
    printf("Dequeued element is: %d\n", x);
    display(q);
    return 0;
}