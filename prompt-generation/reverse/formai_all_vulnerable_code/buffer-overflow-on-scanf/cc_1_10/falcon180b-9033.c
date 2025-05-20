//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20
#define MAX_CONTACTS 100

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

int main() {
    char choice;
    int num_contacts = 0;
    Contact contacts[MAX_CONTACTS];

    printf("Welcome to the phone book!\n");
    printf("Enter 'a' to add a contact,'s' to search for a contact, 'd' to delete a contact, or 'q' to quit.\n");

    while (choice!= 'q') {
        scanf(" %c", &choice);

        switch (choice) {
        case 'a':
            printf("Enter the name of the contact: ");
            scanf(" %s", contacts[num_contacts].name);

            printf("Enter the phone number of the contact: ");
            scanf(" %s", contacts[num_contacts].number);

            num_contacts++;
            break;

        case's':
            printf("Enter the name to search for: ");
            char search_name[MAX_NAME_LEN];
            scanf(" %s", search_name);

            for (int i = 0; i < num_contacts; i++) {
                if (strcmp(contacts[i].name, search_name) == 0) {
                    printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
                }
            }

            break;

        case 'd':
            printf("Enter the name of the contact to delete: ");
            char delete_name[MAX_NAME_LEN];
            scanf(" %s", delete_name);

            for (int i = 0; i < num_contacts; i++) {
                if (strcmp(contacts[i].name, delete_name) == 0) {
                    strcpy(contacts[i].name, "");
                    strcpy(contacts[i].number, "");
                    num_contacts--;
                }
            }

            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    printf("Exiting the phone book...\n");

    return 0;
}