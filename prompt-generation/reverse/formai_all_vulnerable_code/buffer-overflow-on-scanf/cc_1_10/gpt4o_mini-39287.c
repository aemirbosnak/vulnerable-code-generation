//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
} Contact;

Contact *contacts = NULL;
int contactCount = 0;

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void initialize_contacts() {
    contacts = malloc(MAX_CONTACTS * sizeof(Contact));
    if (contacts == NULL) {
        handle_error("Failed to allocate memory for contacts.");
    }
}

void add_contact(const char *name, const char *phone) {
    if (contactCount >= MAX_CONTACTS) {
        handle_error("Contact list is full. Cannot add more contacts.");
    }
    
    strncpy(contacts[contactCount].name, name, MAX_NAME_LENGTH - 1);
    contacts[contactCount].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination

    strncpy(contacts[contactCount].phone, phone, MAX_NAME_LENGTH - 1);
    contacts[contactCount].phone[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination

    contactCount++;
}

void display_contacts() {
    if (contactCount == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("Contacts List:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void cleanup() {
    free(contacts);
    contacts = NULL;
}

int main(int argc, char *argv[]) {
    initialize_contacts();

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        
        int option;
        if (scanf("%d", &option) != 1) {
            handle_error("Invalid input. Please enter a number corresponding to the options.");
        }
        
        switch (option) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                char phone[MAX_NAME_LENGTH];
                
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name); // Read string with spaces
                
                printf("Enter phone: ");
                scanf(" %[^\n]%*c", phone); // Read string with spaces
                
                add_contact(name, phone);
                printf("Contact added successfully.\n");
                break;
            }
            case 2:
                display_contacts();
                break;
            case 3:
                printf("Exiting the program.\n");
                cleanup();
                return 0;
            default:
                handle_error("Invalid option. Please select a valid one.");
        }
    }
    
    cleanup();
    
    return 0;
}