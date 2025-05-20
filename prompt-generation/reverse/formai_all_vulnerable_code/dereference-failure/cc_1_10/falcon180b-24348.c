//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

//Node structure for queue
struct Node{
    int data;
    struct Node* next;
};

//Queue structure
struct Queue{
    struct Node* front;
    struct Node* rear;
};

//Function to create an empty queue
void createQueue(struct Queue* q){
    q->front=NULL;
    q->rear=NULL;
}

//Function to check if the queue is empty
int isEmpty(struct Queue* q){
    if(q->front==NULL && q->rear==NULL)
        return 1;
    else
        return 0;
}

//Function to add an element to the rear of the queue
void enqueue(struct Queue* q,int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
        printf("Heap overflow\n");
    else{
        newNode->data=value;
        newNode->next=NULL;
        if(isEmpty(q))
            q->front=q->rear=newNode;
        else
            q->rear->next=newNode;
        q->rear=newNode;
    }
}

//Function to remove an element from the front of the queue
int dequeue(struct Queue* q){
    int value;
    struct Node* temp=q->front;
    if(isEmpty(q))
        printf("Queue Underflow\n");
    else{
        value=q->front->data;
        q->front=q->front->next;
        if(q->front==NULL)
            q->rear=NULL;
        free(temp);
    }
    return value;
}

//Function to display the elements in the queue
void display(struct Queue* q){
    struct Node* temp=q->front;
    if(isEmpty(q))
        printf("Queue is empty\n");
    else{
        printf("Elements in the queue are:\n");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    struct Queue q;
    createQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(&q);
    printf("\nElement dequeued: %d\n",dequeue(&q));
    display(&q);
    return 0;
}