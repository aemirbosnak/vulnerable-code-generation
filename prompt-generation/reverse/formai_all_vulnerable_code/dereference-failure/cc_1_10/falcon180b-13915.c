//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
}queue;

void init(queue* q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue* q, int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(q->front == NULL && q->rear == NULL){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(queue* q){
    node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);
    if(q->front == NULL){
        q->rear = NULL;
    }
    return data;
}

int peek(queue* q){
    if(q->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return q->front->data;
    }
}

int main(){
    queue q;
    init(&q);
    int choice, data;
    do{
        printf("\n\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if(data!= -1){
                    printf("\nDequeued data is: %d\n", data);
                }
                break;
            case 3:
                data = peek(&q);
                if(data!= -1){
                    printf("\nPeeked data is: %d\n", data);
                }
                break;
            case 4:
                printf("\nQueue is: ");
                node* temp = q.front;
                while(temp!= NULL){
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }while(choice!= 5);
    return 0;
}