//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: modular
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

//Function to enqueue an element into the queue
void enqueue(struct queue* q, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    if(isEmpty(q))
        q->front = q->rear = temp;
    else
        q->rear->next = temp;
        q->rear = temp;
}

//Function to dequeue an element from the queue
int dequeue(struct queue* q){
    int data = -1;
    struct node* temp = q->front;

    if(!isEmpty(q)){
        data = temp->data;
        q->front = q->front->next;
        free(temp);
    }

    return data;
}

//Function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;
    printf("Queue elements are: ");

    if(isEmpty(q))
        printf("Empty\n");
    else{
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
    int choice, data;

    do{
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;

            case 2:
                data = dequeue(q);
                if(data!= -1)
                    printf("Dequeued element is: %d\n", data);
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 4);

    return 0;
}