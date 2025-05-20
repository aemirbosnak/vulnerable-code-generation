//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact* phoneBook;
int contactCount = 0;

void initializePhoneBook() {
    phoneBook = (Contact*)malloc(MAX_CONTACTS * sizeof(Contact));
    if (phoneBook == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter contact name: ");
    getchar(); // consume the newline character
    fgets(phoneBook[contactCount].name, MAX_NAME_LENGTH, stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = '\0'; // remove newline

    printf("Enter contact phone number: ");
    fgets(phoneBook[contactCount].phone, MAX_PHONE_LENGTH, stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = '\0'; // remove newline

    contactCount++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void editContact() {
    int index;
    printf("Enter contact number to edit (1 to %d): ", contactCount);
    scanf("%d", &index);
    index--; // to match array index

    if (index < 0 || index >= contactCount) {
        printf("Invalid contact number.\n");
        return;
    }

    printf("Editing contact: %s, Phone: %s\n", phoneBook[index].name, phoneBook[index].phone);
    printf("Enter new name (or press enter to keep current): ");
    getchar(); // consume newline
    char buffer[MAX_NAME_LENGTH];
    fgets(buffer, MAX_NAME_LENGTH, stdin);
    if (strcmp(buffer, "\n") != 0) {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline
        strcpy(phoneBook[index].name, buffer);
    }

    printf("Enter new phone number (or press enter to keep current): ");
    fgets(buffer, MAX_PHONE_LENGTH, stdin);
    if (strcmp(buffer, "\n") != 0) {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline
        strcpy(phoneBook[index].phone, buffer);
    }

    printf("Contact updated successfully!\n");
}

void searchContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    getchar(); // consume newline
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // remove newline

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Found Contact - Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found with the name '%s'.\n", searchName);
    }
}

void deleteContact() {
    int index;
    printf("Enter contact number to delete (1 to %d): ", contactCount);
    scanf("%d", &index);
    index--; // to match array index

    if (index < 0 || index >= contactCount) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = index; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;
    printf("Contact deleted successfully!\n");
}

void freePhoneBook() {
    free(phoneBook);
}

int main() {
    int choice;

    initializePhoneBook();

    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Search Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    freePhoneBook(); // Release memory
    return 0;
}