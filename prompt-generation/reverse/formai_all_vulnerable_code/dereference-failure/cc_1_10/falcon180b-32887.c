//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct node{
    int data;
    struct node* next;
};

// Queue structure definition
struct queue{
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
void createQueue(struct queue* q){
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q){
    return q->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(struct queue* q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if(isEmpty(q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue* q){
    int value = -1;
    struct node* temp = q->front;

    if(!isEmpty(q)){
        value = temp->data;
        q->front = temp->next;

        if(q->front == NULL){
            q->rear = NULL;
        }

        free(temp);
    }

    return value;
}

// Function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements in the queue are:\n");

        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

// Main function
int main(){
    struct queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);

    display(&q);

    value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);

    display(&q);

    value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);

    display(&q);

    value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);

    return 0;
}