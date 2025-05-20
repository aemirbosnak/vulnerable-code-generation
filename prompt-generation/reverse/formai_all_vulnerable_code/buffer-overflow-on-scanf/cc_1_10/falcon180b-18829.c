//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000000

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create_node(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Memory Error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node** top_ref, int new_data){
    Node* new_node = create_node(new_data);
    new_node->next = *top_ref;
    *top_ref = new_node;
}

int pop(Node** top_ref){
    Node* top_node = *top_ref;
    int popped_data = top_node->data;
    *top_ref = top_node->next;
    free(top_node);
    return popped_data;
}

int peek(Node* top_node){
    if(top_node == NULL){
        printf("Stack is Empty\n");
        exit(1);
    }
    return top_node->data;
}

int is_empty(Node* top_node){
    return top_node == NULL;
}

int main(){
    Node* stack = NULL;
    int choice, data;

    do{
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to be pushed:\n");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                printf("Popped value is %d\n", data);
                break;
            case 3:
                data = peek(stack);
                printf("Top value is %d\n", data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }while(1);

    return 0;
}