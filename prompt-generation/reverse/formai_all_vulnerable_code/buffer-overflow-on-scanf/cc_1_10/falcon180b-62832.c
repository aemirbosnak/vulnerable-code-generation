//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct contact {
    char name[50];
    char phone_number[20];
} Contact;

void add_contact(Contact *contacts, int num_contacts) {
    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter contact phone number: ");
    scanf("%s", contacts[num_contacts].phone_number);
    num_contacts++;
}

void display_contacts(Contact *contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone_number);
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (num_contacts < MAX_CONTACTS) {
        printf("1. Add contact\n2. Display contacts\n3. Exit\n");
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}