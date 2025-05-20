//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
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
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
    printf("Initializing the phone book... Ready for entry!\n");
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("The phone book is full! Can't add more contacts!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]s", pb->contacts[pb->count].name);
    
    printf("Enter phone number: ");
    scanf(" %[^\n]s", pb->contacts[pb->count].phone);
    
    pb->count++;
    printf("Contact added: %s, %s\n", pb->contacts[pb->count - 1].name, pb->contacts[pb->count - 1].phone);
}

void displayContacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("The phone book is empty! Who are you trying to look for?\n");
        return;
    }

    printf("\n=== Phone Book Contacts ===\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("=========================\n");
}

void searchContact(PhoneBook *pb) {
    char name[NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }

    printf("Contact named '%s' not found!\n", name);
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Deleting contact: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            return;
        }
    }

    printf("Contact named '%s' not found for deletion!\n", name);
}

void displayMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("=========================\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);

    int choice;
    do {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

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
                printf("Exiting the phone book. May your contacts be forever with you!\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}