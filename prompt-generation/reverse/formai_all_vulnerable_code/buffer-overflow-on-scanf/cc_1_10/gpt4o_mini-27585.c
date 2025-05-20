//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact();
void displayContacts();
void searchContact();
void loadContacts(Contact contacts[], int *count);
void saveContacts(Contact contacts[], int count);

int main() {
    int choice;

    do {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search for a Contact\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void addContact() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "a");

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter Name: ");
    fgets(contact.name, NAME_LENGTH, stdin);
    strtok(contact.name, "\n"); // remove newline character

    printf("Enter Phone: ");
    fgets(contact.phone, PHONE_LENGTH, stdin);
    strtok(contact.phone, "\n"); // remove newline character

    fwrite(&contact, sizeof(Contact), 1, file);
    fclose(file);

    printf("Contact added successfully!\n");
}

void displayContacts() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\n=== Contacts List ===\n");
    while (fread(&contacts[count], sizeof(Contact), 1, file)) {
        printf("Name: %s, Phone: %s\n", contacts[count].name, contacts[count].phone);
        count++;
    }
    fclose(file);
    
    if (count == 0) {
        printf("No contacts found.\n");
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    Contact contact;
    int found = 0;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter the name of the contact to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    strtok(searchName, "\n"); // remove newline character

    while (fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, searchName) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", contact.name, contact.phone);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Contact not found.\n");
    }
}