//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Node structure for queue
struct node{
    int data;
    struct node* next;
};

//Function to create a new node with given data
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to check if the queue is empty
bool isEmpty(struct node* front){
    if(front == NULL)
        return true;
    else
        return false;
}

//Function to enqueue an element
void enqueue(struct node** front, int data){
    struct node* node = newNode(data);
    node->next = *front;
    *front = node;
}

//Function to dequeue an element
int dequeue(struct node** front){
    struct node* temp = *front;
    int data = temp->data;
    *front = temp->next;
    free(temp);
    return data;
}

//Function to display the queue
void display(struct node* front){
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
}

//Main function
int main(){
    struct node* front = NULL;

    //Enqueue elements
    enqueue(&front, 10);
    enqueue(&front, 20);
    enqueue(&front, 30);

    //Display the queue
    printf("Queue after enqueue: ");
    display(front);

    //Dequeue elements
    int dequeuedData = dequeue(&front);
    printf("\nDequeued element: %d\n", dequeuedData);

    //Display the queue after dequeue
    printf("Queue after dequeue: ");
    display(front);

    return 0;
}