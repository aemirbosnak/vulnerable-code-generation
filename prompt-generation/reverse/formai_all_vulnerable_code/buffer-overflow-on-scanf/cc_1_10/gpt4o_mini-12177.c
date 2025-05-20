//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: shape shifting
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
    Contact *contacts;
    int count;
} PhoneBook;

void initPhoneBook(PhoneBook *pb) {
    pb->contacts = malloc(MAX_CONTACTS * sizeof(Contact));
    pb->count = 0;
}

void freePhoneBook(PhoneBook *pb) {
    free(pb->contacts);
}

void addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count < MAX_CONTACTS) {
        strcpy(pb->contacts[pb->count].name, name);
        strcpy(pb->contacts[pb->count].phone, phone);
        pb->count++;
        printf("Contact added: %s, %s\n", name, phone);
    } else {
        printf("Phonebook is full! Cannot add more contacts.\n");
    }
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n--- Phonebook Contacts ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int findContactIndex(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void deleteContact(PhoneBook *pb, const char *name) {
    int index = findContactIndex(pb, name);
    if (index != -1) {
        // Shift contacts down
        for (int i = index; i < pb->count - 1; i++) {
            pb->contacts[i] = pb->contacts[i + 1];
        }
        pb->count--;
        printf("Contact deleted: %s\n", name);
    } else {
        printf("Contact not found: %s\n", name);
    }
}

void searchContact(const PhoneBook *pb, const char *name) {
    int index = findContactIndex(pb, name);
    if (index != -1) {
        printf("Contact found: Name: %s, Phone: %s\n", pb->contacts[index].name, pb->contacts[index].phone);
    } else {
        printf("Contact not found: %s\n", name);
    }
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

int main() {
    PhoneBook pb;
    initPhoneBook(&pb);

    int choice;
    char name[NAME_LEN], phone[PHONE_LEN];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter phone: ");
                fgets(phone, PHONE_LEN, stdin);
                phone[strcspn(phone, "\n")] = 0; // remove newline
                addContact(&pb, name, phone);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                printf("Enter the name to search: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                searchContact(&pb, name);
                break;
            case 4:
                printf("Enter the name to delete: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                deleteContact(&pb, name);
                break;
            case 5:
                freePhoneBook(&pb);
                printf("Exiting the phone book. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}