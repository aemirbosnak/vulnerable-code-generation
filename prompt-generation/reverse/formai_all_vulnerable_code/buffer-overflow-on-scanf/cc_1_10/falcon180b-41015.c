//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

//declaration of front and rear global variables
struct node* front = NULL;
struct node* rear = NULL;

//function to create a new node with given data
struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//function to add an element to the rear of the queue
void enqueue(int data){
    struct node* new_node = create_node(data);
    if(rear == NULL){
        front = rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

//function to remove an element from the front of the queue
int dequeue(){
    int data;
    struct node* temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
        exit(0);
    }
    data = front->data;
    front = front->next;
    free(temp);
    return data;
}

//function to display the elements of the queue
void display(){
    struct node* temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements of the queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//main function
int main(){
    int choice, data;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("The dequeued element is: %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}