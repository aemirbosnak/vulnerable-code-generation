//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: detailed
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

void addContact(Contact contacts[], int *count);
void displayContacts(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
void updateContact(Contact contacts[], int count);
void deleteContact(Contact contacts[], int *count);
void displayMenu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while(1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch(choice) {
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
                updateContact(contacts, count);
                break;
            case 5:
                deleteContact(contacts, &count);
                break;
            case 6:
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts in phone book.\n");
        return;
    }

    printf("\n--- Contacts ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int count) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; 

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void updateContact(Contact contacts[], int count) {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the contact to update: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; 

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Current contact info: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            printf("Enter new name (press Enter to keep current): ");
            char newName[NAME_LENGTH];
            fgets(newName, NAME_LENGTH, stdin);
            newName[strcspn(newName, "\n")] = 0; 

            if (strlen(newName) > 0) {
                strcpy(contacts[i].name, newName);
            }

            printf("Enter new phone number (press Enter to keep current): ");
            char newPhone[PHONE_LENGTH];
            fgets(newPhone, PHONE_LENGTH, stdin);
            newPhone[strcspn(newPhone, "\n")] = 0; 

            if (strlen(newPhone) > 0) {
                strcpy(contacts[i].phone, newPhone);
            }

            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(Contact contacts[], int *count) {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; 

    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1]; // Shift contacts left
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}