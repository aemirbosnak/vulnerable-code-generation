//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

//node structure for queue
struct node{
    int data;
    struct node* link;
};

struct node* front = NULL; //front of queue
struct node* rear = NULL; //rear of queue

//function to create a new node
struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

//function to add an element to the rear of queue
void enqueue(int data){
    struct node* new_node = create_node(data);
    if(front == NULL){
        front = new_node;
        rear = new_node;
        return;
    }
    rear->link = new_node;
    rear = new_node;
}

//function to remove an element from the front of queue
void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    front = front->link;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

//function to display the elements of queue
void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Elements of queue are:\n");
    struct node* temp = front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

//main function
int main(){
    int choice, data;
    while(1){
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue:\n");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
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