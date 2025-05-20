//FormAI DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100  // Maximum number of contacts in phone book
#define MAX_NAME_LENGTH 50  // Maximum length of contact name
#define MAX_PHONE_LENGTH 15  // Maximum length of phone number

// Struct for contact information
struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

// Function prototypes
void addContact(struct Contact* phonebook, int* numContacts);
int findContact(struct Contact* phonebook, int numContacts, char* searchName);
void printPhonebook(struct Contact* phonebook, int numContacts);

int main() {
    struct Contact phonebook[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    while (1) {
        printf("Phone Book\n");
        printf("==========\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Print phone book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
            case 1:
                addContact(phonebook, &numContacts);
                break;
            case 2: {
                char searchName[MAX_NAME_LENGTH];

                printf("Enter contact name: ");
                fgets(searchName, MAX_NAME_LENGTH, stdin);

                // Strip newline character from input
                searchName[strcspn(searchName, "\n")] = '\0';

                int index = findContact(phonebook, numContacts, searchName);

                if (index == -1) {
                    printf("Contact not found\n");
                } else {
                    printf("Contact found:\n");
                    printf("Name: %s\n", phonebook[index].name);
                    printf("Phone: %s\n", phonebook[index].phone);
                }
                
                break;
            }
            case 3:
                printPhonebook(phonebook, numContacts);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}

// Function to add a new contact to the phone book
void addContact(struct Contact* phonebook, int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phone book is full\n");
        return;
    }

    printf("Enter contact name: ");
    fgets(phonebook[*numContacts].name, MAX_NAME_LENGTH, stdin);

    // Strip newline character from input
    phonebook[*numContacts].name[strcspn(phonebook[*numContacts].name, "\n")] = '\0';

    printf("Enter contact phone number: ");
    fgets(phonebook[*numContacts].phone, MAX_PHONE_LENGTH, stdin);

    // Strip newline character from input
    phonebook[*numContacts].phone[strcspn(phonebook[*numContacts].phone, "\n")] = '\0';

    (*numContacts)++;
}

// Function to find a contact in the phone book by name
int findContact(struct Contact* phonebook, int numContacts, char* searchName) {
    for (int i = 0; i < numContacts; i++) {
        // Convert both strings to uppercase for case-insensitive search
        char nameUpper[MAX_NAME_LENGTH];
        strcpy(nameUpper, phonebook[i].name);
        for (int j = 0; j < strlen(nameUpper); j++) {
            nameUpper[j] = toupper(nameUpper[j]);
        }
        char searchUpper[MAX_NAME_LENGTH];
        strcpy(searchUpper, searchName);
        for (int j = 0; j < strlen(searchUpper); j++) {
            searchUpper[j] = toupper(searchUpper[j]);
        }
        
        if (strcmp(nameUpper, searchUpper) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to print the entire phone book
void printPhonebook(struct Contact* phonebook, int numContacts) {
    printf("Phone Book (%d contacts)\n", numContacts);
    printf("========================\n");

    for (int i = 0; i < numContacts; i++) {
        printf("Contact %d:\n", i+1);
        printf("Name: %s\n", phonebook[i].name);
        printf("Phone: %s\n", phonebook[i].phone);
    }
}