//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 30
#define NUMBER_LENGTH 15

/* Declaring a structure for contact information */
struct contact {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
};

/* Function prototypes */
void addContact(struct contact[], int *);
void findContact(struct contact[], int);
void printContacts(struct contact[], int);

int main() {
    struct contact phonebook[100];  // Maximum of 100 contacts
    int numOfContacts = 0;  // Number of contacts currently in the phonebook
    int choice;  // User's choice in the menu

    while(1) {  // Loop through menu until user chooses to exit
        printf("\n\n-----PHONE BOOK-----\n");
        printf("1) Add Contact\n");
        printf("2) Find Contact\n");
        printf("3) Print Contacts\n");
        printf("4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // Clearing newline from the input buffer

        switch(choice) {
            case 1:
                addContact(phonebook, &numOfContacts);
                break;
            case 2:
                findContact(phonebook, numOfContacts);
                break;
            case 3:
                printContacts(phonebook, numOfContacts);
                break;
            case 4:
                printf("Exiting phone book. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}

/* Function to add a contact to the phonebook */
void addContact(struct contact phonebook[], int *numOfContacts) {
    if(*numOfContacts == 100) {  // Maximum contacts reached
        printf("\nPhonebook is full. Cannot add another contact.\n");
        return;
    }

    printf("\nEnter name: ");
    fgets(phonebook[*numOfContacts].name, NAME_LENGTH, stdin);

    printf("Enter phone number: ");
    fgets(phonebook[*numOfContacts].number, NUMBER_LENGTH, stdin);

    printf("\nContact added successfully!\n");
    (*numOfContacts)++;  // Incrementing the number of contacts in the phonebook
}

/* Function to find a contact in the phonebook */
void findContact(struct contact phonebook[], int numOfContacts) {
    char query[NAME_LENGTH];
    int found = 0;  // Flag for whether a contact was found or not

    printf("\nEnter name to search for: ");
    fgets(query, NAME_LENGTH, stdin);

    printf("\nSearch results:\n");
    for(int i = 0; i < numOfContacts; i++) {
        if(strstr(phonebook[i].name, query) != NULL) {  // Name match
            printf("Name: %s", phonebook[i].name);
            printf("Number: %s", phonebook[i].number);
            found = 1;  // Setting flag to indicate contact was found
        }
    }

    if(!found) {
        printf("No matching contact found.\n");
    }
}

/* Function to print all contacts in the phonebook */
void printContacts(struct contact phonebook[], int numOfContacts) {
    printf("\nContacts in phonebook:\n");
    for(int i = 0; i < numOfContacts; i++) {
        printf("Name: %s", phonebook[i].name);
        printf("Number: %s", phonebook[i].number);
    }
}