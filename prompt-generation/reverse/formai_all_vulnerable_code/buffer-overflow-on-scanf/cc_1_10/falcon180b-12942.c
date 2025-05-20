//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

void add_contact(Contact *contact_list, int num_contacts) {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", contact_list[num_contacts].name);

    printf("Enter phone number (up to %d digits): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", contact_list[num_contacts].number);

    num_contacts++;
}

void display_contacts(Contact *contact_list, int num_contacts) {
    printf("Phone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contact_list[i].name, contact_list[i].number);
    }
}

int main() {
    Contact contact_list[MAX_CONTACTS];
    int num_contacts = 0;

    while (num_contacts < MAX_CONTACTS) {
        printf("1. Add contact\n2. Display contacts\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contact_list, num_contacts);
                break;
            case 2:
                display_contacts(contact_list, num_contacts);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}