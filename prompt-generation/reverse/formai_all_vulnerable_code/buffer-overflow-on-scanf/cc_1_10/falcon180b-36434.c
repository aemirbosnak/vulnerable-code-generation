//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void addContact(struct Contact contacts[], int numContacts);
void displayAllContacts(struct Contact contacts[], int numContacts);
void deleteContact(struct Contact contacts[], int numContacts);
void searchContact(struct Contact contacts[], int numContacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    printf("Phone Book\n");

    while(1) {
        printf("\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, numContacts);
                break;
            case 2:
                displayAllContacts(contacts, numContacts);
                break;
            case 3:
                deleteContact(contacts, numContacts);
                break;
            case 4:
                searchContact(contacts, numContacts);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addContact(struct Contact contacts[], int numContacts) {
    printf("Enter name: ");
    scanf("%s", contacts[numContacts].name);

    printf("Enter number: ");
    scanf("%s", contacts[numContacts].number);

    numContacts++;
}

void displayAllContacts(struct Contact contacts[], int numContacts) {
    printf("\nAll Contacts:\n");

    for(int i=0; i<numContacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].number);
    }
}

void deleteContact(struct Contact contacts[], int numContacts) {
    printf("\nEnter name of contact to delete: ");
    scanf("%s", contacts[numContacts].name);
}

void searchContact(struct Contact contacts[], int numContacts) {
    printf("\nEnter name of contact to search: ");
    scanf("%s", contacts[numContacts].name);

    for(int i=0; i<numContacts; i++) {
        if(strcmp(contacts[i].name, contacts[numContacts].name) == 0) {
            printf("\n%s - %s\n", contacts[i].name, contacts[i].number);
        }
    }
}