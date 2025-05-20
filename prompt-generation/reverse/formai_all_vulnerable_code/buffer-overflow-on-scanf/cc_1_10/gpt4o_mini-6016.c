//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: authentic
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

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", phoneBook[contactCount].name);
        printf("Enter phone number: ");
        scanf("%s", phoneBook[contactCount].phone);
        contactCount++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone book is full!\n");
    }
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts available!\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            found = 1;
            printf("Deleting Contact: Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void saveContacts() {
    FILE *file = fopen("phonebook.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
    printf("Contacts saved to phonebook.txt\n");
}

void loadContacts() {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("Error opening file for reading, no saved contacts found!\n");
        return;
    }
    while (fscanf(file, "%s %s", phoneBook[contactCount].name, phoneBook[contactCount].phone) != EOF && contactCount < MAX_CONTACTS) {
        contactCount++;
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

void displayMenu() {
    printf("\n--- Phone Book ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts\n");
    printf("6. Load Contacts\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    loadContacts();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: saveContacts(); break;
            case 6: loadContacts(); break;
            case 7: printf("Exiting the program...\n"); exit(0);
            default: printf("Invalid option! Please try again.\n"); break;
        }
    }
    return 0;
}