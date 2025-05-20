//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

//node structure
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

//stack structure
typedef struct stack{
    node* top;
    node* bottom;
    int size;
}stack;

//function to create a stack
stack* create_stack(int size){
    stack* s=(stack*)malloc(sizeof(stack));
    s->top=NULL;
    s->bottom=NULL;
    s->size=size;
    return s;
}

//function to push an element onto the stack
void push(stack* s, int data){
    node* n=(node*)malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
    n->prev=NULL;
    if(s->top==NULL){
        s->top=n;
        s->bottom=n;
    }
    else{
        s->top->next=n;
        n->prev=s->top;
        s->top=n;
    }
    s->size++;
}

//function to pop an element from the stack
int pop(stack* s){
    if(s->top==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    node* n=s->top;
    int data=n->data;
    s->top=n->next;
    s->size--;
    free(n);
    return data;
}

//function to display the stack
void display(stack* s){
    printf("Stack elements: ");
    node* n=s->top;
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}

int main(){
    stack* s=create_stack(5);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    display(s);
    printf("Size of stack: %d\n",s->size);
    pop(s);
    pop(s);
    display(s);
    printf("Size of stack: %d\n",s->size);
    return 0;
}