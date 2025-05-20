//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[12];
} surreal_contact;

void add_contact(surreal_contact *contacts, int *num_contacts) {
    printf("\nEnter the name of your contact: ");
    scanf("%s", contacts[*num_contacts].name);
    printf("Enter their phone number (in the format ###-###-####): ");
    scanf("%s", contacts[*num_contacts].number);
    printf("\nContact added!\n");
    (*num_contacts)++;
}

void view_contacts(surreal_contact *contacts, int num_contacts) {
    if (num_contacts == 0) {
        printf("\nSorry, you don't have any contacts yet.\n");
        return;
    }

    printf("\nYour contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("\nName: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    surreal_contact *contacts = NULL;
    int num_contacts = 0;
    char option;

    printf("Welcome to the Surrealist Phone Book!\n");

    while (1) {
        printf("\nWhat would you like to do?\n\n");
        printf("1. Add a contact\n");
        printf("2. View all contacts\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                add_contact(contacts, &num_contacts);
                contacts = (surreal_contact *) realloc(contacts, (num_contacts + 1) * sizeof(surreal_contact));
                break;
            case '2':
                view_contacts(contacts, num_contacts);
                break;
            case '3':
                printf("\nThank you for using the Surrealist Phone Book!\n");
                free(contacts);
                exit(0);
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}