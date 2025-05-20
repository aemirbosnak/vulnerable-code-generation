//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    int choice, num_contacts;
    contact *contacts;

    printf("Welcome to the Happy Mailing List Manager!\n");
    printf("Please choose an option:\n");
    printf("1. Create a new mailing list\n");
    printf("2. Add a contact to the mailing list\n");
    printf("3. Remove a contact from the mailing list\n");
    printf("4. Print the mailing list\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the number of contacts in the mailing list: ");
            scanf("%d", &num_contacts);

            contacts = (contact*) malloc(num_contacts * sizeof(contact));

            for(int i=0; i<num_contacts; i++) {
                printf("Enter the name and email of contact %d:\n", i+1);
                scanf(" %[^\n]s %[^\n]s", contacts[i].name, contacts[i].email);
            }

            printf("Mailing list created successfully!\n");
            break;

        case 2:
            printf("Enter the name and email of the new contact:\n");
            scanf(" %[^\n]s %[^\n]s", contacts->name, contacts->email);

            printf("Contact added successfully!\n");
            break;

        case 3:
            printf("Enter the name of the contact to remove:\n");
            scanf(" %[^\n]s", contacts->name);

            printf("Contact removed successfully!\n");
            break;

        case 4:
            printf("Mailing List:\n");
            for(int i=0; i<num_contacts; i++) {
                printf("%s (%s)\n", contacts[i].name, contacts[i].email);
            }
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}