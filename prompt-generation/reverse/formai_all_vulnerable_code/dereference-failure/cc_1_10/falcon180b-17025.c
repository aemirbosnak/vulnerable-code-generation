//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
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
    q->front = q->rear = NULL;
    return q;
}

//Function to check if the queue is empty
int isEmpty(struct queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

//Function to add an element to the rear of the queue
void enqueue(struct queue* q, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(isEmpty(q))
        q->front = temp;
    else
        q->rear->next = temp;
    q->rear = temp;
}

//Function to remove an element from the front of the queue
int dequeue(struct queue* q){
    int data;
    struct node* temp = q->front;
    if(isEmpty(q))
        printf("Queue Underflow\n");
    else{
        data = temp->data;
        q->front = temp->next;
        free(temp);
    }
    return data;
}

//Function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;
    printf("Queue: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main function
int main(){
    struct queue* q = createQueue();
    int choice, data;

    do{
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;

            case 2:
                data = dequeue(q);
                if(data!= -1)
                    printf("The dequeued element is: %d\n", data);
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }while(1);

    return 0;
}