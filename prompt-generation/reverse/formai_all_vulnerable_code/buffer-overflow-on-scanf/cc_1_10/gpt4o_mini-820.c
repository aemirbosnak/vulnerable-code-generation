//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: calm
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
        strncpy(pb->contacts[pb->size].name, name, NAME_LEN - 1);
        pb->contacts[pb->size].name[NAME_LEN - 1] = '\0';
        strncpy(pb->contacts[pb->size].phone, phone, PHONE_LEN - 1);
        pb->contacts[pb->size].phone[PHONE_LEN - 1] = '\0';
        pb->size++;
        printf("Contact added: %s, %s\n", name, phone);
    } else {
        printf("Phone book is full! Cannot add more contacts.\n");
    }
}

void displayContacts(PhoneBook *pb) {
    if (pb->size == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found contact: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void menu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
    printf("-----------------------\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    int choice;
    char name[NAME_LEN];
    char phone[PHONE_LEN];

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar();  // to consume the newline character after entering the choice

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;  // Removing newline character
                printf("Enter Phone: ");
                fgets(phone, PHONE_LEN, stdin);
                phone[strcspn(phone, "\n")] = 0;  // Removing newline character
                addContact(&pb, name, phone);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                printf("Enter Name to search: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;  // Removing newline character
                searchContact(&pb, name);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}