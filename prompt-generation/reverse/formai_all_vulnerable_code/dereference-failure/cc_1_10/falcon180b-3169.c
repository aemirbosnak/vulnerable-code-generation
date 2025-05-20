//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct node{
    int data;
    struct node* link;
};

struct node* head = NULL;

void insert(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        struct node* temp = head;
        while(temp->link!= NULL){
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void delete(int data){
    struct node* temp = head;
    struct node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        head = temp->link;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->link;
    }
    if(temp == NULL){
        return;
    }
    prev->link = temp->link;
    free(temp);
}

void search(int data){
    struct node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("%d found\n", data);
            return;
        }
        temp = temp->link;
    }
    printf("%d not found\n", data);
}

void display(){
    struct node* temp = head;
    if(temp == NULL){
        printf("Empty list\n");
        return;
    }
    printf("List: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    search(3);
    delete(3);
    display();
    return 0;
}