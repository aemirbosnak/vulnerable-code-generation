//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    char ch;
    int x = 0;
    struct node* temp = top;
    if(temp == NULL){
        printf("Stack Underflow\n");
        exit(0);
    }
    else{
        x = temp->data;
        top = top->next;
        free(temp);
    }
    return x;
}

int peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        exit(0);
    }
    else{
        return top->data;
    }
}

void display(){
    struct node* temp = top;
    if(temp == NULL){
        printf("Stack is empty\n");
        exit(0);
    }
    else{
        printf("Stack elements are:\n");
        while(temp!= NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

void main(){
    int choice,x;
    do{
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                x = pop();
                printf("Popped element is: %d\n",x);
                break;
            case 3:
                x = peek();
                printf("Peeked element is: %d\n",x);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 5);
}