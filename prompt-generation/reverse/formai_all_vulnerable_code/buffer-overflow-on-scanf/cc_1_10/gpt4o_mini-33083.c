//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    getchar(); // To consume the newline character left by previous input
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0'; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0'; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void listContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }
    
    printf("\nContact List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to search.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    getchar(); // To consume the newline character left by previous input
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void deleteContact(Contact contacts[], int *count) {
    if (*count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    listContacts(contacts, *count);
    int index;
    printf("Enter the number of the contact to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid contact number.\n");
    } else {
        for (int i = index - 1; i < (*count) - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*count)--;
        printf("Contact deleted successfully!\n");
    }
}

void saveContacts(Contact contacts[], int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phone);
    }

    fclose(file);
    printf("Contacts saved successfully to contacts.txt\n");
}

void loadContacts(Contact contacts[], int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("No saved contacts found.\n");
        return;
    }

    while (fgets(contacts[*count].name, NAME_LENGTH, file) && 
           fgets(contacts[*count].phone, PHONE_LENGTH, file)) {
        contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0'; // Remove newline
        contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0'; // Remove newline
        (*count)++;
    }

    fclose(file);
    printf("Contacts loaded successfully. Total contacts: %d\n", *count);
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    loadContacts(contacts, &count); 

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                listContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                saveContacts(contacts, count);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}