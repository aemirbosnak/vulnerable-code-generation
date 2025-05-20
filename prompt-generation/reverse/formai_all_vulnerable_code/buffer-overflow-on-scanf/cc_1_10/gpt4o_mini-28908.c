//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define FILE_NAME "phonebook.txt"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void loadContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fscanf(file, "%49s %14s\n", phoneBook[contactCount].name, phoneBook[contactCount].phone) != EOF) {
            contactCount++;
        }
        fclose(file);
    }
}

void saveContacts() {
    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%49s", phoneBook[contactCount].name);
    printf("Enter phone: ");
    scanf("%14s", phoneBook[contactCount].phone);
    contactCount++;
    saveContacts();
    printf("Contact added successfully!\n");
}

void searchContact() {
    char name[NAME_LEN];
    printf("Enter name to search: ");
    scanf("%49s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void updateContact() {
    char name[NAME_LEN];
    printf("Enter name to update: ");
    scanf("%49s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Enter new phone number: ");
            scanf("%14s", phoneBook[i].phone);
            saveContacts();
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%49s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            saveContacts();
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void displayContacts() {
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    loadContacts();
    int choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                updateContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                displayContacts();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}