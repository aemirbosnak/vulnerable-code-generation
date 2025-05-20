//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: minimalist
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
    int size;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->size = 0;
}

void addContact(PhoneBook *pb, const char* name, const char* phone) {
    if (pb->size < MAX_ENTRIES) {
        strncpy(pb->contacts[pb->size].name, name, NAME_LENGTH);
        strncpy(pb->contacts[pb->size].phone, phone, PHONE_LENGTH);
        pb->size++;
        printf("Contact added: %s, %s\n", name, phone);
    } else {
        printf("Phone book is full!\n");
    }
}

void displayContacts(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts in phone book.\n");
        return;
    }
    printf("\nPhone Book:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. %s: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *pb, const char* name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(PhoneBook *pb, const char* name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            printf("Contact deleted: %s\n", name);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void clearPhoneBook(PhoneBook *pb) {
    pb->size = 0;
    printf("Phone book cleared.\n");
}

void showMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Clear Phone Book\n");
    printf("6. Exit\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(&pb, name, phone);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(&pb, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(&pb, name);
                break;
            case 5:
                clearPhoneBook(&pb);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}