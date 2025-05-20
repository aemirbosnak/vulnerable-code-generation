//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: creative
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

void add_contact(Contact* contacts, int count, char* name, char* number) {
    if(count >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(contacts[count].name, name);
    strcpy(contacts[count].number, number);

    printf("Contact added successfully.\n");
}

void search_contact(Contact* contacts, int count, char* name) {
    int i;

    for(i = 0; i < count; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(Contact* contacts, int count, char* name) {
    int i;

    for(i = 0; i < count; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            memset(&contacts[i], 0, sizeof(Contact));
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    while(1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                char number[MAX_NUMBER_LENGTH];

                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);

                add_contact(contacts, count, name, number);
                break;
            }

            case 2: {
                char name[MAX_NAME_LENGTH];

                printf("Enter name: ");
                scanf("%s", name);

                search_contact(contacts, count, name);
                break;
            }

            case 3: {
                char name[MAX_NAME_LENGTH];

                printf("Enter name: ");
                scanf("%s", name);

                delete_contact(contacts, count, name);
                break;
            }

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}