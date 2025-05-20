//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 30
#define PHONE_SIZE 15
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

void addContact(Contact contacts[], int *count);
void displayContacts(Contact contacts[], int count);
int loadContacts(Contact contacts[], int *count);
int saveContacts(Contact contacts[], int count);
void menu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    if (loadContacts(contacts, &count) != 0) {
        printf("Failed to load contacts. Starting with an empty list.\n");
    }

    menu(contacts, &count);
    return 0;
}

void menu(Contact contacts[], int *count) {
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Save Contacts\n");
        printf("4. Load Contacts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                addContact(contacts, count);
                break;
            case 2:
                displayContacts(contacts, *count);
                break;
            case 3:
                if (saveContacts(contacts, *count) == 0) {
                    printf("Contacts saved successfully.\n");
                }
                break;
            case 4:
                if (loadContacts(contacts, count) == 0) {
                    printf("Contacts loaded successfully.\n");
                }
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_SIZE, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline character

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_SIZE, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline character

    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nContacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int loadContacts(Contact contacts[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        return -1; // Could not open the file
    }

    *count = 0;
    while (fscanf(file, "%[^\n]\n%[^\n]\n", contacts[*count].name, contacts[*count].phone) != EOF)
    {
        (*count)++;
    }

    fclose(file);
    return 0;
}

int saveContacts(Contact contacts[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return -1; // Error
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phone);
    }

    fclose(file);
    return 0;
}