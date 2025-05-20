//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold contact information
struct Contact {
    char* name;
    char* email;
    struct Contact* next;
};

// Declare global variables to hold the head and tail of the linked list
struct Contact* head = NULL;
struct Contact* tail = NULL;

// Define function prototypes
void addContact(char* name, char* email);
void removeContact(char* email);
void printContacts();

int main() {
    int choice;
    char name[50];
    char email[50];

    // Display the menu and prompt the user for input
    while(1) {
        printf("\nWelcome to the Mailing List Manager!\n");
        printf("\nPlease choose an option:\n");
        printf("1. Add Contact\n2. Remove Contact\n3. View Contacts\n4. Exit\n");
        printf("Enter your choice (1-4): ");

        // Retrieve the user's choice
        scanf("%d", &choice);

        // Execute the appropriate function based on the user's choice
        switch(choice) {
            case 1:
                printf("\nEnter Contact Name: ");
                scanf("%s", name);
                printf("Enter Contact Email: ");
                scanf("%s", email);
                addContact(name, email);
                printf("\nContact added successfully!\n");
                break;
            case 2:
                printf("\nEnter Contact Email: ");
                scanf("%s", email);
                removeContact(email);
                break;
            case 3:
                printf("\nMailing List Contacts:\n");
                printContacts();
                break;
            case 4:
                printf("\nExiting Mailing List Manager. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }
}

void addContact(char* name, char* email) {
    // Create a new contact struct and allocate memory for its name and email fields
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    newContact->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    newContact->email = (char*)malloc(sizeof(char)*(strlen(email)+1));

    // Copy the name and email strings to the new contact struct
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    newContact->next = NULL;

    // Append the new contact struct to the end of the linked list
    if(head == NULL) {
        head = newContact;
        tail = newContact;
    } else {
        tail->next = newContact;
        tail = newContact;
    }
}

void removeContact(char* email) {
    // Traverse the linked list to find the contact with the email address provided
    struct Contact* currentNode = head;
    struct Contact* previousNode = NULL;
    while(currentNode != NULL) {
        // If the current node's email matches the provided email, remove it from the linked list
        if(strcmp(currentNode->email, email) == 0) {
            if(previousNode == NULL) {
                head = currentNode->next;
            } else {
                previousNode->next = currentNode->next;
            }
            free(currentNode->name);
            free(currentNode->email);
            free(currentNode);
            printf("\nContact removed successfully!\n");
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("\nContact not found.\n");
}

void printContacts() {
    // Traverse the linked list and print each contact's name and email
    struct Contact* currentNode = head;
    while(currentNode != NULL) {
        printf("%s - %s\n", currentNode->name, currentNode->email);
        currentNode = currentNode->next;
    }
}