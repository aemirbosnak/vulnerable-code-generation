//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    node* top;
}stack;

void push(stack* s, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = s->top;
    s->top = temp;
}

int pop(stack* s){
    int x = s->top->data;
    node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return x;
}

void display(stack s){
    node* temp = s.top;
    printf("\n");
    while(temp!= NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main(){
    stack s;
    s.top = NULL;
    int choice, element;

    do{
        printf("\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &element);
                push(&s, element);
                break;

            case 2:
                element = pop(&s);
                if(element!= -1)
                    printf("\nThe popped element is: %d\n", element);
                break;

            case 3:
                display(s);
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    }while(choice!= 4);

    return 0;
}