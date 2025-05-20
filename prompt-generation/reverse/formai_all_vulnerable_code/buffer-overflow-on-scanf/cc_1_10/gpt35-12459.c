//FormAI DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct Contact {
    char name[30];
    char phone[15];
};

struct Contact phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addContact() {
    if (numEntries == MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    struct Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    // Remove '\n' character from the end of the string
    if (newContact.name[strlen(newContact.name) - 1] == '\n') {
        newContact.name[strlen(newContact.name) - 1] = '\0';
    }
    printf("Enter phone: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    // Remove '\n' character from the end of the string
    if (newContact.phone[strlen(newContact.phone) - 1] == '\n') {
        newContact.phone[strlen(newContact.phone) - 1] = '\0';
    }

    phoneBook[numEntries++] = newContact;
}

void searchContact(char *name) {
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            printf("%s's phone number is %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found\n");
    }
}

void listContacts() {
    printf("Phone Book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d. %s: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Add Contact\n2. Search Contact\n3. List Contacts\n4. Quit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // consume '\n' character left by scanf
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                printf("Enter name to search: ");
                char searchName[30];
                fgets(searchName, sizeof(searchName), stdin);
                // Remove '\n' character from the end of the string
                if (searchName[strlen(searchName) - 1] == '\n') {
                    searchName[strlen(searchName) - 1] = '\0';
                }
                searchContact(searchName);
                break;
            case 3:
                listContacts();
                break;
            case 4:
                printf("Exiting Phone Book\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again\n");
        }
    }
    return 0;
}