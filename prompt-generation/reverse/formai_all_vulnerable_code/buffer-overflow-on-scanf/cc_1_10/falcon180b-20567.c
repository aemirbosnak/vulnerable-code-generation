//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX_SIZE 100000
typedef struct node{
    char data[MAX_SIZE];
    struct node*next;
}node;
node*head=NULL;
void push(char*str){
    node*newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->data,str);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void pop(){
    if(head==NULL){
        printf("Stack is empty\n");
        return;
    }
    node*temp=head;
    head=head->next;
    free(temp);
}
void print(){
    node*temp=head;
    while(temp!=NULL){
        printf("%s\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    char str[MAX_SIZE];
    printf("Enter string: ");
    scanf("%s",str);
    push(str);
    push("Hello");
    push("World");
    print();
    pop();
    print();
    pop();
    print();
    return 0;
}