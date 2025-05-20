//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: all-encompassing
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

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    Contact new_contact;
    printf("Enter Name: ");
    getchar(); // to consume newline from previous input
    fgets(new_contact.name, NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0'; // remove newline

    printf("Enter Phone: ");
    fgets(new_contact.phone, PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = '\0'; // remove newline

    printf("Enter Email: ");
    fgets(new_contact.email, EMAIL_LENGTH, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = '\0'; // remove newline

    pb->contacts[pb->count++] = new_contact;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d:\n", i + 1);
        printf(" Name: %s\n", pb->contacts[i].name);
        printf(" Phone: %s\n", pb->contacts[i].phone);
        printf(" Email: %s\n\n", pb->contacts[i].email);
    }
}

void searchContact(const PhoneBook *pb) {
    char search[NAME_LENGTH];
    printf("Enter Name to search: ");
    getchar(); // consume newline
    fgets(search, NAME_LENGTH, stdin);
    search[strcspn(search, "\n")] = '\0'; // remove newline

    printf("\nSearch Results:\n");
    for (int i = 0; i < pb->count; i++) {
        if (strstr(pb->contacts[i].name, search) != NULL) {
            printf("Contact Found:\n");
            printf(" Name: %s\n", pb->contacts[i].name);
            printf(" Phone: %s\n", pb->contacts[i].phone);
            printf(" Email: %s\n\n", pb->contacts[i].email);
            return;
        }
    }
    printf("No contact found with that name.\n");
}

void deleteContact(PhoneBook *pb) {
    char nameToDelete[NAME_LENGTH];
    printf("Enter Name of the contact to delete: ");
    getchar(); // consume newline
    fgets(nameToDelete, NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = '\0'; // remove newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, nameToDelete) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("No contact found with that name to delete.\n");
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&phoneBook);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                searchContact(&phoneBook);
                break;
            case 4:
                deleteContact(&phoneBook);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}