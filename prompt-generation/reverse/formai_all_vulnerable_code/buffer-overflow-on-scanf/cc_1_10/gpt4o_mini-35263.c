//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: innovative
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
    Contact *contacts;
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->contacts = (Contact *)malloc(MAX_ENTRIES * sizeof(Contact));
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count < MAX_ENTRIES) {
        printf("Enter name: ");
        scanf(" %[^\n]s", pb->contacts[pb->count].name);
        printf("Enter phone number: ");
        scanf(" %[^\n]s", pb->contacts[pb->count].phone);
        pb->count++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone book is full!\n");
    }
}

void viewContacts(PhoneBook *pb) {
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("\n");
}

void searchContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]s", name);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf(" %[^\n]s", name);
    
    int index = -1;
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        for (int i = index; i < pb->count - 1; i++) {
            pb->contacts[i] = pb->contacts[i + 1];
        }
        pb->count--;
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void freePhoneBook(PhoneBook *pb) {
    free(pb->contacts);
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);
    
    int choice;
    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&phoneBook);
                break;
            case 2:
                viewContacts(&phoneBook);
                break;
            case 3:
                searchContact(&phoneBook);
                break;
            case 4:
                deleteContact(&phoneBook);
                break;
            case 5:
                printf("Exiting the Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    freePhoneBook(&phoneBook);
    return 0;
}