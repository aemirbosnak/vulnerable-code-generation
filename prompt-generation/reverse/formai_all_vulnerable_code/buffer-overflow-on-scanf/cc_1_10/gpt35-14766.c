//FormAI DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook {
    char name[50];
    long int number;
};

void addContact(struct phonebook*, int*);
void displayContacts(struct phonebook*, int*);
void searchContact(struct phonebook*, int*);

int main() {
    int choice;
    int numcontacts = 0;
    struct phonebook* contacts = malloc(1 * sizeof(struct phonebook));

    printf("Welcome to your Phone Book!\n");

    do {
        printf("\nWhat would you like to do? Press...\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, &numcontacts);
                break;
            case 2:
                displayContacts(contacts, &numcontacts);
                break;
            case 3:
                searchContact(contacts, &numcontacts);
                break;
            case 0:
                printf("\nThank you for using your Phone Book!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 0);

    free(contacts);

    return 0;
}

void addContact(struct phonebook* contacts, int* numcontacts) {
    *numcontacts += 1;
    contacts = realloc(contacts, *numcontacts * sizeof(struct phonebook));

    printf("\nEnter the name of the contact: ");
    scanf("%s", contacts[*numcontacts-1].name);
    printf("Enter the phone number of the contact: ");
    scanf("%ld", &contacts[*numcontacts-1].number);

    printf("\nContact added successfully!\n");
}

void displayContacts(struct phonebook* contacts, int* numcontacts) {
    if(*numcontacts == 0) {
        printf("\nThere are no contacts in your Phone Book yet.\n");
    } else {
        printf("\nHere are your %d contacts...\n", *numcontacts);
        for(int i=0; i<*numcontacts; i++) {
            printf("%s\t%ld\n", contacts[i].name, contacts[i].number);
        }
    }
}

void searchContact(struct phonebook* contacts, int* numcontacts) {
    char searchname[50];
    int foundcnt = 0;

    printf("\nEnter the name of the contact you want to search for: ");
    scanf("%s", searchname);

    for(int i=0; i<*numcontacts; i++) {
        if(strcmp(searchname, contacts[i].name) == 0) {
            printf("%s\t%ld\n", contacts[i].name, contacts[i].number);
            foundcnt++;
        }
    }

    if(foundcnt == 0) {
        printf("\nNo contact found matching %s.\n", searchname);
    } else {
        printf("\n%d matches found for %s.\n", foundcnt, searchname);
    }
}