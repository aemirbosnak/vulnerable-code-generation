//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//Node structure for the Queue
typedef struct node{
    int data;
    struct node* next;
}node;

//Queue structure
typedef struct queue{
    node* front;
    node* rear;
}queue;

//Function to create an empty Queue
void createQueue(queue* q){
    q->front = NULL;
    q->rear = NULL;
}

//Function to check if the Queue is empty or not
int isEmpty(queue* q){
    if(q->front == NULL && q->rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to add an element to the rear of the Queue
void enQueue(queue* q, int data){
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

//Function to remove an element from the front of the Queue
int deQueue(queue* q){
    int data;
    node* temp = q->front;

    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }

    return data;
}

//Function to display the Queue
void display(queue* q){
    node* temp = q->front;

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    queue q;
    createQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);

    printf("Queue elements after enQueue operations are:\n");
    display(&q);

    int frontElement = deQueue(&q);
    printf("Front element removed from Queue is: %d\n", frontElement);

    printf("Queue elements after deQueue operation are:\n");
    display(&q);

    return 0;
}