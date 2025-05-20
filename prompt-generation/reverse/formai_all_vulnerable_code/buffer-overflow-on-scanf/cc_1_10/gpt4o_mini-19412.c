//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: random
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
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    Contact newContact;
    printf("Enter Name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Removing newline character

    printf("Enter Phone Number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Removing newline character

    phoneBook[contactCount++] = newContact;
    printf("Contact Added Successfully!\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("\n---- Contact List ----\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("----------------------\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter Name to Search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Removing newline character

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Found: Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact() {
    if (contactCount == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    int index;
    printf("Enter the index of contact to delete (1-%d): ", contactCount);
    scanf("%d", &index);
    getchar(); // Clear newline character from the buffer

    if (index < 1 || index > contactCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;
    printf("Contact Deleted Successfully!\n");
}

void menu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}