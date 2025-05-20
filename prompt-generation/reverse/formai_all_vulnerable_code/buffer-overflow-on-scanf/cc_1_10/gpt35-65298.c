//FormAI DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{  // create a node structure
    struct node *next;
    char *password_name;
    char *password_key;
}; 

struct node *head = NULL; // initialize head node

void add_password(char *name, char *key){  // function to add password
    struct node *new_node = (struct node*)malloc(sizeof(struct node));  // create new node
    new_node->password_name = (char*)malloc(strlen(name)+1);  // allocate memory for password name
    new_node->password_key = (char*)malloc(strlen(key)+1);    // allocate memory for password key
    
    strcpy(new_node->password_name, name);  // copy password name to node
    strcpy(new_node->password_key, key);    // copy password key to node
    new_node->next = head;  // set new node's next pointer to current head node
    head = new_node;        // set head node pointer to new node
    printf("Password added!\n");
}

void delete_password(char *name){  // function to delete password
    struct node *current_node = head;
    struct node *previous_node = NULL;
    
    while(current_node != NULL){  // traverse linked list to find password name to be deleted
        if(strcmp(current_node->password_name, name)==0){  // if password name matches
            if(previous_node == NULL){  
                head = current_node->next;  // if password name is found at first node
            }
            else{
                previous_node->next = current_node->next;  // if password name is found in middle of list
            }
            free(current_node->password_name);  // free memory for password name 
            free(current_node->password_key);   // free memory for password key
            free(current_node);                // free memory for node
            printf("Password deleted!\n");
            return;
        }
        previous_node = current_node;           // move previous node to current node
        current_node = current_node->next;      // move current node to next node
    }
    printf("Password not found!\n");   // password name not found in list
}

void display_passwords(){   // function to display all passwords
    struct node *current_node = head;
    printf("Passwords:");
    while(current_node != NULL){  // traverse linked list to display all passwords
        printf("\nName: %s \t Key: %s", current_node->password_name, current_node->password_key);
        current_node = current_node->next;
    }
    printf("\n");
}

int main(){   // main function
    char name[20], key[20];
    int choice;
    printf("Welcome to Password Manager!\n");
    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Display passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){   // menu
            case 1: 
                printf("\nEnter password name: ");
                scanf("%s", name);
                printf("Enter password key: ");
                scanf("%s", key);
                add_password(name, key);
                break;
            case 2:
                printf("\nEnter password name to delete: ");
                scanf("%s", name);
                delete_password(name);
                break;
            case 3:
                display_passwords();
                break;
            case 4:
                printf("\nThank you for using Password Manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice!=4);
    return 0;
}