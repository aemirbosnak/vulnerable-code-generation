//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void add_node(node** head,int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }
    else{
        node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_node(node** head,int data){
    node* temp = *head;
    if(temp->data == data){
        *head = temp->next;
        free(temp);
    }
    else{
        while(temp->next!= NULL && temp->next->data!= data){
            temp = temp->next;
        }
        if(temp->next!= NULL){
            node* next_node = temp->next->next;
            free(temp->next);
            temp->next = next_node;
        }
    }
}

void search_node(node* head,int data){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("%d found\n",data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n",data);
}

void display(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    node* head = NULL;
    add_node(&head,1);
    add_node(&head,2);
    add_node(&head,3);
    display(head);
    search_node(head,2);
    delete_node(&head,2);
    display(head);
    return 0;
}