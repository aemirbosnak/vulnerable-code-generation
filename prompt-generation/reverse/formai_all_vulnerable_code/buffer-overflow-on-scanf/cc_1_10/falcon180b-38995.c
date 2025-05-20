//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Print all contacts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter number: ");
            scanf("%s", contacts[num_contacts].number);
            num_contacts++;
            break;
        case 2:
            printf("Enter name to search: ");
            char name_to_search[MAX_NAME_LENGTH];
            scanf("%s", name_to_search);

            int found = 0;
            for (int i = 0; i < num_contacts; i++) {
                if (strcmp(contacts[i].name, name_to_search) == 0) {
                    printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
                    found = 1;
                }
            }

            if (!found) {
                printf("Contact not found\n");
            }
            break;
        case 3:
            for (int i = 0; i < num_contacts; i++) {
                printf("Name: %s\nNumber: %s\n\n", contacts[i].name, contacts[i].number);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}