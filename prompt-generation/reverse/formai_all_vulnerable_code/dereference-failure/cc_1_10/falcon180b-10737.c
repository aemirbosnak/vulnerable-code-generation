//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct stack{
    node *top;
}stack;

void push(stack *s, int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(s->top == NULL){
        s->top = newnode;
    }
    else{
        newnode->next = s->top;
        s->top = newnode;
    }
}

int pop(stack *s){
    node *temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

void display(stack s){
    node *temp = s.top;
    printf("Stack elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    stack s;
    s.top = NULL;
    int choice, data;

    do{
        printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&s, data);
                break;

            case 2:
                data = pop(&s);
                if(data!= -1){
                    printf("The popped element is %d\n", data);
                }
                else{
                    printf("Stack is empty\n");
                }
                break;

            case 3:
                display(s);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 4);

    return 0;
}