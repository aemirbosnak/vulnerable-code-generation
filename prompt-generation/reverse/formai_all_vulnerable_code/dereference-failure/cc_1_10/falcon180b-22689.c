//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 10

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

void initQueue(struct queue* q){
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(struct queue* q){
    if(q->front == NULL && q->rear == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(struct queue* q){
    if((q->rear->next == NULL && q->rear!= q->front) || q->rear == q->front->next){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(struct queue* q, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
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

int dequeue(struct queue* q){
    int data = -1;
    if(!isEmpty(q)){
        data = q->front->data;
        struct node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        if(isEmpty(q)){
            q->rear = NULL;
        }
    }
    return data;
}

void display(struct queue* q){
    struct node* temp = q->front;
    printf("Queue elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    int data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);
    display(&q);
    enqueue(&q, 50);
    display(&q);
    return 0;
}