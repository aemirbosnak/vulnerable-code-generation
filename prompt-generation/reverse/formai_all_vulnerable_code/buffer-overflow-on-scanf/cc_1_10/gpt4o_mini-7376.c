//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: secure
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

int addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count >= MAX_ENTRIES) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return -1;
    }

    strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH);
    strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH);
    pb->count++;
    return 0;
}

void listContacts(const PhoneBook *pb) {
    printf("\n--- Phone Book Contacts ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d: %s, %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("---------------------------\n");
}

int findContactIndex(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int deleteContact(PhoneBook *pb, const char *name) {
    int index = findContactIndex(pb, name);
    if (index == -1) {
        printf("Contact not found!\n");
        return -1;
    }

    for (int i = index; i < pb->count - 1; i++) {
        pb->contacts[i] = pb->contacts[i + 1];
    }
    pb->count--;
    return 0;
}

void editContact(PhoneBook *pb, const char *name, const char *newPhone) {
    int index = findContactIndex(pb, name);
    
    if (index != -1) {
        strncpy(pb->contacts[index].phone, newPhone, PHONE_LENGTH);
        printf("Contact updated!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Find Contact\n");
    printf("4. Edit Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("-----------------------\n");
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(&phoneBook, name, phone);
                break;

            case 2:
                listContacts(&phoneBook);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                int index = findContactIndex(&phoneBook, name);
                if (index != -1) {
                    printf("Found contact: %s, %s\n", phoneBook.contacts[index].name, phoneBook.contacts[index].phone);
                } else {
                    printf("Contact not found!\n");
                }
                break;

            case 4:
                printf("Enter name of the contact to edit: ");
                scanf("%s", name);
                printf("Enter new phone number: ");
                scanf("%s", phone);
                editContact(&phoneBook, name, phone);
                break;

            case 5:
                printf("Enter name of the contact to delete: ");
                scanf("%s", name);
                deleteContact(&phoneBook, name);
                break;

            case 6:
                printf("Exiting... Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}