//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_ENTRIES];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count >= MAX_ENTRIES) {
        printf("Phone Book is full. Cannot add more contacts.\n");
        return;
    }
    strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH);
    strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH);
    pb->count++;
    printf("Contact added: %s, %s\n", name, phone);
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("Phone Book is empty.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d: Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Found Contact: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact deleted: %s\n", name);
            return;
        }
    }
    printf("Contact not found for deletion: %s\n", name);
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);

    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                printf("Enter phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = '\0'; // remove newline
                addContact(&myPhoneBook, name, phone);
                break;

            case 2:
                displayContacts(&myPhoneBook);
                break;

            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                searchContact(&myPhoneBook, name);
                break;

            case 4:
                printf("Enter name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                deleteContact(&myPhoneBook, name);
                break;

            case 5:
                printf("Exiting Phone Book...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}