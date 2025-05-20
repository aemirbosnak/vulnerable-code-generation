//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct stack{
    int top;
    char data[MAX];
};

void push(struct stack* s,char value){
    if(s->top==MAX-1){
        printf("\nStack Overflow");
        exit(1);
    }
    else{
        s->data[++s->top]=value;
    }
}

char pop(struct stack* s){
    if(s->top==-1){
        printf("\nStack Underflow");
        exit(1);
    }
    else{
        return s->data[s->top--];
    }
}

int is_empty(struct stack* s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct stack* s){
    if(s->top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct stack s;
    s.top=-1;
    int choice,value;
    while(1){
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the value to be pushed:");
                scanf("%d",&value);
                push(&s,value);
                break;
            case 2:
                value=pop(&s);
                printf("\nThe popped value is: %d",value);
                break;
            case 3:
                if(is_empty(&s)){
                    printf("\nStack is empty");
                }
                else{
                    printf("\nThe elements in the stack are:");
                    while(!is_empty(&s)){
                        value=pop(&s);
                        printf("\n%d",value);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}