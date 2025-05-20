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

void initializePhoneBook(PhoneBook* pb) {
    pb->size = 0;
}

void addContact(PhoneBook* pb, const char* name, const char* phone) {
    if (pb->size < MAX_CONTACTS) {
        strncpy(pb->contacts[pb->size].name, name, NAME_LEN);
        strncpy(pb->contacts[pb->size].phone, phone, PHONE_LEN);
        pb->size++;
        printf("Contact %s added successfully.\n", name);
    } else {
        printf("Phone book is full, cannot add more contacts.\n");
    }
}

void viewContacts(const PhoneBook* pb) {
    printf("\nList of Contacts:\n");
    for (int i = 0; i < pb->size; ++i) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook* pb, const char* name) {
    for (int i = 0; i < pb->size; ++i) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact %s not found.\n", name);
}

void menu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
    printf("-----------------------\n");
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);
    
    int choice;
    char name[NAME_LEN], phone[PHONE_LEN];

    while (1) {
        menu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name); // Read name with spaces
                printf("Enter phone number: ");
                scanf(" %[^\n]%*c", phone); // Read phone number
                addContact(&myPhoneBook, name, phone);
                break;
            case 2:
                viewContacts(&myPhoneBook);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf(" %[^\n]%*c", name);
                searchContact(&myPhoneBook, name);
                break;
            case 4:
                printf("Exiting the phone book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please choose again.\n");
        }
    }

    return 0;
}