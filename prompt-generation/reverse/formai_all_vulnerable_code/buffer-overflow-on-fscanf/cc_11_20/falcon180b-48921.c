//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
};

int main() {
    FILE *phonebook;
    int num_contacts = 0;
    struct contact contacts[MAX_CONTACTS];

    // Open the phone book file
    phonebook = fopen("phonebook.txt", "r");
    if (phonebook == NULL) {
        printf("Error: Could not open phone book file.\n");
        return 1;
    }

    // Read contacts from the file
    while (fscanf(phonebook, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].number) == 2) {
        num_contacts++;
        if (num_contacts >= MAX_CONTACTS) {
            printf("Error: Too many contacts in phone book.\n");
            return 1;
        }
    }
    fclose(phonebook);

    // Main menu loop
    char choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf(" %s", contacts[num_contacts].name);
            printf("Enter phone number: ");
            scanf(" %s", contacts[num_contacts].number);
            num_contacts++;
            break;

        case '2':
            printf("Enter name to delete: ");
            scanf(" %s", contacts[num_contacts - 1].name);
            num_contacts--;
            break;

        case '3':
            printf("Enter name to search: ");
            scanf(" %s", contacts[num_contacts - 1].name);
            break;

        case '4':
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    // Write updated contacts to file
    phonebook = fopen("phonebook.txt", "w");
    if (phonebook == NULL) {
        printf("Error: Could not open phone book file.\n");
        return 1;
    }

    for (int i = 0; i < num_contacts; i++) {
        fprintf(phonebook, "%s %s\n", contacts[i].name, contacts[i].number);
    }
    fclose(phonebook);

    return 0;
}