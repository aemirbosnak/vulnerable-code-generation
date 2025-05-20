//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    if(front == NULL){
        front = new_node;
        rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(){
    node* temp = front;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    free(temp);
}

void display(){
    node* temp = front;

    if(front == NULL){
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue Elements are:\n");
        while(temp!= NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int choice, data;

    do{
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
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