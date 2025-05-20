//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    char phone[20];
} Contact;

Contact contacts[MAX_ENTRIES];
int numContacts = 0;

void searchByName(char name[]) {
    int i;
    printf("\nSearching for '%s'...\n", name);
    for(i = 0; i < numContacts; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Not found.\n");
}

void addContact() {
    Contact newContact;
    printf("\nEnter contact name: ");
    scanf("%s", newContact.name);
    printf("Enter contact phone: ");
    scanf("%s", newContact.phone);
    contacts[numContacts++] = newContact;
    printf("Contact added successfully.\n");
}

int main() {
    int choice;
    char name[30];

    do {
        printf("\n-----------------------\n");
        printf("| Romeo & Juliet PhoneBook |\n");
        printf("-----------------------|\n");
        printf("| 1. Add Contact        |\n");
        printf("| 2. Search by Name     |\n");
        printf("| 3. Exit              |\n");
        printf("-----------------------|\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchByName(name);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}