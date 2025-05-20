//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;

    printf("Welcome to the Phonebook!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_contacts >= MAX_CONTACTS) {
                printf("Sorry, phonebook is full.\n");
            } else {
                printf("Enter name: ");
                scanf("%s", phonebook[num_contacts].name);
                printf("Enter number: ");
                scanf("%s", phonebook[num_contacts].number);
                num_contacts++;
                printf("Contact added successfully.\n");
            }
            break;

        case 2:
            printf("Enter name to search: ");
            char search_name[MAX_NAME_LENGTH];
            scanf("%s", search_name);

            int found = 0;
            for (int i = 0; i < num_contacts; i++) {
                if (strcmp(phonebook[i].name, search_name) == 0) {
                    printf("Name: %s\n", phonebook[i].name);
                    printf("Number: %s\n", phonebook[i].number);
                    found = 1;
                }
            }

            if (!found) {
                printf("Contact not found.\n");
            }
            break;

        case 3:
            printf("Phonebook:\n");
            for (int i = 0; i < num_contacts; i++) {
                printf("Name: %s\n", phonebook[i].name);
                printf("Number: %s\n", phonebook[i].number);
            }
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}