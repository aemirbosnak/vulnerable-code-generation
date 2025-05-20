//FormAI DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// defining the linked list structure
struct node {
    int data;
    struct node* next;
}; 

// function to create new nodes for the linked list
struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// function to add a new node to the end of the linked list
void append(struct node** head_ref, int data){
    struct node* new_node = create_node(data);
    struct node* temp = *head_ref;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

// function to insert a new node at a given position in the linked list
void insert_at_pos(struct node** head_ref, int data, int pos){
    struct node* new_node = create_node(data);
    struct node* temp = *head_ref;
    int count = 1;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    if(pos == 1){
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    while(count != pos-1 && temp->next != NULL){
        count++;
        temp = temp->next;
    }
    if(count != pos-1){
        printf("\nPosition out of range. Node not inserted!\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

// function to delete a node with a given key from the linked list
void delete_node(struct node** head_ref, int key){
    struct node* temp = *head_ref;
    struct node* prev;
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key ){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("\nNode not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

// function to print the linked list data
void display(struct node* head){
    if(head == NULL){
        printf("\nThe list is empty!\n");
        return;
    }
    struct node* temp = head;
    printf("\nThe linked list is: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// driver function
int main(){
    struct node* head = NULL;
    int i;
    printf("-----Welcome to the dynamic linked list-----\n");
    printf("-----Following are the available operations-----\n");
    while(1){
        printf("\n");
        printf("1. Append a new node to the end of the linked list\n");
        printf("2. Insert a new node at a given position\n");
        printf("3. Delete a node with a given key from the linked list\n");
        printf("4. Display the linked list\n");
        printf("5. Exit\n");
        printf("\nEnter an operation number: ");
        scanf("%d", &i);
        switch(i){
            case 1: {
                int data;
                printf("\nEnter the data value to be added: ");
                scanf("%d", &data);
                append(&head, data);
                printf("\nNode added successfully!\n");
                break;
            }
            case 2: {
                int data, pos;
                printf("\nEnter the data value to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_at_pos(&head, data, pos);
                break;
            }
            case 3: {
                int key;
                printf("\nEnter the key value to be deleted: ");
                scanf("%d", &key);
                delete_node(&head, key);
                break;
            }
            case 4: {
                display(head);
                break;
            }
            case 5: {
                printf("\nExiting Program...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid operation number. Please enter a valid number!\n");
                break;
            }
        }
    }
    return 0;
}