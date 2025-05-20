//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

void displayMenu() {
    printf("\n=====================\n");
    printf("   Retro Phone Book  \n");
    printf("=====================\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("=====================\n");
    printf("Enter your choice: ");
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_LEN, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // remove trailing newline

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_LEN, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // remove trailing newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(Contact contacts[], int count) {
    printf("\n=== Contacts List ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
    printf("=====================\n");
}

void searchContact(Contact contacts[], int count) {
    char name[NAME_LEN];
    printf("Enter name to search: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // remove trailing newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            printf("Found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(Contact contacts[], int *count) {
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // remove trailing newline

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume newline after scanf

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Exiting... Thank you for using the Retro Phone Book!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}