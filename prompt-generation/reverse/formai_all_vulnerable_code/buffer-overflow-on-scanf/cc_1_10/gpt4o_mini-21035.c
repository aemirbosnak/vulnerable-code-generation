//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: future-proof
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

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

int addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count < MAX_CONTACTS) {
        strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH);
        strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH);
        pb->count++;
        return 1; // success
    }
    return 0; // failure, phone book is full
}

int deleteContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strncmp(pb->contacts[i].name, name, NAME_LENGTH) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            return 1; // success
        }
    }
    return 0; // failure, contact not found
}

Contact* searchContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strncmp(pb->contacts[i].name, name, NAME_LENGTH) == 0) {
            return &pb->contacts[i]; // found
        }
    }
    return NULL; // not found
}

void displayContacts(PhoneBook *pb) {
    printf("Phone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void printMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline

                printf("Enter Phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // remove newline

                if (addContact(&pb, name, phone)) {
                    printf("Contact added successfully!\n");
                } else {
                    printf("Failed to add contact. Phone book might be full.\n");
                }
                break;

            case 2:
                printf("Enter Name of contact to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline

                if (deleteContact(&pb, name)) {
                    printf("Contact deleted successfully!\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 3:
                printf("Enter Name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline

                Contact *contact = searchContact(&pb, name);
                if (contact) {
                    printf("Found: %s - %s\n", contact->name, contact->phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 4:
                displayContacts(&pb);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}