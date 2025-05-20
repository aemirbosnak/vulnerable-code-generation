//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

//Node structure for Queue
struct node{
    int data;
    struct node* next;
};

//Linked List implementation of Queue
struct node* front = NULL;
struct node* rear = NULL;

//Function to create an empty queue
void create(){
    front = rear = NULL;
}

//Function to check if the queue is empty
int isEmpty(){
    if(front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}

//Function to add an element to the rear of the queue
void enqueue(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    if(isEmpty()){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

//Function to remove an element from the front of the queue
int dequeue(){
    int value;
    struct node* temp = front;
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(0);
    }
    else{
        value = front->data;
        front = front->next;
        free(temp);
    }
    return value;
}

//Function to display the elements in the queue
void display(){
    struct node* temp = front;
    if(isEmpty()){
        printf("Queue is Empty\n");
    }
    else{
        printf("Elements in the Queue are:\n");
        while(temp!= NULL){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Main function
int main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                printf("The dequeued value is: %d\n",value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}