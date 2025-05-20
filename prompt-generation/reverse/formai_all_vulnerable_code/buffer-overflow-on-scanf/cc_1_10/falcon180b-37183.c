//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int value){
    node* new_node = (node*)malloc(sizeof(node));

    if(new_node == NULL){
        printf("Memory error\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if(front == NULL && rear == NULL){
        front = new_node;
        rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }

    printf("%d enqueued to the queue\n", value);
}

int dequeue(){
    int value = -1;

    if(front == NULL){
        printf("Queue is empty\n");
        return value;
    }

    node* temp = front;
    value = front->data;
    front = front->next;

    free(temp);

    if(front == NULL){
        rear = NULL;
    }

    printf("%d dequeued from the queue\n", value);

    return value;
}

void display(){
    node* temp = front;

    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue are: ");

    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(){
    int choice, value;

    do{
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if(value!= -1){
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 4);

    return 0;
}