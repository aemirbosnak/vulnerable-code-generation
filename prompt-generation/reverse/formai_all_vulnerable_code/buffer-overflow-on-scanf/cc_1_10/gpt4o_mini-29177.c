//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int size;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->size = 0;
}

void addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->size < MAX_CONTACTS) {
        strncpy(pb->contacts[pb->size].name, name, NAME_LEN);
        strncpy(pb->contacts[pb->size].phone, phone, PHONE_LEN);
        pb->size++;
        printf("Contact added: %s, %s\n", name, phone);
    } else {
        printf("Phone book is full! Cannot add more contacts.\n");
    }
}

void displayContacts(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("Contacts in the phone book:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. %s: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Found contact: %s -> %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            // Shift contacts down to fill the gap
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            printf("Deleted contact: %s\n", name);
            return;
        }
    }
    printf("Contact not found for deletion: %s\n", name);
}

void showMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);

    int choice;
    char name[NAME_LEN];
    char phone[PHONE_LEN];

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter phone: ");
                fgets(phone, PHONE_LEN, stdin);
                phone[strcspn(phone, "\n")] = '\0'; // Remove newline
                addContact(&myPhoneBook, name, phone);
                break;
            case 2:
                displayContacts(&myPhoneBook);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                searchContact(&myPhoneBook, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                deleteContact(&myPhoneBook, name);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}