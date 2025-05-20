//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

//Defining the structure of a node in the queue
typedef struct node{
    int data;
    struct node* next;
}node;

//Creating the queue
void createQueue(node** front, node** rear){
    *front = NULL;
    *rear = NULL;
}

//Checking if the queue is empty
int isEmpty(node* front){
    return front == NULL;
}

//Adding an element to the end of the queue
void enqueue(node** front, node** rear, int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if(isEmpty(*front)){
        *front = temp;
        *rear = temp;
    }else{
        (*rear)->next = temp;
        *rear = temp;
    }
}

//Removing an element from the front of the queue
int dequeue(node** front, node** rear){
    node* temp = *front;
    int data = temp->data;
    free(temp);

    if(*front == NULL){
        *front = NULL;
        *rear = NULL;
    }else{
        *front = (*front)->next;
    }

    return data;
}

//Printing the elements of the queue
void printQueue(node* front){
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
}

int main(){
    node* front, *rear;
    createQueue(&front, &rear);

    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 15);
    enqueue(&front, &rear, 20);

    printf("Queue: ");
    printQueue(front);

    int data = dequeue(&front, &rear);
    printf("\nDequeued element: %d", data);
    printf("Queue after dequeue: ");
    printQueue(front);

    return 0;
}