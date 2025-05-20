//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

//Defining the structure of a node
typedef struct node{
    int data;
    struct node *next;
}node;

//Defining the structure of a queue
typedef struct queue{
    node *front;
    node *rear;
}queue;

//Function to create an empty queue
void createQueue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

//Function to add an element to the rear of the queue
void enqueue(queue *q, int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = newnode;
    }
    else{
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

//Function to remove an element from the front of the queue
void dequeue(queue *q){
    if(q->front == NULL){
        printf("Queue is empty!\n");
    }
    else{
        node *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

//Function to display the elements of the queue
void display(queue *q){
    node *temp = q->front;
    if(q->front == NULL){
        printf("Queue is empty!\n");
    }
    else{
        printf("Elements in the queue are: ");
        while(temp!= NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Main function to test the implementation
int main(){
    queue q;
    createQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}