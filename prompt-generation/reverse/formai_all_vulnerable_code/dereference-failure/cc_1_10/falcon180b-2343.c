//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
    int count;
};

void initQueue(struct Queue* q){
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

int isEmpty(struct Queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct Queue* q){
    if(q->count == MAX_SIZE)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue* q, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
}

int dequeue(struct Queue* q){
    int data;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        exit(0);
    }
    else if(q->front == q->rear){
        struct Node* temp = q->front;
        data = temp->data;
        free(temp);
        q->front = NULL;
        q->rear = NULL;
        q->count--;
        return data;
    }
    else{
        struct Node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
        q->count--;
        return data;
    }
}

void display(struct Queue* q){
    struct Node* temp = q->front;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue Elements: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    printf("Dequeued Element: %d\n", dequeue(&q));
    printf("Dequeued Element: %d\n", dequeue(&q));
    printf("Dequeued Element: %d\n", dequeue(&q));
    printf("Dequeued Element: %d\n", dequeue(&q));
    printf("Dequeued Element: %d\n", dequeue(&q));
    display(&q);
    return 0;
}