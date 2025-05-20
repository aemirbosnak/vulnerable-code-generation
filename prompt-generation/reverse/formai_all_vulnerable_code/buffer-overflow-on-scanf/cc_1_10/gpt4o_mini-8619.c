//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

void initPhoneBook(struct PhoneBook *pb) {
    pb->count = 0;
}

void addContact(struct PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count < MAX_CONTACTS) {
        strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH - 1);
        strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH - 1);
        pb->contacts[pb->count].name[NAME_LENGTH - 1] = '\0';
        pb->contacts[pb->count].phone[PHONE_LENGTH - 1] = '\0';
        pb->count++;
        printf("Contact %s added.\n", name);
    } else {
        printf("Phone book is full!\n");
    }
}

void displayContacts(const struct PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\n--- Phone Book ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("-------------------\n");
}

void searchContact(const struct PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Found! Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact %s not found.\n", name);
}

int main() {
    struct PhoneBook myPhoneBook;
    initPhoneBook(&myPhoneBook);

    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer 

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character

                printf("Enter phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = '\0'; // Remove newline character
                
                addContact(&myPhoneBook, name, phone);
                break;

            case 2:
                displayContacts(&myPhoneBook);
                break;

            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                
                searchContact(&myPhoneBook, name);
                break;

            case 4:
                printf("Exiting the phone book application.\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}