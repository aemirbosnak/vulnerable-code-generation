//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    int num_contacts = 0;
    Contact contacts[100];

    char choice;
    do {
        printf("Phone Book\n");
        printf("=========\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter contact name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter contact number: ");
            scanf("%s", contacts[num_contacts].number);
            num_contacts++;
            break;
        case '2':
            printf("Enter contact name to search: ");
            char search_name[MAX_NAME_LENGTH];
            scanf("%s", search_name);
            for (int i = 0; i < num_contacts; i++) {
                if (strcmp(search_name, contacts[i].name) == 0) {
                    printf("Contact found:\n");
                    printf("Name: %s\n", contacts[i].name);
                    printf("Number: %s\n", contacts[i].number);
                }
            }
            break;
        case '3':
            for (int i = 0; i < num_contacts; i++) {
                printf("Contact %d:\n", i + 1);
                printf("Name: %s\n", contacts[i].name);
                printf("Number: %s\n", contacts[i].number);
            }
            break;
        case '4':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}