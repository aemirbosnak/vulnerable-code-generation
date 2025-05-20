//FormAI DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definition of a contact structure
struct contact {
    char name[50];
    char phone_number[15];
    struct contact *next;
};

// Function to add a new contact to the phone book
void add_contact(struct contact **head_ref, char *name, char *phone_number) {
    // Allocate memory for the new contact
    struct contact *new_contact = (struct contact*) malloc(sizeof(struct contact));
    
    // Populate the contact structure with the provided information
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone_number, phone_number);
    new_contact->next = NULL;

    if (*head_ref == NULL) {
        // If the phone book is empty, new_contact becomes the head
        *head_ref = new_contact;
    } else {
        // Otherwise, we need to find the end of the phone book and append the new contact
        struct contact *current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_contact;
    }
    printf("Contact added successfully!\n");
}

// Function to search for a contact by name and print their phone number
void search_contact(struct contact *head, char *name) {
    struct contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->phone_number);
            return;
        }
        current = current->next;
    }
    printf("Contact not found!\n");
}

// Function to delete a contact by name
void delete_contact(struct contact **head_ref, char *name) {
    struct contact *current = *head_ref;
    struct contact *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                // If the contact to delete is the head, we need to update the head pointer
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            // Free the memory allocated for the contact
            free(current);
            printf("Contact deleted successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found!\n");
}

int main() {
    // Initialize the phone book as an empty linked list
    struct contact *phone_book = NULL;

    printf("Welcome to the Decentralized Phone Book!\n");

    // Main loop of the program
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the name of the contact: ");
            char name[50];
            scanf("%s", name);
            printf("Enter the phone number of %s: ", name);
            char phone_number[15];
            scanf("%s", phone_number);
            add_contact(&phone_book, name, phone_number);
        } else if (choice == 2) {
            printf("Enter the name of the contact to search for: ");
            char name[50];
            scanf("%s", name);
            search_contact(phone_book, name);
        } else if (choice == 3) {
            printf("Enter the name of the contact to delete: ");
            char name[50];
            scanf("%s", name);
            delete_contact(&phone_book, name);
        } else if (choice == 4) {
            // Exit the program
            printf("Thank you for using the Decentralized Phone Book!\n");
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}