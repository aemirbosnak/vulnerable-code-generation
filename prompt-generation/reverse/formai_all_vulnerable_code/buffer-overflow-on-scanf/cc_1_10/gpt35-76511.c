//FormAI DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 20
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_LIST_SIZE];
    int size;
} MailingList;

void displayMenu() {
    printf("\nWelcome to the Mailing List Manager!\n\n");
    printf("1. Add Contact\n");
    printf("2. Remove Contact\n");
    printf("3. View All Contacts\n");
    printf("4. Quit\n");
}

void addContact(MailingList* list) {
    Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter email: ");
    scanf("%s", newContact.email);
    
    if (list->size < MAX_LIST_SIZE) {
        list->contacts[list->size] = newContact;
        list->size++;
        printf("Contact added successfully.\n");
    } else {
        printf("Mailing list is full.\n");
    }
}

void removeContact(MailingList* list) {
    char email[MAX_EMAIL_LENGTH];
    printf("Enter email of contact to remove: ");
    scanf("%s", email);
    
    for (int i = 0; i < list->size; i++) {
        if (strcmp(email, list->contacts[i].email) == 0) {
            // shift all elements after the removed contact to fill the gap
            for (int j = i; j < list->size - 1; j++) {
                list->contacts[j] = list->contacts[j + 1];
            }
            list->size--;
            printf("Contact removed successfully.\n");
            return;
        }
    }
    
    printf("Contact not found in list.\n");
}

void viewAllContacts(MailingList* list) {
    if (list->size == 0) {
        printf("No contacts in list.\n");
        return;
    }
    
    printf("Name\t\tEmail\n");
    printf("----\t\t-----\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\t\t%s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    int choice;
    MailingList list = { .size = 0 };
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&list);
                break;
            case 2:
                removeContact(&list);
                break;
            case 3:
                viewAllContacts(&list);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    
    return 0;
}