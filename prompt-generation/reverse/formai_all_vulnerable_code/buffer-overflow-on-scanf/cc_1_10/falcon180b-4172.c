//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// node structure definition
typedef struct node{
    int data;
    struct node* next;
}node;

// queue structure definition
typedef struct{
    node *front;
    node *rear;
}queue;

// function to create an empty queue
void create_queue(queue* q){
    q->front = q->rear = NULL;
}

// function to check if the queue is empty
int is_empty(queue* q){
    if(q->front == NULL && q->rear == NULL)
        return TRUE;
    else
        return FALSE;
}

// function to check if the queue is full
int is_full(queue* q){
    node* temp = (node*)malloc(sizeof(node)); // create a temporary node
    if(temp == NULL)
        return TRUE;
    else{
        free(temp); // free the temporary node
        return FALSE;
    }
}

// function to add an element to the queue
void enqueue(queue* q, int value){
    node* temp = (node*)malloc(sizeof(node)); // create a new node
    if(temp == NULL){
        printf("Error: Unable to enqueue element.\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if(is_empty(q)){
        q->front = q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

// function to remove an element from the queue
int dequeue(queue* q){
    int value = -1;
    node* temp = q->front;
    if(is_empty(q)){
        printf("Error: Unable to dequeue element as the queue is empty.\n");
    }
    else if(q->front == q->rear){
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    }
    else{
        value = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return value;
}

// function to display the elements in the queue
void display(queue* q){
    node* temp = q->front;
    if(is_empty(q)){
        printf("Queue is empty.\n");
    }
    else{
        printf("Elements in the queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// main function
int main(){
    queue q;
    create_queue(&q);
    int choice, value;

    do{
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if(value!= -1)
                    printf("The dequeued value is: %d\n", value);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!= 4);

    return 0;
}