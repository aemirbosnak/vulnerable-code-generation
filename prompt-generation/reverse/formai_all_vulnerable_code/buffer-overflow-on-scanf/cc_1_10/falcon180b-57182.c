//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct queue{
    node *front;
    node *rear;
}queue;

void enqueue(queue *q,int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(q->front == NULL){
        q->front = newnode;
        q->rear = newnode;
    }else{
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(queue *q){
    int data;
    node *temp = q->front;
    if(q->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }else{
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

int peek(queue *q){
    int data;
    if(q->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }else{
        data = q->front->data;
    }
    return data;
}

int is_empty(queue *q){
    if(q->front == NULL){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    queue q;
    q.front = q.rear = NULL;
    int choice,data;
    do{
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Is Empty\n5. Exit\n");
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
                    printf("Dequeued element: %d\n",data);
                }
                break;
            case 3:
                data = peek(&q);
                if(data!= -1){
                    printf("Front element: %d\n",data);
                }
                break;
            case 4:
                if(is_empty(&q)){
                    printf("Queue is empty\n");
                }else{
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=5);
    return 0;
}