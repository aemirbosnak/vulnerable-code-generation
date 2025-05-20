//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//node structure
typedef struct node{
    int data;
    struct node *next;
}Node;

//queue structure
typedef struct queue{
    Node *front;
    Node *rear;
}Queue;

//function to create an empty queue
Queue *createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//function to check if the queue is empty
int isEmpty(Queue *q){
    if(q->front == NULL && q->rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//function to enqueue an element
void enqueue(Queue *q, int data){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if(isEmpty(q)){
        q->front = newnode;
        q->rear = newnode;
    }
    else{
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

//function to dequeue an element
int dequeue(Queue *q){
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

//function to display the elements in the queue
void display(Queue *q){
    Node *temp = q->front;
    printf("Queue elements are:\n");
    while(temp!= NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue *q = createQueue();
    int choice, data;
    do{
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be enqueued:\n");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                if(data!= -1){
                    printf("The dequeued element is %d\n", data);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(1);
    return 0;
}