//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[20];
    int id;
    int size;
}block;

int top = -1;

void push(block* stack, int size){
    top++;
    stack[top].id = top;
    stack[top].size = size;
    printf("\nBlock of size %d created at %d", size, top);
}

void pop(block* stack){
    top--;
    printf("\nBlock of size %d removed from %d", stack[top].size, top);
}

void display(block* stack){
    int i;
    for(i=0; i<=top; i++){
        printf("\nBlock %d of size %d at %d", stack[i].id, stack[i].size, i);
    }
}

int main(){
    int choice, size;
    block stack[10];

    while(1){
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("\nEnter the size of block: ");
                scanf("%d", &size);
                push(stack, size);
                break;
            }
            case 2:{
                pop(stack);
                break;
            }
            case 3:{
                display(stack);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("\nInvalid choice");
            }
        }
    }

    return 0;
}