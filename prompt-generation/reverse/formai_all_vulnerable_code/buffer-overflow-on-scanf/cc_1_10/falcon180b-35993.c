//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CONTACTS 500
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

void add_contact(Contact* contacts, int num_contacts, char* name, char* number) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Error: Phone book is full.\n");
        return;
    }

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Error: Contact already exists.\n");
            return;
        }
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].number, number);
    num_contacts++;
}

void delete_contact(Contact* contacts, int num_contacts, char* name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            memmove(&contacts[i], &contacts[i+1], (num_contacts - i - 1) * sizeof(Contact));
            num_contacts--;
            return;
        }
    }

    printf("Error: Contact not found.\n");
}

void search_contact(Contact* contacts, int num_contacts, char* name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Error: Contact not found.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Delete contact\n3. Search contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                char number[MAX_NUMBER_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);

                add_contact(contacts, num_contacts, name, number);
                break;
            }
            case 2: {
                char name[MAX_NAME_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);

                delete_contact(contacts, num_contacts, name);
                break;
            }
            case 3: {
                char name[MAX_NAME_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);

                search_contact(contacts, num_contacts, name);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}