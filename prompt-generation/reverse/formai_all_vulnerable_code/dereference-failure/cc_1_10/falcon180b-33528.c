//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node* next;
};

//Queue structure definition
struct Queue{
    struct node* front;
    struct node* rear;
};

//Function to create an empty queue
void createQueue(struct Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

//Function to check if the queue is empty
int isEmpty(struct Queue q){
    if(q.front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to check if the queue is full
int isFull(struct Queue q){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
        return 1;
    }
    else{
        free(temp);
        return 0;
    }
}

//Function to add an element to the queue
void enqueue(struct Queue* q, int value){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(isEmpty(*q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

//Function to remove an element from the queue
int dequeue(struct Queue* q){
    int value;
    struct node* temp;
    if(isEmpty(*q)){
        printf("Queue is Empty.\n");
        return -1;
    }
    else{
        temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        free(temp);
        return value;
    }
}

//Function to display the elements in the queue
void display(struct Queue q){
    struct node* temp = q.front;
    printf("Queue elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    printf("Queue elements after dequeue are: ");
    display(q);
    return 0;
}