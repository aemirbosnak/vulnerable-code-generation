//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

//queue structure definition
struct queue{
    struct node* front;
    struct node* rear;
};

//function to create an empty queue
void createQueue(struct queue* q){
    q->front = q->rear = NULL;
}

//function to check if the queue is empty
int isEmpty(struct queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

//function to add an element to the rear end of the queue
void enqueue(struct queue* q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if(isEmpty(q))
        q->front = q->rear = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
}

//function to remove an element from the front end of the queue
int dequeue(struct queue* q){
    int value;
    struct node* temp;

    if(isEmpty(q))
        printf("\nQueue is empty!");
    else{
        temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        free(temp);
    }

    return value;
}

//function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;

    if(isEmpty(q))
        printf("\nQueue is empty!");
    else{
        printf("\nElements in the queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

//main function
int main(){
    int choice, value;
    struct queue q;

    createQueue(&q);

    do{
        printf("\n\nMENU\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to be added to the queue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if(value!= -1)
                    printf("\nThe dequeued element is: %d", value);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }while(choice!= 4);

    return 0;
}