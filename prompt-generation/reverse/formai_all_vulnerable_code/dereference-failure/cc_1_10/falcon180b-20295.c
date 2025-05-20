//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

/* node structure */
struct node{
    int data;
    struct node* next;
};

/* create an empty queue */
struct node* createQueue(){
    struct node* queue = (struct node*)malloc(sizeof(struct node));
    if(queue == NULL){
        printf("Memory error\n");
        return NULL;
    }
    queue->next = NULL;
    return queue;
}

/* check if the queue is empty */
int isEmpty(struct node* queue){
    if(queue == NULL || queue->next == NULL){
        return 1;
    }
    return 0;
}

/* add an element to the end of the queue */
void enqueue(struct node** front, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if(*front == NULL){
        *front = newNode;
        return;
    }
    struct node* temp = *front;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

/* remove an element from the front of the queue */
int dequeue(struct node** front){
    if(isEmpty(*front)){
        printf("Queue is empty\n");
        return -1;
    }
    struct node* temp = *front;
    *front = (*front)->next;
    int data = temp->data;
    free(temp);
    return data;
}

/* display the contents of the queue */
void display(struct node* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = queue;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node* queue = createQueue();
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    display(queue);
    int data = dequeue(&queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    data = dequeue(&queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    data = dequeue(&queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    return 0;
}