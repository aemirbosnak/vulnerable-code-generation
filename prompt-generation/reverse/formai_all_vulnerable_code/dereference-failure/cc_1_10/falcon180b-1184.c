//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

//queue structure definition
struct queue{
    struct node* front;
    struct node* rear;
};

//function to create an empty queue
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//function to check if the queue is empty
int isEmpty(struct queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

//function to enqueue an element into the queue
void enqueue(struct queue* q, int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
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

//function to dequeue an element from the queue
int dequeue(struct queue* q){
    int value;
    struct node* temp = q->front;

    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    value = temp->data;
    q->front = temp->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);

    return value;
}

//function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;

    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int value1 = dequeue(q);
    int value2 = dequeue(q);

    display(q);

    return 0;
}