//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node*create_node(int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void push(node**head,int data){
    node*newnode=create_node(data);
    newnode->next=*head;
    *head=newnode;
}

void pop(node**head){
    node*temp=*head;
    if(*head==NULL)
        return;
    *head=(*head)->next;
    free(temp);
}

void display(node*head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    int choice,data;
    node*head=NULL;
    do{
        printf("\nEnter 1 to push an element\n");
        printf("Enter 2 to pop an element\n");
        printf("Enter 3 to display the stack\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the element to be pushed\n");
                scanf("%d",&data);
                push(&head,data);
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
    }while(1);
    return 0;
}