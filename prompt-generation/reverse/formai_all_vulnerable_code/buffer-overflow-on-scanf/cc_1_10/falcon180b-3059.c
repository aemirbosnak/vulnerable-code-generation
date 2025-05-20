//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//node structure
typedef struct node{
    int data;
    struct node* next;
}node;

//function prototypes
void create(node** head);
void insert(node** head, int data);
void delete(node** head, int data);
void display(node* head);

int main(){
    node* head = NULL;
    int choice, data;
    
    do{
        printf("\nLinked List Operations:\n");
        printf("1. Create List\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                create(&head);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 3:
                printf("Enter the element to be deleted: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 5);
    
    return 0;
}

//function to create an empty list with head as NULL
void create(node** head){
    *head = NULL;
}

//function to insert an element at the end of the list
void insert(node** head, int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

//function to delete an element from the list
void delete(node** head, int data){
    node* temp = *head;
    node* prev = NULL;

    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

//function to display the list
void display(node* head){
    if(head == NULL)
        printf("List is empty!\n");
    else{
        printf("List elements are:\n");
        while(head!= NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    }
}