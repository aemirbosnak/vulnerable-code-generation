//Falcon-180B DATASET v1.0 Category: Error handling ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void create(node** head_ref,int data){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    if(*head_ref==NULL){
        *head_ref=new_node;
    }
    else{
        node* last=*head_ref;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=new_node;
    }
}

void delete(node** head_ref,int key){
    node* temp=*head_ref;
    node* prev=NULL;
    if(temp!=NULL&&temp->data==key){
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nElement not found in the list");
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void search(node* head,int key){
    node* current=head;
    while(current!=NULL){
        if(current->data==key){
            printf("\nElement found");
            return;
        }
        current=current->next;
    }
    printf("\nElement not found in the list");
}

void display(node* head){
    node* current=head;
    while(current!=NULL){
        printf("\n%d",current->data);
        current=current->next;
    }
}

int main(){
    node* head=NULL;
    int choice,key;
    do{
        printf("\n1.Create");
        printf("\n2.Delete");
        printf("\n3.Search");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the element to be inserted:");
                scanf("%d",&key);
                create(&head,key);
                break;
            case 2:
                printf("\nEnter the element to be deleted:");
                scanf("%d",&key);
                delete(&head,key);
                break;
            case 3:
                printf("\nEnter the element to be searched:");
                scanf("%d",&key);
                search(head,key);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }while(choice!=5);
    return 0;
}