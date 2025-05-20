//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
//This C program is an example of Linked List operations using C programming
#include<stdio.h>
#include<stdlib.h>

//Defining a node for the linked list
struct node{
    int data;
    struct node* next;
};

//Function to insert a node at the beginning of the linked list
struct node* insert_at_beginning(struct node* head, int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    return head;
}

//Function to insert a node at the end of the linked list
struct node* insert_at_end(struct node* head, int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
        return head;
    }
    struct node* current_node = head;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

//Function to delete a node from the linked list
struct node* delete_node(struct node* head, int value){
    if(head == NULL){
        printf("Linked List is Empty");
        return head;
    }
    if(head->data == value){
        struct node* current_node = head;
        head = head->next;
        free(current_node);
        return head;
    }
    struct node* current_node = head;
    struct node* previous_node = NULL;
    while(current_node != NULL && current_node->data != value){
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(current_node == NULL){
        printf("Element not found in Linked List");
        return head;
    }
    previous_node->next = current_node->next;
    free(current_node);
    return head;
}

//Function to display all the nodes of the linked list
void display(struct node* head){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    struct node* current_node = head;
    printf("Linked List: ");
    while(current_node != NULL){
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

//Main function
int main(){
    struct node* head = NULL;
    int choice = 0, value = 0, position = 0;
    do{
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete Node\n4. Display Linked List\n5. Exit\nEnter your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter the value: ");
                scanf("%d", &value);
                head = insert_at_beginning(head, value);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                head = insert_at_end(head, value);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = delete_node(head, value);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid Choice\n");
        }
    }while(choice != 5);
    return 0;
}