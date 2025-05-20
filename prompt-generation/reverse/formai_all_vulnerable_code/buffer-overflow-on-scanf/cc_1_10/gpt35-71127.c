//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 // maximum number of contacts that can be added to the phone book

// structure for contact info
struct contact {
    char name[50];
    char phone[15];
};

// function to add a new contact to the phone book
void addContact(struct contact phonebook[], int *numContacts) {
    char name[50];
    char phone[15];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);
    // add contact to phonebook array
    strcpy(phonebook[*numContacts].name, name);
    strcpy(phonebook[*numContacts].phone, phone);
    // increase number of stored contacts
    (*numContacts)++;
}

// function to print all contacts in the phone book
void printContacts(struct contact phonebook[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

// function to search for a contact by name
void searchContact(struct contact phonebook[], int numContacts) {
    char searchTerm[50];
    printf("Enter search term: ");
    scanf("%s", searchTerm);
    for (int i = 0; i < numContacts; i++) {
        if (strstr(phonebook[i].name, searchTerm) != NULL) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

int main() {
    struct contact phonebook[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    do {
        // print menu
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Print All Contacts\n");
        printf("3. Search by Name\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        // handle choice
        switch (choice) {
            case 1:
                addContact(phonebook, &numContacts);
                break;
            case 2:
                printContacts(phonebook, numContacts);
                break;
            case 3:
                searchContact(phonebook, numContacts);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}