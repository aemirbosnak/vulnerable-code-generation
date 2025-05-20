//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define MAX_CONTACTS 100

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact* createContact(const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newContact->name, name, NAME_LENGTH);
    strncpy(newContact->phone, phone, PHONE_LENGTH);
    return newContact;
}

void deleteContact(Contact* contact) {
    if (contact != NULL) {
        free(contact);
        contact = NULL; // Avoid dangling pointer
    }
}

void printContact(const Contact* contact) {
    if (contact != NULL) {
        printf("Name: %s, Phone: %s\n", contact->name, contact->phone);
    }
}

void displayContacts(Contact** contacts, int count) {
    printf("Contacts List:\n");
    if (count == 0) {
        printf("No contacts found.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printContact(contacts[i]);
        }
    }
}

int main() {
    Contact* contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;
    
    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                if (contactCount >= MAX_CONTACTS) {
                    printf("Contact list is full. Cannot add more contacts.\n");
                    break;
                }
                {
                    char name[NAME_LENGTH];
                    char phone[PHONE_LENGTH];
                    
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter phone: ");
                    scanf("%s", phone);
                    
                    contacts[contactCount++] = createContact(name, phone);
                }
                break;
                
            case 2:
                displayContacts(contacts, contactCount);
                break;

            case 3:
                for (int i = 0; i < contactCount; i++) {
                    deleteContact(contacts[i]);
                }
                printf("Exiting... All contacts deleted.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}