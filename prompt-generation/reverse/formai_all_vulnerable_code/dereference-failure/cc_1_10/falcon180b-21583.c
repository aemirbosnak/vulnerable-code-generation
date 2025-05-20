//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
    int count;
}Queue;

Queue* createQueue();
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void display(Queue* q);

int main(){
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("%d dequeued\n", dequeue(q));
    printf("%d dequeued\n", dequeue(q));
    display(q);
    return 0;
}

Queue* createQueue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

void enqueue(Queue* q, int data){
    Node* temp = (Node*) malloc(sizeof(Node));
    if(temp == NULL){
        printf("Memory error\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if(q->rear == NULL){
        q->front = temp;
    }
    else{
        q->rear->next = temp;
    }
    q->rear = temp;
    q->count++;
}

int dequeue(Queue* q){
    int data;
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        Node* temp = q->front;
        data = temp->data;
        q->front = temp->next;
        free(temp);
        q->count--;
        if(q->front == NULL){
            q->rear = NULL;
        }
        return data;
    }
}

bool isEmpty(Queue* q){
    if(q->count == 0){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Queue* q){
    if(q->count == MAX_SIZE){
        return true;
    }
    else{
        return false;
    }
}

void display(Queue* q){
    printf("Queue elements are: ");
    if(isEmpty(q)){
        printf("Empty\n");
    }
    else{
        Node* temp = q->front;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}