//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
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
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

//function to check if the queue is empty
int isEmpty(struct queue* q){
    return (q->front == NULL);
}

//function to add an element to the rear of the queue
void enqueue(struct queue* q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(isEmpty(q)){
        q->front = q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

//function to remove an element from the front of the queue
int dequeue(struct queue* q){
    int value;
    struct node* temp = q->front;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        value = temp->data;
        q->front = temp->next;
        free(temp);
        return value;
    }
}

//function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        printf("Elements in the Queue are:\n");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

//main function
int main(){
    struct queue* q = createQueue();
    int choice, value;

    while(1){
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
                enqueue(q, value);
                break;

            case 2:
                value = dequeue(q);
                if(value!= -1){
                    printf("The dequeued element is: %d\n", value);
                }
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}