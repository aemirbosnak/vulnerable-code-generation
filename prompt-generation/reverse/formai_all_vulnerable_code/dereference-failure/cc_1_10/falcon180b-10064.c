//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    struct node *temp = head;

    while(temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

void delete(int data){
    struct node *temp = head;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->data == data){
        head = head->next;
        free(temp);
        return;
    }

    while(temp->next!= NULL && temp->next->data!= data){
        temp = temp->next;
    }

    if(temp->next == NULL){
        printf("Element not found\n");
        return;
    }

    struct node *newnode = temp->next;
    temp->next = temp->next->next;
    free(newnode);
}

void display(){
    struct node *temp = head;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    printf("List elements are: ");

    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    display();

    delete(2);

    display();

    delete(1);

    display();

    delete(4);

    display();

    return 0;
}