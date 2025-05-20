//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[15];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} ContactList;

void initializeContactList(ContactList *list) {
    list->size = 0;
    list->capacity = 5;
    list->contacts = (Contact *)malloc(list->capacity * sizeof(Contact));
    if (list->contacts == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void freeContactList(ContactList *list) {
    free(list->contacts);
    list->contacts = NULL; // helps prevent dangling pointer
    list->size = 0;
    list->capacity = 0;
}

void addContact(ContactList *list, const char *name, const char *phone) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->contacts = (Contact *)realloc(list->contacts, list->capacity * sizeof(Contact));
        if (list->contacts == NULL) {
            fprintf(stderr, "Reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    strncpy(list->contacts[list->size].name, name, MAX_NAME_LEN);
    strncpy(list->contacts[list->size].phone, phone, 15);
    list->size++;
}

void displayContacts(const ContactList *list) {
    if (list->size == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s, Phone: %s\n", list->contacts[i].name, list->contacts[i].phone);
    }
}

void deleteContact(ContactList *list, const char *name) {
    int found = -1;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Contact not found!\n");
        return;
    }

    for (int i = found; i < list->size - 1; i++) {
        list->contacts[i] = list->contacts[i + 1]; // Shift left
    }
    list->size--;
}

int main() {
    ContactList myContacts;
    initializeContactList(&myContacts);

    int option;
    char name[MAX_NAME_LEN];
    char phone[15];
    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // consume newline

        switch (option) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter phone number: ");
                fgets(phone, 15, stdin);
                phone[strcspn(phone, "\n")] = 0; // remove newline
                addContact(&myContacts, name, phone);
                break;
            case 2:
                displayContacts(&myContacts);
                break;
            case 3:
                printf("Enter name of the contact to delete: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                deleteContact(&myContacts, name);
                break;
            case 4:
                freeContactList(&myContacts);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}