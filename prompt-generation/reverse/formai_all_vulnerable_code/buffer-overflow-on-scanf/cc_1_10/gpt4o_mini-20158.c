//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
} Contact;

Contact* head = NULL;

void addContact(const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = head;
    head = newContact;
    printf("Contact '%s' added successfully!\n", name);
}

void viewContacts() {
    Contact* current = head;
    if (current == NULL) {
        printf("Phone book is empty!\n");
        return;
    }
    printf("\nContacts:\n");
    while (current != NULL) {
        printf("Name: %s, Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

Contact* searchContact(const char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteContact(const char* name) {
    Contact* current = head;
    Contact* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact '%s' not found!\n", name);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the first contact
    } else {
        previous->next = current->next; // Bypass the deleted contact
    }

    free(current);
    printf("Contact '%s' deleted successfully!\n", name);
}

void freeContacts() {
    Contact* current = head;
    Contact* nextContact;

    while (current != NULL) {
        nextContact = current->next;
        free(current);
        current = nextContact;
    }
    head = NULL;
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char name[50], phone[15];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter contact phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline
                addContact(name, phone);
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                printf("Enter contact name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                Contact* found = searchContact(name);
                if (found) {
                    printf("Found Contact - Name: %s, Phone: %s\n", found->name, found->phone);
                } else {
                    printf("Contact '%s' not found!\n", name);
                }
                break;
            case 4:
                printf("Enter contact name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deleteContact(name);
                break;
            case 5:
                freeContacts();
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}