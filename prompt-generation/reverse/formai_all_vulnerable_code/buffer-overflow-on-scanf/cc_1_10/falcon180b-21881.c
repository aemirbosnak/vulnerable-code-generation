//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node=(node*)malloc(sizeof(node));
    if(!new_node){
        printf("Memory Error!");
        exit(0);
    }
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void insert_node(node** head,int data){
    node* new_node=create_node(data);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

int search_node(node* head,int data){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==data){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void delete_node(node** head,int data){
    node* temp=*head;
    node* prev=NULL;
    if(temp!=NULL && temp->data==data){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=data){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void display_list(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    node* head=NULL;
    int choice,data;
    while(1){
        printf("Enter your choice:\n");
        printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted:");
                scanf("%d",&data);
                insert_node(&head,data);
                break;
            case 2:
                printf("Enter the data to be deleted:");
                scanf("%d",&data);
                delete_node(&head,data);
                break;
            case 3:
                printf("Enter the data to be searched:");
                scanf("%d",&data);
                if(search_node(head,data)){
                    printf("%d found in the list",data);
                }
                else{
                    printf("%d not found in the list",data);
                }
                break;
            case 4:
                display_list(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}