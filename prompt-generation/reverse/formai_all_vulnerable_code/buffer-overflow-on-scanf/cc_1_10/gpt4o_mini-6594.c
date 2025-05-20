//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: ephemeral
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
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", phoneBook[contactCount].name); // Read string with spaces
    printf("Enter Phone Number: ");
    scanf(" %[^\n]%*c", phoneBook[contactCount].phone); // Read string with spaces
    contactCount++;
    printf("Contact added successfully!\n\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("Phone book is empty!\n\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("\n");
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]%*c", searchName);
    
    printf("Search Results:\n");
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strstr(phoneBook[i].name, searchName) != NULL) {
            printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found with that name.\n");
    }
    printf("\n");
}

void deleteContact() {
    int index;
    displayContacts();
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > contactCount) {
        printf("Invalid index! Please try again.\n\n");
        return;
    }
    for (int i = index - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;
    printf("Contact deleted successfully!\n\n");
}

void menu() {
    printf("===== Phone Book Menu =====\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("===========================\n");
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        printf("\n");

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
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n\n");
        }
    }
    return 0;
}