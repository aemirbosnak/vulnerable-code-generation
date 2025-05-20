//FormAI DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[50];
    char email[50];
    struct node* next;
};

typedef struct node node;

int add_node(node** head, char* name, char* email){
    //First create a new node
    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node){
        return -1; //Memory allocation failed
    }
    //Populate node with data
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    //If list is empty
    if(*head == NULL){
        *head = new_node;
        return 0;
    }
    //If list is non-empty, append new node to the end of the list
    node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    return 0;
}

int delete_node(node** head, char* email){
    //If list is empty
    if(*head == NULL){
        return -1; //Empty list
    }
    //If first node matches email
    if(strcmp((*head)->email, email) == 0){
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return 0;
    }
    //If not the first node, search through the list
    node* current = *head;
    node* prev = NULL;
    while(current != NULL){
        if(strcmp(current->email, email) == 0){
            prev->next = current->next;
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    //If email not found in the list
    return -1;
}

int print_list(node* head){
    //If list is empty
    if(head == NULL){
        return -1; //Empty list
    }
    //If list is non-empty
    node* current = head;
    while(current != NULL){
        printf("%s,%s\n", current->name, current->email);
        current = current->next;
    }
    return 0;
}

int main(){
    node* head = NULL; //Initialize an empty list
    int choice;
    char name[50], email[50];
    while(1){
        printf("1. Add contact\n2. Delete contact\n3. Print contacts\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: //Add contact
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                if(add_node(&head, name, email) == -1){
                    printf("Error: Memory allocation failed!\n");
                }
                break;
            case 2: //Delete contact
                printf("Enter email: ");
                scanf("%s", email);
                if(delete_node(&head, email) == -1){
                    printf("Error: Email not found in the list!\n");
                }
                break;
            case 3: //Print contacts
                if(print_list(head) == -1){
                    printf("Error: List is empty!\n");
                }
                break;
            case 4: //Exit
                exit(0);
            default: //Invalid choice
                printf("Error: Invalid choice!\n");
                break;
        }
    }
    return 0;
}