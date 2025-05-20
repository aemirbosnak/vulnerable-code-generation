//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    char number[16];
} Contact;

Contact *phonebook;
int numContacts = 0;

void addContact(char *name, char *number) {
    if (numContacts == 0) {
        phonebook = malloc(sizeof(Contact));
    } else {
        phonebook = realloc(phonebook, sizeof(Contact) * (numContacts + 1));
    }
    strcpy(phonebook[numContacts].name, name);
    strcpy(phonebook[numContacts].number, number);
    numContacts++;
}

void printContacts() {
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

void searchContacts(char *name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found: %s (%s)\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Not found: %s\n", name);
}

void deleteContact(char *name) {
    int index = -1;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Not found: %s\n", name);
        return;
    }

    for (int i = index; i < numContacts - 1; i++) {
        phonebook[i] = phonebook[i + 1];
    }
    numContacts--;
    phonebook = realloc(phonebook, sizeof(Contact) * numContacts);
}

int main() {
    int choice;
    char name[32];
    char number[16];

    do {
        printf("\n1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact number: ");
                scanf("%s", number);
                addContact(name, number);
                break;
            case 2:
                printContacts();
                break;
            case 3:
                printf("Enter contact name to search: ");
                scanf("%s", name);
                searchContacts(name);
                break;
            case 4:
                printf("Enter contact name to delete: ");
                scanf("%s", name);
                deleteContact(name);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}