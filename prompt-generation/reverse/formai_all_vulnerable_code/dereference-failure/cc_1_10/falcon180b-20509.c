//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include<stdio.h>
#include<stdlib.h>

//Node Structure
typedef struct node{
    int data;
    struct node *next;
} Node;

//Stack Structure
typedef struct stack{
    Node *top;
} Stack;

//Function to create an empty stack
Stack *create_stack(){
    Stack *stack=(Stack *)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}

//Function to check if stack is empty
int is_empty(Stack *stack){
    if(stack->top==NULL)
        return 1;
    else
        return 0;
}

//Function to push an element onto the stack
void push(Stack *stack,int data){
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=stack->top;
    stack->top=new_node;
}

//Function to pop an element from the stack
int pop(Stack *stack){
    if(is_empty(stack))
        return -1;
    else{
        Node *temp=stack->top;
        int data=temp->data;
        stack->top=temp->next;
        free(temp);
        return data;
    }
}

//Function to display the stack
void display(Stack *stack){
    Node *temp=stack->top;
    if(is_empty(stack))
        printf("Stack is empty\n");
    else{
        printf("Stack elements are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

//Main Function
int main(){
    Stack *stack=create_stack();
    int choice,data;

    do{
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&data);
                push(stack,data);
                break;

            case 2:
                data=pop(stack);
                if(data==-1)
                    printf("Stack is empty\n");
                else
                    printf("Popped element is: %d\n",data);
                break;

            case 3:
                display(stack);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }while(choice!=4);

    return 0;
}