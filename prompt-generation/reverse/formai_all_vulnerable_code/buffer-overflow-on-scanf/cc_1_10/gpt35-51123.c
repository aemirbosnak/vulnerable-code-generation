//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold contact information
struct Contact {
    char name[50];
    char email[50];
    struct Contact *next;
};

// Global variable to track the head of the linked list
struct Contact *head = NULL;

// Function to add a new contact to the end of the linked list
void addContact(char name[], char email[]) {
    // Allocate memory for new contact
    struct Contact *newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    newContact->next = NULL;

    // If list is empty, add new contact as head
    if (head == NULL) {
        head = newContact;
        return;
    }

    // Traverse list to find the end
    struct Contact *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Add new contact to the end
    current->next = newContact;
}

// Function to print all contacts in the linked list
void viewContacts() {
    // If list is empty, print message and return
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }

    // Print heading
    printf("Name                      Email\n");
    printf("---------------------------------------\n");

    // Traverse list and print each contact
    struct Contact *current = head;
    while (current != NULL) {
        printf("%-25s %-25s\n", current->name, current->email);
        current = current->next;
    }
}

// Function to delete a contact from the linked list
void deleteContact(char name[]) {
    // If list is empty, print message and return
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }

    // If head is the contact to be deleted, update head
    if (strcmp(head->name, name) == 0) {
        struct Contact *next = head->next;
        free(head);
        head = next;
        printf("%s deleted.\n", name);
        return;
    }

    // Traverse list to find contact
    struct Contact *current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }

    // If contact not found, print message and return
    if (current->next == NULL) {
        printf("%s not found.\n", name);
        return;
    }

    // Delete contact and update pointers
    struct Contact *next = current->next->next;
    free(current->next);
    current->next = next;
    printf("%s deleted.\n", name);
}

int main() {
    char name[50], email[50], choice;
    do {
        printf("\nMAIN MENU\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Delete contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nEnter name: ");
                scanf(" %[^\n]s", name);
                printf("Enter email: ");
                scanf(" %s", email);
                addContact(name, email);
                printf("%s added.\n", name);
                break;
            case '2':
                printf("\nCONTACT LIST\n");
                viewContacts();
                break;
            case '3':
                printf("\nEnter name: ");
                scanf(" %[^\n]s", name);
                deleteContact(name);
                break;
            case '4':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}