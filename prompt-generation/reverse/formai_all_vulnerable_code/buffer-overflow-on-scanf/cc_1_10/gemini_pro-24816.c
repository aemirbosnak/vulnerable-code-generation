//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[30];
    char number[20];
} Contact;

Contact contacts[MAX_CONTACTS];

int num_contacts = 0;

void add_contact() {
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter number: ");
    scanf("%s", contacts[num_contacts].number);

    num_contacts++;
}

void display_contacts() {
    if (num_contacts == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].number);
    }
}

void search_contact() {
    char name[30];

    printf("Enter name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
            return;
        }
    }

    printf("Contact not found!\n");
}

void delete_contact() {
    char name[30];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            num_contacts--;
            printf("Contact deleted!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}