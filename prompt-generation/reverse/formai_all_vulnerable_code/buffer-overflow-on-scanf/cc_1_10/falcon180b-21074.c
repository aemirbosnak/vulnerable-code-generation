//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

void add_contact(Contact *contacts, int num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].number);

    printf("Enter email: ");
    scanf("%s", contacts[num_contacts].email);

    num_contacts++;
}

void search_contact(Contact *contacts, int num_contacts) {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].number);
            printf("Email: %s\n\n", contacts[i].email);
        }
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (num_contacts < MAX_CONTACTS) {
        printf("\n1. Add contact\n2. Search contact\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}