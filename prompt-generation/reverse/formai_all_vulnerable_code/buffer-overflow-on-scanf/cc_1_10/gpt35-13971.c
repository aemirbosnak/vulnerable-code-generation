//FormAI DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[30];
    char number[15];
};

void add_contact(struct contact **contacts, int *size) {
    // Maximum number of contacts is 10
    if (*size >= 10) {
        printf("The phone book is full.\n");
        return;
    }
    // Create a new contact
    struct contact *new_contact = malloc(sizeof(struct contact));
    printf("Enter the name of the contact: ");
    scanf(" %[^\n]", new_contact->name);
    printf("Enter the number of the contact: ");
    scanf(" %s", new_contact->number);
    // Add the new contact to the phone book
    contacts[*size] = new_contact;
    (*size)++;
    printf("Contact added successfully.\n");
}

void search_contact(struct contact **contacts, int size, char *name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i]->name, contacts[i]->number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void list_contacts(struct contact **contacts, int size) {
    if (size == 0) {
        printf("The phone book is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d. %s (%s)\n", i + 1, contacts[i]->name, contacts[i]->number);
    }
}

void delete_contact(struct contact **contacts, int *size, char *name) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            // Free the memory allocated for the contact
            free(contacts[i]);
            // Shift the remaining contacts to fill the gap
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            found = 1;
            printf("Contact deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    struct contact *contacts[10];
    int size = 0;
    char choice;
    char name[30];
    printf("Welcome to the Post-Apocalyptic Phone Book!\n");
    do {
        printf("\n");
        printf("Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. List Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                add_contact(contacts, &size);
                break;
            case '2':
                printf("Enter the name of the contact: ");
                scanf(" %[^\n]", name);
                search_contact(contacts, size, name);
                break;
            case '3':
                list_contacts(contacts, size);
                break;
            case '4':
                printf("Enter the name of the contact to be deleted: ");
                scanf(" %[^\n]", name);
                delete_contact(contacts, &size, name);
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '5');
    return 0;
}