//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

void push(struct Stack* stack, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Juliet: Oh sweet Romeo! Your value %d has been added to our stack!\n", value);
}

void pop(struct Stack* stack){
    if(stack->top == NULL){
        printf("Juliet: Oh Romeo! You cannot pop an empty stack!\n");
    } else {
        struct Node* temp = stack->top;
        int value = temp->data;
        stack->top = stack->top->next;
        printf("Romeo: Ah, my sweet Juliet! I have removed the value %d from our stack!\n", value);
        free(temp);
    }
}

void display(struct Stack* stack){
    if(stack->top == NULL){
        printf("Juliet: Oh Romeo! Our stack is currently empty!\n");
    } else {
        printf("Juliet: Our stack currently contains: ");
        struct Node* temp = stack->top;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct Stack stack;
    stack.top = NULL;
    int choice, value;
    printf("Juliet: Oh Romeo! Welcome to our stack visualization program!\n");
    do{
        printf("Romeo: My sweet Juliet, what shall we do with our stack?\n");
        printf("1. Push a value\n2. Pop a value\n3. Display the stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Romeo: My beautiful Juliet, what value would you like to push?\n");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Juliet: Oh Romeo! Our time here is over, farewell my love!\n");
                break;
            default:
                printf("Juliet: Oh Romeo! That is not a valid choice!\n");
                break;
        }
    } while(choice != 4);
    return 0;
}