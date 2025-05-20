//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct contact {
    char name[50];
    char phone_number[15];
} contact_t;

contact_t contacts[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {
    printf("Enter the name of the contact: ");
    scanf("%s", contacts[contact_count].name);

    printf("Enter the phone number of the contact: ");
    scanf("%s", contacts[contact_count].phone_number);

    contact_count++;
}

void display_contacts() {
    printf("\nPhone Book:\n");
    printf("----------------\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone_number);
    }
}

void search_contact() {
    printf("\nEnter the name of the contact to search: ");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\n%s - %s\n", contacts[i].name, contacts[i].phone_number);
        }
    }
}

int main() {
    printf("Phone Book\n");
    printf("----------------\n");

    while (1) {
        printf("\n1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            display_contacts();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}