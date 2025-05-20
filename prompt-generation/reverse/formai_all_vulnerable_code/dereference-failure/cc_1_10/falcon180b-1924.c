//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node* next;
};

//Queue structure definition
struct queue{
    struct node* front;
    struct node* rear;
};

//Function to create an empty queue
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//Function to check if the queue is empty
int isEmpty(struct queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

//Function to enqueue an element
void enqueue(struct queue* q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if(isEmpty(q))
        q->front = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
}

//Function to dequeue an element
int dequeue(struct queue* q){
    int value;
    struct node* temp = q->front;

    if(isEmpty(q))
        printf("Queue is empty!");
    else{
        value = q->front->data;
        q->front = q->front->next;
        free(temp);
    }

    return value;
}

//Function to display the queue
void display(struct queue* q){
    struct node* temp = q->front;

    if(isEmpty(q))
        printf("Queue is empty!");
    else{
        printf("Queue: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Main function
int main(){
    struct queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    display(q);

    return 0;
}