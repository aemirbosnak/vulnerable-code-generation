//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;

void addNode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}

void display(){
    node *ptr=head;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        printf("List contains:\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void search(int data){
    node *ptr=head;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        while(ptr!=NULL){
            if(ptr->data==data){
                printf("%d found in the list\n",data);
                return;
            }
            ptr=ptr->next;
        }
        printf("%d not found in the list\n",data);
    }
}

void delete(int data){
    node *ptr=head;
    node *prev=NULL;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        while(ptr!=NULL){
            if(ptr->data==data){
                if(prev==NULL){
                    head=head->next;
                }
                else{
                    prev->next=ptr->next;
                }
                free(ptr);
                printf("%d deleted from the list\n",data);
                return;
            }
            prev=ptr;
            ptr=ptr->next;
        }
        printf("%d not found in the list\n",data);
    }
}

int main(){
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    display();
    search(3);
    delete(2);
    display();
    return 0;
}