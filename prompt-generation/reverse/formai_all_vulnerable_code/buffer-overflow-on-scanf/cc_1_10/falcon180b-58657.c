//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct{
    node* front;
    node* rear;
}queue;

void enqueue(queue* q,int data){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node==NULL){
        printf("Memory Error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if(q->rear==NULL){
        q->front = new_node;
        q->rear = new_node;
    }
    else{
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue* q){
    int data;
    node* temp = q->front;
    if(q->front==NULL){
        printf("Queue Underflow\n");
        exit(0);
    }
    data = q->front->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

void display(queue* q){
    node* temp = q->front;
    printf("Queue elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    queue q;
    int choice,data;
    do{
        printf("Enter 1 for Enqueue\n");
        printf("Enter 2 for Dequeue\n");
        printf("Enter 3 for Display\n");
        printf("Enter 4 to Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d",&data);
                enqueue(&q,data);
                break;
            case 2:
                data = dequeue(&q);
                printf("Dequeued element is: %d\n",data);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice!=4);
    return 0;
}