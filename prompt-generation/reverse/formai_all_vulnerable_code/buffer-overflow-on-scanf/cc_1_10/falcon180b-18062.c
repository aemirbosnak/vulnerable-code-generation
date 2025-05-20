//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

typedef struct{
    int data;
    int next;
}node;

typedef struct{
    node *head;
    node *tail;
}queue;

void enqueue(queue *q,int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(q->head == NULL){
        q->head = newnode;
        q->tail = newnode;
    }else{
        q->tail->next = newnode;
        q->tail = newnode;
    }
}

int dequeue(queue *q){
    if(q->head == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    node *temp = q->head;
    int data = temp->data;
    q->head = temp->next;
    free(temp);
    if(q->head == NULL){
        q->tail = NULL;
    }
    return data;
}

void display(queue *q){
    node *temp = q->head;
    printf("Queue: ");
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    queue q;
    q.head = NULL;
    q.tail = NULL;
    int choice,data;
    while(1){
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d",&data);
                enqueue(&q,data);
                break;
            case 2:
                data = dequeue(&q);
                if(data!= -1){
                    printf("Dequeued data: %d\n",data);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}