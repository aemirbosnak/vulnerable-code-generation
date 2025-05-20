//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *top = NULL;

int push(int value){
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    if(temp == NULL){
        printf("malloc failed to allocate memory");
        return 0;
    }
    temp->data = value;
    temp->next = top;
    top = temp;
    return 1;
}

int pop(){
    NODE *temp;
    int n;
    if(top == NULL){
        printf("stack underflow");
        return 0;
    }
    temp = top;
    top = top->next;
    n = temp->data;
    free(temp);
    return n;
}

int display(){
    NODE *temp;
    if(top == NULL){
        printf("stack is empty");
        return 0;
    }
    temp = top;
    printf("\nstack elements are:\n");
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    return 1;
}

void main(){
    int choice, value;
    do{
        printf("\n***********Cyberpunk Stack Menu***********\n");
        printf("\nchoose an option from the menu below\n");
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the value to be pushed : ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4: 
                printf("\nExiting from the program...\n");
                exit(0);
            default:
                printf("\nChoose a valid option!\n");
        }
    }while(choice != 4);
}