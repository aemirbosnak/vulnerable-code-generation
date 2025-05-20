//FormAI DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char number[15];
} PhoneBook;

void addContact(PhoneBook[], int *);
void viewContacts(PhoneBook[], int);
void searchContact(PhoneBook[], int);

int main() {
    PhoneBook contacts[100];
    int numContacts = 0;

    int choice = 0;
    while(choice != 4) {
        printf("\nWelcome to the Phone Book Application\n\n");
        printf("1. Add a Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                viewContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                printf("\nThank you for using the Phone Book Application!\n\n");        
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}

void addContact(PhoneBook contacts[], int *numContacts) {
    printf("\nAdding new contact...\n\n");

    printf("Enter the name: ");
    scanf("%s", &contacts[*numContacts].name);

    printf("Enter the number: ");
    scanf("%s", &contacts[*numContacts].number);

    (*numContacts)++;
    printf("\nContact added successfully!\n\n");
}

void viewContacts(PhoneBook contacts[], int numContacts) {
    printf("\nContacts:\n\n");

    if(numContacts == 0) {
        printf("No contacts found.\n\n");
        return;
    }

    for(int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].number);
    }
}

void searchContact(PhoneBook contacts[], int numContacts) {
    char name[30];
    printf("\nEnter the name to search: ");
    scanf("%s", name);

    for(int i = 0; i < numContacts; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            printf("\nContact found:\n\n");
            printf("%s - %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("\nContact not found.\n\n");
}