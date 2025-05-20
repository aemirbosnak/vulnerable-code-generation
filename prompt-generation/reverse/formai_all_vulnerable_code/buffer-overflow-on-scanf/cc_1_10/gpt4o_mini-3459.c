//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: multivariable
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

void addContact(Contact contacts[], int *count);
void displayContacts(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
void deleteContact(Contact contacts[], int *count);
void editContact(Contact contacts[], int count);
void saveContacts(Contact contacts[], int count);
void loadContacts(Contact contacts[], int *count);

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    // Load existing contacts from file.
    loadContacts(contacts, &count);

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                editContact(contacts, count);
                break;
            case 5:
                deleteContact(contacts, &count);
                break;
            case 6:
                saveContacts(contacts, count);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    printf("Enter Name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter Phone: ");
    scanf("%s", contacts[*count].phone);
    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\nContacts List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int count) {
    char name[NAME_LEN];
    printf("Enter the name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(Contact contacts[], int *count) {
    char name[NAME_LEN];
    printf("Enter the name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1]; // Shift contacts
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void editContact(Contact contacts[], int count) {
    char name[NAME_LEN];
    printf("Enter the name to edit: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Editing contact %s - %s\n", contacts[i].name, contacts[i].phone);
            printf("Enter new name: ");
            scanf("%s", contacts[i].name);
            printf("Enter new phone: ");
            scanf("%s", contacts[i].phone);
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void saveContacts(Contact contacts[], int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void loadContacts(Contact contacts[], int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("No existing contacts to load.\n");
        return;
    }
    while (fscanf(file, "%s %s", contacts[*count].name, contacts[*count].phone) == 2) {
        (*count)++;
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}