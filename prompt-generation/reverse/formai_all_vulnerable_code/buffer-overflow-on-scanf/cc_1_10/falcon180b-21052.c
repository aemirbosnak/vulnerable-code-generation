//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for a node in linked list
struct node{
    int data;
    struct node* next;
};

//Function to create a new node
struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//Function to add a node at the end of the linked list
void add_node(struct node** head, int data){
    struct node* new_node = create_node(data);
    struct node* temp = *head;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

//Function to delete a node from the linked list
void delete_node(struct node** head, int data){
    struct node* temp = *head;
    struct node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//Function to print the linked list
void print_list(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main function
int main(){
    struct node* head = NULL;
    int choice, data;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Add node\n2. Delete node\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be added:\n");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                printf("Enter the data to be deleted:\n");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}