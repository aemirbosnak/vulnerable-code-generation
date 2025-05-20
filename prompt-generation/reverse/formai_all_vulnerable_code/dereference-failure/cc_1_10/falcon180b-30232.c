//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Memory error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(node** head_ref, int data){
    node* new_node = create_node(data);
    node* temp = *head_ref;
    if(*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void delete_node(node** head_ref, int key){
    node* temp = *head_ref;
    node* prev = NULL;
    if(temp!= NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= key){
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

void search_node(node* head, int key){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == key){
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
    return;
}

void print_list(node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return;
}

int main(){
    node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);
    print_list(head);
    search_node(head, 4);
    delete_node(&head, 3);
    print_list(head);
    return 0;
}