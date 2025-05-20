//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push(node** head_ref, int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("Data %d is pushed to the stack\n", new_data);
}

void pop(node** head_ref){
    node* temp_node = (*head_ref);
    if(temp_node!= NULL){
        printf("The popped element is %d\n", temp_node->data);
        (*head_ref) = temp_node->next;
        free(temp_node);
    }
    else{
        printf("The stack is empty\n");
    }
}

void display(node* node){
    if(node!= NULL){
        printf("Data is %d\n", node->data);
        node = node->next;
    }
    else{
        printf("The stack is empty\n");
    }
}

int main(){
    node* head = NULL;
    int choice, data;
    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            }
            case 2:{
                pop(&head);
                break;
            }
            case 3:{
                display(head);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}