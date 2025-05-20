//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

void initQueue(struct queue* q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct queue* q, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct queue* q){
    int data;
    struct node* temp = q->front;
    if(q->front == NULL){
        printf("Queue is empty\n");
        exit(0);
    }
    else if(q->front == q->rear){
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else{
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

void display(struct queue* q){
    struct node* temp = q->front;
    if(q->front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int choice, data;
    struct queue q;
    initQueue(&q);
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                printf("Dequeued data is: %d\n", data);
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