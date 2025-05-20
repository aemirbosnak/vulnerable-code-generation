//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;

NODE *create_node(int data){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    if(!new_node){
        printf("Memory Error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int is_empty(NODE *head){
    if(head == NULL){
        return 1;
    }
    return 0;
}

void insert_node(NODE **head, int data){
    NODE *new_node = create_node(data);
    NODE *temp = *head;
    if(is_empty(*head)){
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void delete_node(NODE **head, int data){
    NODE *temp = *head;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    NODE *prev = NULL;
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

void traverse_list(NODE *head){
    NODE *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    NODE *head = NULL;
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);
    traverse_list(head);
    delete_node(&head, 20);
    traverse_list(head);
    return 0;
}