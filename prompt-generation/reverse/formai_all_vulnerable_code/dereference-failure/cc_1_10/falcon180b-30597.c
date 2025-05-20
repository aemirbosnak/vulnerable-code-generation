//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
    int size;
}Queue;

void init(Queue* q){
    q->front=q->rear=NULL;
    q->size=0;
}

bool isEmpty(Queue* q){
    return q->front==NULL;
}

bool isFull(Queue* q){
    return q->size==100;
}

void enqueue(Queue* q,int data){
    Node* temp=malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    if(isEmpty(q)){
        q->front=temp;
        q->rear=temp;
    }
    else{
        q->rear->next=temp;
        q->rear=temp;
    }
    q->size++;
}

int dequeue(Queue* q){
    int data;
    Node* temp=q->front;
    if(isEmpty(q)){
        printf("Queue is empty\n");
        exit(0);
    }
    if(q->front==q->rear){
        data=q->front->data;
        free(q->front);
        q->front=NULL;
        q->rear=NULL;
    }
    else{
        data=q->front->data;
        q->front=q->front->next;
        free(temp);
    }
    q->size--;
    return data;
}

int main(){
    Queue q;
    init(&q);
    for(int i=0;i<105;i++){
        enqueue(&q,i);
    }
    for(int i=0;i<100;i++){
        printf("%d ",dequeue(&q));
    }
    return 0;
}