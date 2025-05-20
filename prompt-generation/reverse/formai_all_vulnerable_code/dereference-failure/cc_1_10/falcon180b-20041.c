//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure definition
struct node{
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct node** head_ref, int new_data){
    struct node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(struct node** head_ref, int new_data){
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;
    
    if(*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    
    while(last->next!= NULL){
        last = last->next;
    }
    
    last->next = new_node;
    return;
}

// Function to add a node at a specific position in the list
void insertNode(struct node** head_ref, int new_data, int pos){
    struct node* new_node = newNode(new_data);
    struct node* temp = *head_ref;
    int i;
    
    if(pos == 0){
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }
    
    for(i=0;i<pos-1 && temp!=NULL;i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("Position out of range\n");
        return;
    }
    
    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

// Function to delete a node with given data
void deleteNode(struct node** head_ref, int key){
    struct node* temp = *head_ref;
    struct node* prev;
    
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

// Function to display the list
void display(struct node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct node* head = NULL;
    
    // Adding nodes
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    append(&head, 40);
    insertNode(&head, 25, 2);
    
    // Displaying list
    printf("List after adding nodes:\n");
    display(head);
    
    // Deleting a node
    deleteNode(&head, 20);
    
    // Displaying list after deletion
    printf("\nList after deleting node with value 20:\n");
    display(head);
    
    return 0;
}