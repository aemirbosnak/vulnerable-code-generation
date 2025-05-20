//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node* next;
};

//Queue structure definition
struct queue{
    struct node* front;
    struct node* rear;
};

//Function to create an empty queue
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    if(q == NULL){
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    return q;
}

//Function to check if the queue is empty
int isEmpty(struct queue* q){
    return q->front == NULL;
}

//Function to check if the queue is full
int isFull(struct queue* q){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory error\n");
        exit(0);
    }
    if(q->rear == NULL){
        q->front = q->rear = temp;
        temp->next = NULL;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
        temp->next = NULL;
    }
    free(temp);
    return 0;
}

//Function to add an element to the queue
void enqueue(struct queue* q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory error\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    if(isEmpty(q)){
        q->front = q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
    free(temp);
}

//Function to remove an element from the queue
int dequeue(struct queue* q){
    int value;
    struct node* temp = q->front;
    if(isEmpty(q)){
        printf("Queue is empty\n");
        exit(0);
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

//Function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;
    if(isEmpty(q)){
        printf("Queue is empty\n");
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

//Main function
int main(){
    struct queue* q = createQueue();
    int choice, value;

    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                value = dequeue(q);
                if(value!= -1){
                    printf("The dequeued value is: %d\n", value);
                }
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}