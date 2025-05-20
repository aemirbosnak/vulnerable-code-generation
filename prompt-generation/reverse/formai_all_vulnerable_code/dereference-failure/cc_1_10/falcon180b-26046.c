//Falcon-180B DATASET v1.0 Category: Memory management ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 5

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;

void push(int data){
    node* new_node=(node*)malloc(sizeof(node));
    if(new_node==NULL){
        printf("Memory Error\n");
        exit(0);
    }
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

int pop(){
    if(head==NULL){
        printf("Stack Underflow\n");
        exit(0);
    }
    int data=head->data;
    node* temp=head;
    head=head->next;
    free(temp);
    return data;
}

void display(){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    printf("Popped element is %d\n",pop());
    display();
    return 0;
}