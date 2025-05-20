//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

void add_contact(Contact* contacts, int count, char* name, char* number) {
    if (count >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(contacts[count].name, name);
    strcpy(contacts[count].number, number);

    printf("Contact added successfully!\n");
}

void search_contact(Contact* contacts, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found!\n");
}

void delete_contact(Contact* contacts, int* count, char* name) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].number, contacts[j + 1].number);
            }

            (*count)--;

            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
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

            add_contact(contacts, count, name, number);
            break;
        }
        case 2: {
            char name[MAX_NAME_LENGTH];

            printf("Enter name to search: ");
            scanf("%s", name);

            search_contact(contacts, count, name);
            break;
        }
        case 3: {
            char name[MAX_NAME_LENGTH];

            printf("Enter name to delete: ");
            scanf("%s", name);

            delete_contact(contacts, &count, name);
            break;
        }
        case 4:
            return 0;
        }
    }

    return 0;
}