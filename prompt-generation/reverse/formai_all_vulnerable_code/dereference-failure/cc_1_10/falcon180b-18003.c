//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node* next;
};

//Function to create a new node with given data
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to add an element to the rear of the queue
void enqueue(struct node** frontRef, struct node** rearRef, int data){
    struct node* newNode = createNode(data);

    if(*frontRef == NULL){
        *frontRef = newNode;
        *rearRef = newNode;
    }
    else{
        (*rearRef)->next = newNode;
        *rearRef = newNode;
    }
}

//Function to remove an element from the front of the queue
int dequeue(struct node** frontRef, struct node** rearRef){
    struct node* temp = *frontRef;
    int data = temp->data;

    if(*frontRef!= NULL){
        *frontRef = (*frontRef)->next;

        if(*frontRef == NULL){
            *rearRef = NULL;
        }
    }

    free(temp);
    return data;
}

//Function to display the elements in the queue
void display(struct node* front){
    printf("Queue elements are: ");
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main(){
    struct node* front = NULL;
    struct node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    display(front);

    dequeue(&front, &rear);
    dequeue(&front, &rear);

    display(front);

    return 0;
}