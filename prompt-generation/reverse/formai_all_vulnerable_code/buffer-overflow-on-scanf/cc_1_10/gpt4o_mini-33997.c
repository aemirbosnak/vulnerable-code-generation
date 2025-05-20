//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: optimized
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
void viewContacts(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
void deleteContact(Contact contacts[], int *count);
void saveToFile(Contact contacts[], int count);
void loadFromFile(Contact contacts[], int *count);
void displayMenu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    loadFromFile(contacts, &count);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                viewContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                saveToFile(contacts, count);
                printf("Contacts saved successfully!\n");
                break;
            case 6:
                printf("Exiting the phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts\n");
    printf("6. Exit\n");
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full, cannot add more contacts!\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0'; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0'; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void viewContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display!\n");
        return;
    }

    printf("\n=== Contacts ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int count) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact(Contact contacts[], int *count) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void saveToFile(Contact contacts[], int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error saving contacts!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
}

void loadFromFile(Contact contacts[], int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        return; // No file exists, start with no contacts
    }

    while (fgets(contacts[*count].name, NAME_LENGTH, file) && 
           fgets(contacts[*count].phone, PHONE_LENGTH, file)) {
        contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0'; // Remove newline
        contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0'; // Remove newline
        (*count)++;
    }
    fclose(file);
}