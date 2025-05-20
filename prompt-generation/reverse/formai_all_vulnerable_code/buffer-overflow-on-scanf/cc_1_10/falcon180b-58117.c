//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//node structure
struct node{
    int data;
    struct node* next;
};

//queue structure
struct queue{
    struct node* front;
    struct node* rear;
};

//function to create an empty queue
void createQueue(struct queue* q){
    q->front = q->rear = NULL;
}

//function to add an element to the rear of the queue
void enqueue(struct queue* q, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Queue overflow\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

//function to remove an element from the front of the queue
int dequeue(struct queue* q){
    int data;
    struct node* temp = q->front;
    if(q->front == NULL){
        printf("Queue underflow\n");
        exit(0);
    }
    data = q->front->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

//function to display the queue
void displayQueue(struct queue* q){
    struct node* temp = q->front;
    if(q->front == NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//main function
int main(){
    int choice, data;
    struct queue q;
    createQueue(&q);
    while(1){
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if(data!= -1){
                    printf("The element removed is: %d\n", data);
                }
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}