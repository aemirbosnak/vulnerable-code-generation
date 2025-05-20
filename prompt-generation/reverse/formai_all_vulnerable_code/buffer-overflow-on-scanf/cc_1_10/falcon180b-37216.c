//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

typedef struct node{
    int data;
    struct node* next;
}node;

node *front = NULL, *rear = NULL;

void enqueue(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;
        return;
    }
    else if(front == NULL){
        rear = newnode;
        front = newnode;
        return;
    }
    else if(rear == NULL){
        front = newnode;
        rear = newnode;
        return;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        return;
    }
}

void dequeue(){
    node *temp = front;
    front = front->next;
    free(temp);
    if(front == NULL){
        rear = NULL;
    }
}

void display(){
    node *temp = front;
    printf("Elements in the Queue are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, value;
    do{
        printf("Enter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Display\n");
        printf("Enter 4 to Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be Enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }while(1);
    return 0;
}