//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

typedef struct Contact {
    char name[50];
    char phone[20];
} Contact;

void add_contact(Contact contacts[], int num_contacts) {
    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter contact phone number: ");
    scanf("%s", contacts[num_contacts].phone);

    num_contacts++;
}

void display_contacts(Contact contacts[], int num_contacts) {
    printf("\nPhone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
    }
}

void search_contact(Contact contacts[], int num_contacts) {
    char search_name[50];

    printf("\nEnter contact name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, contacts[i].name) == 0) {
            printf("\n%s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nContact not found.\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("\n1. Add contact\n2. Display contacts\n3. Search contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact(contacts, num_contacts);
            break;
        case 2:
            display_contacts(contacts, num_contacts);
            break;
        case 3:
            search_contact(contacts, num_contacts);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}