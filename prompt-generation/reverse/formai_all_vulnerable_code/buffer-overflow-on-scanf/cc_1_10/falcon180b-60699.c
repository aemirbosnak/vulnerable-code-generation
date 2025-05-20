//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 1000

typedef struct {
    char name[51];
    char phone_number[21];
} Contact;

int add_contact(Contact contacts[], int num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone_number);

    num_contacts++;

    return num_contacts;
}

int search_contact(Contact contacts[], int num_contacts, char* name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Phone number: %s\n", contacts[i].phone_number);
            return 1;
        }
    }

    printf("Contact not found.\n");
    return 0;
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        int choice;

        printf("\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            num_contacts = add_contact(contacts, num_contacts);
            break;

        case 2:
            printf("Enter name to search: ");
            char name[51];
            scanf("%s", name);

            search_contact(contacts, num_contacts, name);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}