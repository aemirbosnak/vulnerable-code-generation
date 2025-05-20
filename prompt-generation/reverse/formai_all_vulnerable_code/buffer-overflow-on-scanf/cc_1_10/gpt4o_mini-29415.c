//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: dynamic
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
    printf("Contact added: %s - %s\n", name, phone);
}

void displayContacts() {
    if (head == NULL) {
        printf("No contacts available.\n");
        return;
    }
    printf("Phone Book Contacts:\n");
    Contact* current = head;
    while (current != NULL) {
        printf("Name: %s, Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

void searchContact(const char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found Contact: %s - %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(const char* name) {
    Contact* current = head;
    Contact* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found: %s\n", name);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Contact deleted: %s\n", name);
}

void freeContacts() {
    Contact* current = head;
    Contact* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    char name[50];
    char phone[15];
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                addContact(name, phone);
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                printf("Enter Name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;

            case 4:
                printf("Enter Name to delete: ");
                scanf("%s", name);
                deleteContact(name);
                break;

            case 5:
                freeContacts();
                printf("Exiting the phone book.\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}