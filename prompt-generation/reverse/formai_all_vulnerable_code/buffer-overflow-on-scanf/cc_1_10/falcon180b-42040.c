//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL && rear == NULL)
        front = rear = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    int value;
    Node* temp = front;
    value = front->data;
    front = front->next;
    free(temp);
    return value;
}

void display(){
    Node* temp = front;
    if(front == NULL)
        printf("\nQueue is empty\n");
    else{
        printf("\nQueue elements are: \n");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int choice, value;
    char ch;
    do{
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value!= -1)
                    printf("The dequeued value is: %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}