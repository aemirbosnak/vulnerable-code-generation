//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    scanf(" %[^\n]", contacts[*count].name); // Read string with spaces
    printf("Enter phone number: ");
    scanf(" %[^\n]", contacts[*count].phone); // Read string with spaces
    
    (*count)++;
    printf("Contact added successfully!\n");
}

void listContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    
    printf("\nAll Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
    printf("\n");
}

void deleteContact(Contact contacts[], int *count) {
    if (*count == 0) {
        printf("No contacts to delete!\n");
        return;
    }
    
    listContacts(contacts, *count);
    int index;
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid index! Please try again.\n");
        return;
    }
    
    for (int i = index - 1; i < *count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    
    (*count)--;
    printf("Contact deleted successfully!\n");
}

void searchContact(Contact contacts[], int count) {
    if (count == 0) {
        printf("The phone book is empty!\n");
        return;
    }
    
    char query[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", query);
    
    printf("Search Results:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, query) != NULL) {
            printf("%s: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No contacts found with the name '%s'.\n", query);
    }
}

int main() {
    Contact contacts[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Delete contact\n");
        printf("4. Search contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                listContacts(contacts, count);
                break;
            case 3:
                deleteContact(contacts, &count);
                break;
            case 4:
                searchContact(contacts, count);
                break;
            case 5:
                printf("Exiting the phone book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}