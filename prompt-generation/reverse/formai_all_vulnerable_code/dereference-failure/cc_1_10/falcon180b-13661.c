//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

//node structure
struct node{
    int data;
    struct node* next;
};

void add_node(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }else{
        struct node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;

    //add nodes
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    add_node(&head, 40);
    add_node(&head, 50);

    //print list
    printf("Original list: ");
    print_list(head);

    //delete node
    struct node* prev_node = head;
    struct node* curr_node = head->next;
    while(curr_node!= NULL){
        if(curr_node->data == 30){
            prev_node->next = curr_node->next;
            free(curr_node);
            break;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    //print list after deletion
    printf("List after deleting node with data 30: ");
    print_list(head);

    return 0;
}