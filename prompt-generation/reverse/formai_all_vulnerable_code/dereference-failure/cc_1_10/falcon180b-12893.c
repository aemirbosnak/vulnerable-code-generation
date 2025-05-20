//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

//Node structure
typedef struct node{
    int data;
    struct node* next;
}node;

//Queue structure
typedef struct queue{
    node* front;
    node* rear;
}queue;

//Function for creating an empty queue
queue* createQueue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//Function for checking if the queue is empty
int isEmpty(queue* q){
    return q->front == NULL;
}

//Function for adding an element at the rear of the queue
void enqueue(queue* q, int data){
    node* newNode = (node*)malloc(sizeof(node));
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

//Function for removing an element from the front of the queue
int dequeue(queue* q){
    node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);
    if(isEmpty(q)){
        q->rear = NULL;
    }
    return data;
}

//Function for printing the elements of the queue
void printQueue(queue* q){
    node* temp = q->front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printQueue(q);
    enqueue(q, 40);
    printQueue(q);
    return 0;
}