//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} contact_t;

int num_contacts = 0;
contact_t contacts[MAX_CONTACTS];

int add_contact(char* name, char* number) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book full.\n");
        return -1;
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].number, number);
    num_contacts++;
    return 0;
}

int search_contact(char* name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", name, contacts[i].number);
            return 0;
        }
    }
    printf("Contact not found.\n");
    return -1;
}

int main() {
    printf("Phone Book\n");
    while (1) {
        printf("\n1. Add contact\n2. Search contact\n3. Exit\n");
        char choice;
        scanf("%c", &choice);
        switch (choice) {
        case '1': {
            char name[MAX_NAME_LEN], number[MAX_NUMBER_LEN];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            add_contact(name, number);
            break;
        }
        case '2': {
            char name[MAX_NAME_LEN];
            printf("Enter name to search: ");
            scanf("%s", name);
            search_contact(name);
            break;
        }
        case '3':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}