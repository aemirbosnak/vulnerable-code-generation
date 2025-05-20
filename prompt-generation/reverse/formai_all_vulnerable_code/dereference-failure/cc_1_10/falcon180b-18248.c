//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = new_node;
        printf("\nQueue is empty, %d is added to the queue", data);
    }
    else if(rear == NULL){
        rear = new_node;
        printf("\n%d is added to the rear of the queue", data);
    }
    else{
        printf("\n%d is added to the queue", data);
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(){
    node* temp = front;
    if(front == NULL && rear == NULL){
        printf("\nQueue is empty");
    }
    else if(front == NULL){
        printf("\n%d is removed from the rear of the queue", rear->data);
        rear = NULL;
        front = NULL;
    }
    else{
        printf("\n%d is removed from the front of the queue", front->data);
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
    }
    free(temp);
}

void display(){
    node* temp = front;
    if(front == NULL && rear == NULL){
        printf("\nQueue is empty");
    }
    else{
        printf("\nElements in the queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(40);
    display();
    return 0;
}