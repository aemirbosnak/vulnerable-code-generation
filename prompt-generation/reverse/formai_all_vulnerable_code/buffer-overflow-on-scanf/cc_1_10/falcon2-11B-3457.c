//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_LEN];
    char number[MAX_LEN];
} Contact;

Contact contacts[MAX_ENTRIES];
int numContacts = 0;

void addContact(char *name, char *number) {
    Contact temp;
    strncpy(temp.name, name, MAX_LEN);
    strncpy(temp.number, number, MAX_LEN);

    if (numContacts < MAX_ENTRIES) {
        contacts[numContacts] = temp;
        numContacts++;
        printf("Contact added: %s - %s\n", temp.name, temp.number);
    } else {
        printf("Phone book is full!\n");
    }
}

void searchContact(char *name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }
    printf("Contact not found!\n");
}

void displayAllContacts() {
    for (int i = 0; i < numContacts; i++) {
        printf("Contact %d: %s - %s\n", i + 1, contacts[i].name, contacts[i].number);
    }
}

int main() {
    char name[MAX_LEN], number[MAX_LEN];
    char command;

    do {
        printf("Phone book menu:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &command);

        switch (command) {
            case '1':
                printf("Enter name: ");
                fgets(name, MAX_LEN, stdin);
                printf("Enter number: ");
                fgets(number, MAX_LEN, stdin);
                addContact(name, number);
                break;
            case '2':
                printf("Enter name to search: ");
                fgets(name, MAX_LEN, stdin);
                searchContact(name);
                break;
            case '3':
                displayAllContacts();
                break;
            case '4':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while (command!= '4');

    return 0;
}