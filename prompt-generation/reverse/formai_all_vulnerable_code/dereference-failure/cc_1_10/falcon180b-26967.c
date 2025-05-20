//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

//function to create a new node with given data
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to add an element to the rear of the queue
void enqueue(struct node** front, struct node** rear, int data){
    struct node* newNode = createNode(data);
    if(*rear == NULL){
        *front = newNode;
        *rear = newNode;
    }
    else{
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

//function to remove an element from the front of the queue
int dequeue(struct node** front, struct node** rear){
    struct node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    free(temp);
    if(*front == NULL){
        *rear = NULL;
    }
    return data;
}

//function to display the elements of the queue
void display(struct node* front){
    printf("Queue elements are: ");
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

//main function
int main(){
    struct node* front = NULL;
    struct node* rear = NULL;

    //testing enqueue operation
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 50);

    //testing dequeue operation
    printf("Dequeued element is: %d\n", dequeue(&front, &rear));
    printf("Dequeued element is: %d\n", dequeue(&front, &rear));

    //testing display operation
    printf("Queue elements after dequeue operations are: ");
    display(front);

    return 0;
}