//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 15

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char* name, char* number) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].number, number);

    num_contacts++;
}

void search_contact(char* name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(char* name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].number, "");

            printf("Contact deleted.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    char choice;

    printf("Phone Book\n");

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts - 1].name);
                printf("Enter number: ");
                scanf("%s", contacts[num_contacts - 1].number);
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", contacts[num_contacts - 1].name);
                search_contact(contacts[num_contacts - 1].name);
                break;
            case '3':
                printf("Enter name to delete: ");
                scanf("%s", contacts[num_contacts - 1].name);
                delete_contact(contacts[num_contacts - 1].name);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}