//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: decentralized
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

// Function prototypes
void addContact();
void searchContact();
void deleteContact();
void displayContacts();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void clearBuffer() {
    while (getchar() != '\n');
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter Name: ");
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    strtok(phoneBook[contactCount].name, "\n"); // Remove newline

    printf("Enter Phone Number: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    strtok(phoneBook[contactCount].phone, "\n"); // Remove newline

    contactCount++;
    printf("Contact added successfully!\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter the name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter the name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1]; // Shift contacts left
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts() {
    if (contactCount == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\n--- Contacts ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}