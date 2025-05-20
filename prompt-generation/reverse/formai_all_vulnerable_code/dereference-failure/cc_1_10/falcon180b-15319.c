//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

//Node structure definition
struct Node{
    int data;
    struct Node* next;
};

//Queue structure definition
struct Queue{
    struct Node* front;
    struct Node* rear;
};

//Function to create an empty queue
void createQueue(struct Queue* queue){
    queue->front = NULL;
    queue->rear = NULL;
}

//Function to check if the queue is empty
int isEmpty(struct Queue queue){
    if(queue.front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(*queue)){
        queue->front = newNode;
        queue->rear = newNode;
    }
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

//Function to remove an element from the front of the queue
int dequeue(struct Queue* queue){
    int data;
    struct Node* temp = queue->front;

    if(isEmpty(*queue)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        data = temp->data;
        queue->front = temp->next;
        free(temp);
        return data;
    }
}

//Function to display the elements in the queue
void display(struct Queue queue){
    struct Node* temp = queue.front;

    if(isEmpty(queue)){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements in the queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct Queue queue;
    createQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(queue);

    int removedElement = dequeue(&queue);
    printf("Removed element is: %d\n", removedElement);

    display(queue);

    return 0;
}