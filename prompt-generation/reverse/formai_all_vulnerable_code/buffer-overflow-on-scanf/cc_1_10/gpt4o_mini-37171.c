//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: multivariable
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
        printf("Phone Book is full! Can't add more contacts.\n");
        return;
    }
    
    printf("Enter Name: ");
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = '\0'; // Remove newline

    printf("Enter Phone: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = '\0'; // Remove newline

    contactCount++;
    printf("Contact added successfully!\n\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts found!\n\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("\n");
}

void deleteContact() {
    if (contactCount == 0) {
        printf("No contacts available to delete!\n\n");
        return;
    }
    
    int index;
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);
    getchar(); // Consume the newline character

    if (index < 1 || index > contactCount) {
        printf("Invalid contact number!\n\n");
        return;
    }

    // Shift contacts to overwrite the deleted one
    for (int i = index - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;
    printf("Contact deleted successfully!\n\n");
}

void searchContact() {
    if (contactCount == 0) {
        printf("No contacts to search!\n\n");
        return;
    }

    char query[NAME_LENGTH];
    printf("Enter name or phone to search: ");
    fgets(query, NAME_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strstr(phoneBook[i].name, query) != NULL || strstr(phoneBook[i].phone, query) != NULL) {
            printf("Found: Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found!\n");
    }
    printf("\n");
}

void showMenu() {
    printf("Phone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}