//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char number[20];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numContacts = 0;

void addContact(const char* name, const char* number) {
    if (numContacts >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phoneBook[numContacts].name, name);
    strcpy(phoneBook[numContacts].number, number);
    numContacts++;
}

void searchContactByName(const char* name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    char command[10];
    char name[NAME_LENGTH];
    char number[20];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            addContact(name, number);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            searchContactByName(name);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}