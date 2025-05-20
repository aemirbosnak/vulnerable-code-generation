//FormAI DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
struct node {
    char *email;
    struct node *next;
};

// Define the head of the linked list as a global variable
struct node *head = NULL;

// Function to add a new email to the linked list
void addEmail(char *newEmail) {
    // Allocate memory for the new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    
    // Copy the email address to the new node
    newNode->email = (char*)malloc(strlen(newEmail)+1);
    strcpy(newNode->email, newEmail);
    
    // Make the new node the head of the linked list
    newNode->next = head;
    head = newNode;
}

// Function to print the contents of the linked list
void printList() {
    struct node *current = head;
    while(current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Function to remove an email from the linked list
void removeEmail(char *emailToRemove) {
    struct node *current = head;
    struct node *prev = NULL;
    while(current != NULL) {
        if(strcmp(current->email, emailToRemove) == 0) {
            if(prev == NULL) {
                // Removing the head of the linked list
                head = current->next;
            } else {
                // Removing a node in the middle or end of the list
                prev->next = current->next;
            }
            free(current->email);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    char email[50];
    int menuOption;
    
    do {
        printf("\n1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Print List\n");
        printf("4. Quit\n");
        printf("Enter menu option: ");
        scanf("%d", &menuOption);
        
        switch(menuOption) {
            case 1:
                printf("Enter email address to add: ");
                scanf("%s", email);
                addEmail(email);
                break;
            case 2:
                printf("Enter email address to remove: ");
                scanf("%s", email);
                removeEmail(email);
                break;
            case 3:
                printf("Email List:\n");
                printList();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu option. Please try again.\n");
        }
    } while(menuOption != 4);
    
    // Free all memory used by the linked list
    struct node *current = head;
    struct node *temp = NULL;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp->email);
        free(temp);
    }
    
    return 0;
}