//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CONTACTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
} Contact;

void printContacts(Contact *contacts, int count) {
    printf("\nContact List:\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Email: %s\n", contacts[i].email);
        printf("Phone: %s\n\n", contacts[i].phone);
    }
}

void addContact(Contact *contacts, int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full. Cannot add more contacts.\n");
        return;
    }

    printf("Adding new contact:\n");
    printf("Enter name: ");
    fgets(contacts[*count].name, MAX_NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline

    printf("Enter email: ");
    fgets(contacts[*count].email, MAX_NAME_LENGTH, stdin);
    contacts[*count].email[strcspn(contacts[*count].email, "\n")] = 0; // Remove newline

    printf("Enter phone: ");
    fgets(contacts[*count].phone, MAX_NAME_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void deleteContact(Contact *contacts, int *count) {
    if (*count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    printContacts(contacts, *count);
    int index;
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);
    getchar(); // Clear the newline character from the buffer

    if (index < 1 || index > *count) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    (*count)--;
    printf("Contact deleted successfully!\n");
}

void freeMemory(Contact *contacts) {
    free(contacts);
    printf("Memory freed successfully!\n");
}

int main() {
    Contact *contacts = (Contact *)malloc(MAX_CONTACTS * sizeof(Contact));
    if (contacts == NULL) {
        fprintf(stderr, "Failed to allocate memory for contacts.\n");
        return 1;
    }

    int count = 0;
    int choice;

    while (1) {
        printf("\n---- Contact Management System ----\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. View Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                deleteContact(contacts, &count);
                break;
            case 3:
                printContacts(contacts, count);
                break;
            case 4:
                freeMemory(contacts);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}