//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: irregular
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
        printf("\033[1;31mError:\033[0m Phone book is full!\n");
        return;
    }
    
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;  // Remove newline character
    
    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;  // Remove newline character
    
    phoneBook[contactCount] = newContact;
    contactCount++;
    printf("\033[1;32mContact added successfully!\033[0m\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("\033[1;33mNo contacts in the phone book.\033[0m\n");
        return;
    }

    printf("\n\033[1;34mPhone Book Contacts:\033[0m\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: \n", i + 1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone: %s\n\n", phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("\n\033[1;36mContact Found:\033[0m\n");
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n\n", phoneBook[i].phone);
            return;
        }
    }
    printf("\033[1;31mContact not found!\033[0m\n");
}

void deleteContact() {
    char delName[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(delName, NAME_LENGTH, stdin);
    delName[strcspn(delName, "\n")] = 0;

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, delName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("\033[1;32mContact deleted successfully!\033[0m\n");
            return;
        }
    }
    printf("\033[1;31mContact not found!\033[0m\n");
}

void menu() {
    while (1) {
        printf("\n\033[1;35m---- Phone Book Menu ----\033[0m\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("\033[1;33mSelect an option: \033[0m");

        int choice = 0;
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("\033[1;34mExiting... Thank you!\033[0m\n"); exit(0);
            default: printf("\033[1;31mInvalid option! Try again.\033[0m\n");
        }
    }
}

int main() {
    printf("\033[1;32mWelcome to the Phone Book Application!\033[0m\n");
    menu();
    return 0;
}