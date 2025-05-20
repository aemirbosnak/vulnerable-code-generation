//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: scientific
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

void addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    strncpy(pb->contacts[pb->count].name, name, NAME_LENGTH);
    strncpy(pb->contacts[pb->count].phone, phone, PHONE_LENGTH);
    pb->count++;
    printf("Contact %s has been added.\n", name);
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact %s not found.\n", name);
}

void deleteContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            pb->contacts[i] = pb->contacts[pb->count - 1]; // Replace with the last contact
            pb->count--;
            printf("Contact %s has been deleted.\n", name);
            return;
        }
    }
    printf("Contact %s not found for deletion.\n", name);
}

void updateContact(PhoneBook *pb, const char *name, const char *newPhone) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            strncpy(pb->contacts[i].phone, newPhone, PHONE_LENGTH);
            printf("Contact %s has been updated to new phone %s.\n", name, newPhone);
            return;
        }
    }
    printf("Contact %s not found for update.\n", name);
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);

    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                addContact(&myPhoneBook, name, phone);
                break;
            case 2:
                displayContacts(&myPhoneBook);
                break;
            case 3:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                searchContact(&myPhoneBook, name);
                break;
            case 4:
                printf("Enter Name to Delete: ");
                scanf("%s", name);
                deleteContact(&myPhoneBook, name);
                break;
            case 5:
                printf("Enter Name to Update: ");
                scanf("%s", name);
                printf("Enter New Phone: ");
                scanf("%s", phone);
                updateContact(&myPhoneBook, name, phone);
                break;
            case 6:
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}