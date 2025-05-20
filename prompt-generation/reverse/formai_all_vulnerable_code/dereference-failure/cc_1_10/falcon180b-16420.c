//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

//Node structure for linked list
struct node{
    int data;
    struct node* next;
};

//Queue structure using linked list
struct queue{
    struct node* front;
    struct node* rear;
};

//Function to create an empty queue
void createQueue(struct queue* q){
    q->front=NULL;
    q->rear=NULL;
}

//Function to check if the queue is empty
int isEmpty(struct queue* q){
    if(q->front==NULL && q->rear==NULL)
        return 1;
    else
        return 0;
}

//Function to enqueue an element
void enqueue(struct queue* q, int element){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=element;
    newNode->next=NULL;
    if(isEmpty(q))
        q->front=newNode;
    else
        q->rear->next=newNode;
    q->rear=newNode;
}

//Function to dequeue an element
int dequeue(struct queue* q){
    int element;
    struct node* temp=q->front;
    if(isEmpty(q))
        printf("Queue is empty");
    else{
        element=q->front->data;
        q->front=q->front->next;
        free(temp);
    }
    return element;
}

//Function to display the queue
void displayQueue(struct queue* q){
    struct node* temp=q->front;
    printf("Queue: ");
    if(isEmpty(q))
        printf("Empty");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    struct queue q;
    createQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    displayQueue(&q);
    printf("\nDequeued element: %d",dequeue(&q));
    displayQueue(&q);
    printf("\nDequeued element: %d",dequeue(&q));
    displayQueue(&q);
    return 0;
}