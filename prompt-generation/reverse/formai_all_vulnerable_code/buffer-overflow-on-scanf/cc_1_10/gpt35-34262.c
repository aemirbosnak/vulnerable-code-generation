//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { //Define linked list node structure
    char* password;
    struct Node* next;
};

void addPassword(struct Node** head, char* password){ //Function to add password to a linked list
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->password = password;
    new_node->next = *head;
    *head = new_node;
}

void printPasswords(struct Node* head){ //Function to print all the passwords in the linked list
    struct Node* current = head;
    while(current != NULL){
        printf("%s\n", current->password);
        current = current->next;
    }
}

int main(){
    struct Node* head = NULL; //Initialize the linked list head to NULL
    
    printf("Welcome to your password manager!\n");
    int choice;
    char password[20];
    char confirm[20];
    
    while(1){ //Infinite loop to continue program execution until user chooses to exit
        printf("\nWhat would you like to do?\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("\nEnter new password: ");
                scanf("%s", password);
                printf("Confirm new password: ");
                scanf("%s", confirm);
                
                if(strcmp(password, confirm) == 0){ //Check if password and confirmation match
                    addPassword(&head, password); //Add password to linked list
                    printf("Password added successfully!\n");
                }else{
                    printf("Passwords do not match. Try again.\n");
                }
                
                break;
            case 2:
                if(head == NULL){ //Check if linked list is empty
                    printf("\nNo passwords saved yet.\n");
                }else{
                    printf("\nYour saved passwords:\n");
                    printPasswords(head); //Print all saved passwords
                }
                break;
            case 3:
                printf("\nThank you for using your password manager!\n");
                exit(0); //Exit program
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    
    return 0;
}