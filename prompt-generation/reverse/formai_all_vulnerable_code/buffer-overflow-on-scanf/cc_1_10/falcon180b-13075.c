//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

//function to create an empty queue
void create()
{
    front = rear = NULL;
}

//function to check if the queue is empty
int is_empty()
{
    if(front == NULL)
        return 1;
    else
        return 0;
}

//function to check if the queue is full
int is_full()
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL)
        return 1;
    else{
        free(temp);
        return 0;
    }
}

//function to add an element to the queue
void enqueue(int value)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Queue Overflow\n");
        return;
    }

    temp->data = value;
    temp->next = NULL;

    if(is_empty())
        front = rear = temp;
    else
        rear->next = temp;

    rear = temp;
}

//function to remove an element from the queue
int dequeue()
{
    int value;
    struct node* temp;

    if(is_empty()){
        printf("Queue Underflow\n");
        return -1;
    }

    temp = front;
    value = temp->data;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    return value;
}

//function to display the elements in the queue
void display()
{
    struct node* temp = front;

    if(is_empty())
        printf("Queue is empty\n");
    else{
        printf("Elements in the queue are:\n");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

//main function
int main()
{
    int choice, value;

    create();

    do{
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to be added: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if(value!= -1)
                    printf("The removed element is %d\n", value);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }while(1);

    return 0;
}