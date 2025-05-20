//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
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

void addContact();
void listContacts();
void findContact();
void deleteContact();
void printMenu();
void clearInputBuffer();

int main() {
    int choice;
    while (1) {
        printMenu();
        printf("Choose an option (1-%d): ", 5);
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                findContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    strtok(phoneBook[contactCount].name, "\n"); // Remove newline

    printf("Enter phone: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    strtok(phoneBook[contactCount].phone, "\n"); // Remove newline

    contactCount++;
    printf("Contact added successfully!\n");
}

void listContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\nContact List:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void findContact() {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    int index;
    printf("Enter the index of the contact to delete (1-%d): ", contactCount);
    scanf("%d", &index);
    clearInputBuffer();

    if (index < 1 || index > contactCount) {
        printf("Invalid index. No contact deleted.\n");
        return;
    }

    for (int i = index - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;
    printf("Contact deleted successfully!\n");
}

void printMenu() {
    printf("\n==== Phone Book Menu ====\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Find Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}