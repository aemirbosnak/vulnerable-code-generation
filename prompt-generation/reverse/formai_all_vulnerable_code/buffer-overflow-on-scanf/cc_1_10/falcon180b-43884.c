//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node{
    int data;
    struct node* next;
}node;

// Queue structure definition
typedef struct{
    node* front;
    node* rear;
}queue;

// Function for creating a new node with given data
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function for creating an empty queue
queue* createQueue(){
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function for checking if the queue is empty
int isEmpty(queue* q){
    return (q->front == NULL);
}

// Function for adding an element to the rear of the queue
void enqueue(queue* q, int data){
    node* newNode = createNode(data);
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function for removing an element from the front of the queue
int dequeue(queue* q){
    int data;
    node* tempNode;
    if(isEmpty(q)){
        printf("Underflow\n");
        return -1;
    }
    else{
        tempNode = q->front;
        data = tempNode->data;
        q->front = q->front->next;
        free(tempNode);
    }
    return data;
}

// Function for displaying the elements of the queue
void display(queue* q){
    node* tempNode = q->front;
    printf("Queue elements are: ");
    while(tempNode!= NULL){
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main(){
    queue* q = createQueue();
    int choice, data;

    do{
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data to be added: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                if(data!= -1)
                    printf("The removed element is: %d\n", data);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 4);

    return 0;
}