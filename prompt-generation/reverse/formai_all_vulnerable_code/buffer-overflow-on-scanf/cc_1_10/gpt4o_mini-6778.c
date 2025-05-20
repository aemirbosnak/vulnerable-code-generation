//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    do {
        printf("\n---- Phone Book Menu ----\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the trailing newline

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
                deleteContact();
                break;
            case 5:
                printf("Exiting Phone Book.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter Name: ");
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = '\0';  // Remove newline

    printf("Enter Phone: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = '\0';  // Remove newline

    printf("Enter Email: ");
    fgets(phoneBook[contactCount].email, EMAIL_LENGTH, stdin);
    phoneBook[contactCount].email[strcspn(phoneBook[contactCount].email, "\n")] = '\0';  // Remove newline

    contactCount++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts available!\n");
        return;
    }

    printf("\n--- Contacts ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d:\n", i + 1);
        printf("  Name: %s\n", phoneBook[i].name);
        printf("  Phone: %s\n", phoneBook[i].phone);
        printf("  Email: %s\n\n", phoneBook[i].email);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) { // Case insensitive comparison
            found = 1;
            printf("Contact Found:\n");
            printf("  Name: %s\n", phoneBook[i].name);
            printf("  Phone: %s\n", phoneBook[i].phone);
            printf("  Email: %s\n", phoneBook[i].email);
            break;
        }
    }
    if (!found) {
        printf("Contact with name '%s' not found.\n", name);
    }
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1]; // Shift contacts left
            }
            contactCount--;
            printf("Contact '%s' deleted successfully!\n", name);
            break;
        }
    }
    if (!found) {
        printf("Contact with name '%s' not found.\n", name);
    }
}