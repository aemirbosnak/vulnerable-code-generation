//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: shape shifting
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

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initPhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    Contact newContact;
    printf("Enter Name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    strtok(newContact.name, "\n"); // Remove newline character
    printf("Enter Phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    strtok(newContact.phone, "\n"); // Remove newline character
    pb->contacts[pb->count++] = newContact;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook *pb) {
    printf("Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter Name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline character

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter Name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline character

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            pb->contacts[i] = pb->contacts[pb->count - 1]; // Replace with last contact
            pb->count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
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
    PhoneBook pb;
    initPhoneBook(&pb);
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                searchContact(&pb);
                break;
            case 4:
                deleteContact(&pb);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}